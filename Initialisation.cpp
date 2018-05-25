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
vector<Maladie> listeMaladie;
vector<Medecin> listeMedecin;
vector<Patient> listePatient;
unordered_map <int, Maladie> mapMaladie;
//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type Initialisation::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Initialisation::init(string nomFichier)
// Algorithme :
//
{
	string separateur = ";";
	unordered_map<string, vector<string>> tmp_map;
	ifstream lecture(nomFichier);
	string ligne;
	if (lecture)
	{
		while (getline(lecture, ligne))
		{
			int position = ligne.find_last_of(separateur);
			tmp_map[ligne.substr(position+1, ligne.size())].push_back(ligne.substr(0, position));
		}
		lecture.close();
	}
	else
	{
		cout << "Erreur de lecture du fichier" << endl;
	}
	unordered_map<string, vector<string>>::iterator it;
	int idMaladie(0);
	for (it = tmp_map.begin(); it != tmp_map.end(); ++it,idMaladie++)
	{
		int nbrEmpreinte = it->second.size();
		for (unsigned int i(0); i < it->second.size(); i++)
		{

			vector<string> symptomes = split(it->second[i], separateur);
			for (unsigned int j(0); j < symptomes.size(); j++)
			{
				if (symptomes[j] == "F" || symptomes[j] == "V")
				{
					if (mapMaladie[idMaladie].getListeAttribut().size()<=j)
					{
						if (symptomes[j] == "F")
						{
							Attribut_intervalle* symptome = new Attribut_intervalle(j,1,0,0);
							mapMaladie[idMaladie].ajouterAttribut(symptome);

						}
						else 
						{
							Attribut_intervalle* symptome = new Attribut_intervalle(j, 1, 0, 1);
							mapMaladie[idMaladie].ajouterAttribut(symptome);
						}
					}
					else
					{
						
						Attribut_intervalle* symptome = (Attribut_intervalle*)mapMaladie[idMaladie].getListeAttribut()[j];
						double moy = symptome->getMoyenne();
						if (symptomes[j] == "V")
						{
							moy+=1;
							
						}
						symptome->setMoyenne(moy / nbrEmpreinte);
					}
				}

				else if (regex_match(symptomes[j],regex{ "[+-]?[0-9]+(.[0-9]+)?" }))
				{

					double borne = atof(symptomes[j].c_str());

					if (mapMaladie[idMaladie].getListeAttribut().size()<=j)
					{
						Attribut_intervalle* symptome = new Attribut_intervalle(j, borne, borne, borne);
						mapMaladie[idMaladie].ajouterAttribut(symptome);
						
					}
					else
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
						double moyenne = symptome->getMoyenne() + borne;

						symptome->setMoyenne(moyenne / nbrEmpreinte);

					}
					
				}

				else
				{
					if (mapMaladie[idMaladie].getListeAttribut().size() <= j)
					{
						vector<string> valeurs;
						valeurs.push_back(symptomes[j]);
						Attribut_enumeration* symptome = new Attribut_enumeration(j, 1,valeurs );
						mapMaladie[idMaladie].ajouterAttribut(symptome);

					}
					else
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


//------------------------------------------------- Surcharge d'opérateurs
Initialisation & Initialisation::operator = ( const Initialisation & unInitialisation )
// Algorithme :
//
{
	this->listeMaladie=unInitialisation.listeMaladie;
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

