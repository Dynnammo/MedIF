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
#include "Maladie.h"
#include "medecin.h"
#include "patient.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type Initialisation::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

unordered_map<int, Maladie>& Initialisation::getListeMaladie()
// type ${file_base}::Méthode ( liste de paramètres )
// Algorithme :
//
{
	return mapMaladie;
} //----- Fin de Méthode

Patient  Initialisation::getPatient(int id)
// type ${file_base}::Méthode ( liste de paramètres )
// Algorithme :
//
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
} //----- Fin de Méthode

void  Initialisation::setPatient(Patient p)
// type ${file_base}::Méthode ( liste de paramètres )
// Algorithme :
//
{
	this->listePatient.push_back(p);
} //----- Fin de Méthode

vector<Medecin> Initialisation::getListeMedecin()
// type ${file_base}::Méthode ( liste de paramètres )
// Algorithme :
//
{
	return this->listeMedecin;
} //----- Fin de Méthode

void Initialisation::init(string nomFichier)
// Algorithme :Lire le fichier - en lisant ligne par ligne, ajouter dans la map la maladie (clé) et ses empreintes (valeurs)
// Pour chaque maladie parcourir ses empreintes et calculer les attributs: intervalle+moyenne, p(X=Vrai), sequence string
// 
{
	string separateur = ";";
	unordered_map<string, vector<string>> tmp_map;
	ifstream lecture(nomFichier); //lecture du fichier
	string ligne;
	if (lecture) // test de lecture
	{
		if (!getline(lecture, ligne))
		{
			cout << "Le fichier est vide." << endl;
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
			
			tmp_map[maladie].push_back(ligne.substr(positionId+1, (position-1-positionId)));
		}
		lecture.close();
	}
	else
	{
		cout << "Erreur de lecture du fichier" << endl;
	}
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
				if (symptomes[j] == "F" || symptomes[j] == "V") // test symptome Vrai/Faux attribut de type intervale 0(V) - 1(F)
				{
					if (mapMaladie[idMaladie].getListeAttribut().size()<=j)//test pour initialiser les attribut
					{
						if (symptomes[j] == "F")
						{
							Attribut_intervalle* symptome = new Attribut_intervalle(j,1,0,0);
							mapMaladie[idMaladie].ajouterAttribut(symptome);

						}
						else 
						{
							Attribut_intervalle* symptome = new Attribut_intervalle(j, 1, 0, 1/ nbrEmpreinte);
							mapMaladie[idMaladie].ajouterAttribut(symptome);
						}
					}
					else // sinon recuprer et modifier les attributs existants
					{
						
						Attribut_intervalle* symptome = (Attribut_intervalle*)mapMaladie[idMaladie].getListeAttribut()[j];
						double moy = symptome->getMoyenne();
						if (symptomes[j] == "V")
						{
							moy+=1/ nbrEmpreinte;
							
						}
						symptome->setMoyenne(moy / nbrEmpreinte);
					}
				}

				else if (regex_match(symptomes[j],regex{ "[+-]?[0-9]+(.[0-9]+)?" })) // test symptome numérique
				{

					double borne = atof(symptomes[j].c_str());

					if (mapMaladie[idMaladie].getListeAttribut().size()<=j) //cf commentaire symptome precedent
					{
						Attribut_intervalle* symptome = new Attribut_intervalle(j, borne, borne, borne/ nbrEmpreinte);
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
						Attribut_enumeration* symptome = new Attribut_enumeration(j, 1,valeurs );
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
} //----- Fin de Méthode

vector<string> Initialisation::split(string &lignef, string del)
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
			if (pos != lignef.size() - 1 && pos != -1)
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

}

void Initialisation::initMedesin(string nomFichier)
//Algo: initier la liste de medecin qui peuvent se connecteà partir d'un fichier
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
	}
	else
	{
		cout << "Erreur de lecture du fichier log Medecin." << endl;
	}
}


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


//-------------------------------------------- Constructeurs - destructeur
Initialisation::Initialisation ( const Initialisation & unInitialisation )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Initialisation>" << endl;
#endif
} //----- Fin de Initialisation (constructeur de copie)


Initialisation::Initialisation ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Initialisation>" << endl;
#endif
} //----- Fin de Initialisation


Initialisation::~Initialisation ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Initialisation>" << endl;
#endif
} //----- Fin de ~Initialisation


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

