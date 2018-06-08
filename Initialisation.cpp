/*************************************************************************
Initialisation  -  description
-------------------
début                : 27.04.2018
copyright            : (C) 2018 par Tifenn FLOCH
									Anatolii GASIUK
									Léo PAPE
									Baptiste THIVEND
e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Initialisation> (fichier Initialisation.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <string>
#include <regex>

//------------------------------------------------------ Include personnel
#include "Initialisation.h"

unordered_map<int, Maladie>& Initialisation::getListeMaladie()
{
	return mapMaladie;
} //----- Fin de Méthode getListeMaladie

Patient  Initialisation::getPatient(int id)
{
	Patient p;
	for (unsigned int i(0); i < this->listePatient.size();i++)
	{
		if (id == this->listePatient[i].getIdPersonne())
		{
			 return this->listePatient[i];
		}
	}
	return p;
} //----- Fin de Méthode getPatient

void  Initialisation::setPatient(Patient &p)
{
	if (p.getPrenom() == "" || p.getNom() == "" || p.getMail() == "" || p.getIdPersonne() == NULL)
	{
		cout << "Profil du Patient est incomplet." << endl;
		return;
	}
	this->listePatient.push_back(p);
} //----- Fin de Méthode setPatient

vector<Medecin> Initialisation::getListeMedecin()
{
	return this->listeMedecin;
} //----- Fin de Méthode getListeMedecin

vector<Patient> &Initialisation::getListePatient()
{
	return this->listePatient;
} //----- Fin de Méthode getListeMedecin

void Initialisation::init(string nomFichier)
// Algorithme :Lire le fichier - en lisant ligne par ligne, ajouter dans la map la maladie (clé) et ses empreintes (valeurs)
// Pour chaque maladie parcourir ses empreintes et calculer les attributs: intervalle+moyenne, p(X=Vrai), sequence string
// 
{
	int pos = nomFichier.find_last_of(".");
	if (pos==-1||nomFichier.substr(pos) != ".txt")
	{
		cout << "Erreur : format du fichier incorrecte." << endl;
		return;
	}

	string separateur = ";";
	unordered_map<string, vector<string>> tmp_map;
	ifstream lecture(nomFichier); //lecture du fichier
	string ligne;
	vector<string> nomAttributs;
	vector<int> typeAttributs;

	if (!lecture) // test de lecture
	{
		cout << "Erreur de lecture du fichier" << endl;
		return;		
	}

	if (getline(lecture, ligne))
			{
				nomAttributs = split(ligne, ";");
				nomAttributs.pop_back();
				nomAttributs.erase(nomAttributs.begin());
				if (nomAttributs.size() == 0)
				{
					cout << "Erreur : le fichier ne comporte pas de ligne d'attributs" << endl;
					return;
				}

			}
			else
			{
				cout << "Le fichier est vide." << endl;
				return;
			}
			mapMaladie.clear();
			int posLigne=lecture.tellg();
			getline(lecture, ligne);
			lecture.seekg(posLigne);

			vector<string> tmp_attributs;
			tmp_attributs = split(ligne, ";");
			if (ligne.size() != 0)
			{
				for (unsigned int l(1); l < tmp_attributs.size() - 1; l++)
				{
					if (tmp_attributs[l] == "False" || tmp_attributs[l] == "True")
					{
						typeAttributs.push_back(1);
					}
					else if (regex_match(tmp_attributs[l], regex{ "[+-]?[0-9]+(.[0-9]+)?" }))
					{
						typeAttributs.push_back(2);
					}
					else
					{
						typeAttributs.push_back(3);
					}
				}
			}
			else // fichier erroné
			{
				cout << "Erreur : Maladie sans attributs. Premier résultat éroné." << endl;
				return;
			}

			while (getline(lecture, ligne)) // initialisation de maladies et empreintes correspondantes dans une map
			{
				int position = ligne.find_last_of(separateur);
				int positionId = ligne.find(separateur);
				string maladie= ligne.substr(position + 1);
				if (maladie == "")
				{
					maladie = "sain"; // état correspondant à aucune maladie
				}
				if (ligne.size() != 0)
				{
					tmp_map[maladie].push_back(ligne.substr(positionId + 1, (position - 1 - positionId)));
				}
				else // pour eviter de creer des maladies sans attributs;
				{
					cout << "Attention : Maladie sans attributs ignorée."<<endl;
				}
			}

			lecture.close();
	unordered_map<string, vector<string>>::iterator it;
	int idMaladie(0);
	for (it = tmp_map.begin(); it != tmp_map.end(); ++it,idMaladie++) // debut de calcul des attributs dans la mapMaladie
	{
		
		int nbrEmpreinte = it->second.size();
		for (unsigned int i(0); i < it->second.size(); i++)
		{
			vector<string> symptomes = split(it->second[i], separateur); // symptomes d'empreinte
			for (unsigned int j(0); j < symptomes.size(); j++)
			{
				if (typeAttributs[j]==1) // test symptome Vrai/Faux attribut de type intervale 0(V) - 1(F)
				{
					if (mapMaladie[idMaladie].getListeAttribut().size()<=j)//test pour initialiser les attribut
					{
						int boolean = 1;
						if (symptomes[j] == "False")
						{
							boolean = 0;
						}
						Attribut_intervalle* symptome = new Attribut_intervalle(nomAttributs[j],j, 1, 0, boolean/ nbrEmpreinte);						
						mapMaladie[idMaladie].ajouterAttribut(symptome);
					}
					else // sinon recuprer et modifier les attributs existants
					{
						
						Attribut_intervalle* symptome = (Attribut_intervalle*)mapMaladie[idMaladie].getListeAttribut()[j];
						double moy = symptome->getMoyenne();
						if (symptomes[j] == "True")
						{
							moy+=1/ nbrEmpreinte;
							
						}
						symptome->setMoyenne(moy / nbrEmpreinte);
					}
				}

				else if (typeAttributs[j]==2) // test symptome numérique
				{

					double borne = atof(symptomes[j].c_str());

					if (mapMaladie[idMaladie].getListeAttribut().size()<=j) //cf commentaire symptome precedent
					{
						Attribut_intervalle* symptome = new Attribut_intervalle(nomAttributs[j],j, borne, borne, borne/ nbrEmpreinte);
						mapMaladie[idMaladie].ajouterAttribut(symptome);
						
					}
					else//cf commentaire symptome precedent
					{
						Attribut_intervalle* symptome = (Attribut_intervalle*)mapMaladie[idMaladie].getListeAttribut()[j];
						if (borne > symptome->getBorneSup())
						{
							symptome->setBorneSup(borne);
						}

						else if (borne < symptome->getBorneInf())
						{
							symptome->setBorneInf(borne);
						}
						double moyenne = symptome->getMoyenne() + borne/ nbrEmpreinte;

						symptome->setMoyenne(moyenne);

					}
					
				}

				else //sinon action pour symptome string
				{
					if (mapMaladie[idMaladie].getListeAttribut().size() <= j) //cf commentaire symptome precedent
					{
						vector<string> valeurs;
						valeurs.push_back(symptomes[j]);
						Attribut_enumeration* symptome = new Attribut_enumeration(nomAttributs[j],j, 1,valeurs );
						mapMaladie[idMaladie].ajouterAttribut(symptome);

					}
					else //cf commentaire symptome precedent
					{
						Attribut_enumeration* symptome = (Attribut_enumeration*)mapMaladie[idMaladie].getListeAttribut()[j];
						vector<string> tmp_Symptomes = symptome->getValeurs();
						if (find(tmp_Symptomes.begin(), tmp_Symptomes.end(), symptomes[j]) == tmp_Symptomes.end())
						{
							symptome->setValeur(symptomes[j]);
						}
						symptome->setNbValeurs(tmp_Symptomes.size());
					}
				}
			}
		}
		mapMaladie[idMaladie].setNom(it->first);
		mapMaladie[idMaladie].setId(idMaladie);
	}
} //----- Fin de Méthode init

vector<string> Initialisation::split(string lignef, string del)
{
	vector<string> reponse;
	int pos = 0;
	while (pos != -1)
	{
		pos = lignef.find(del);
		if (del.size() != lignef.size())
		{

			if (pos != 0)
			{
				reponse.push_back(lignef.substr(0, pos));

			}
			if (pos != (int)lignef.size() - 1 && pos != -1)
			{
				lignef.erase(0, pos + del.size());
			}
			else if (pos != -1)
			{
				lignef.erase(pos, pos + del.size());
				break;
			}
		}
		else
		{
			pos = -1;
			reponse.push_back(lignef);
		}

	}
	return reponse;
} //----- Fin de Méthode split

void Initialisation::initMedecin(string nomFichier)
//Algo: initier la liste de medecin qui peuvent se connecter à partir d'un fichier

//
{
	string separateur = ";";
	ifstream lecture(nomFichier);
	string ligne;
	if (lecture)
	{
		while (getline(lecture, ligne))
		{
			vector<string> parametres = split(ligne, ";");
			Medecin m( parametres[0], parametres[1], parametres[2], parametres[3]);
			listeMedecin.push_back(m);
		}
		lecture.close();
	}
	else
	{
		cout << "Erreur de lecture du fichier log Medecin." << endl;
	}
}//----- Fin de Méthode initMedecin


//------------------------------------------------- Surcharge d'opérateurs
Initialisation & Initialisation::operator = ( const Initialisation & unInitialisation )
// Algorithme :
//
{
	this->listeMedecin = unInitialisation.listeMedecin;
	this->listePatient = unInitialisation.listePatient;
	this->mapMaladie = unInitialisation.mapMaladie;
	return *this;
} //----- Fin de operator =

void Initialisation::afficherMedecin(){
	for(unsigned int i = 0; i < listeMedecin.size() ; i++)
	{
		cout << listeMedecin[i];
	}	
}

void Initialisation::afficherPatient(){
	for(unsigned int i = 0; i < listePatient.size() ; i++)
	{
		Patient p = listePatient[i];
		cout << p.getNom() << " " << p.getPrenom() <<endl;
		cout  << "ID = " <<p.getIdPersonne() << endl;
	}	
}

//-------------------------------------------- Constructeurs - destructeur
Initialisation::Initialisation ( const Initialisation &i )
	:listeMedecin(i.listeMedecin),listePatient(i.listePatient),mapMaladie(i.mapMaladie)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Initialisation>" << endl;
#endif
} //----- Fin de Initialisation (constructeur de copie)


Initialisation::Initialisation ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Initialisation>" << endl;
#endif
} //----- Fin de Initialisation


Initialisation::~Initialisation ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Initialisation>" << endl;
#endif
} //----- Fin de ~Initialisation
