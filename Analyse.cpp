/*************************************************************************
Analyse  -  description
-------------------
début                : 27.04.2018
copyright            : (C) 2018 par Tifenn FLOCH
									Anatolii GASIUK
									Léo PAPE
									Baptiste THIVEND
e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Analyse> (fichier Analyse.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <regex>
#include <string>
#include <sstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Analyse.h"
#include "Maladie.h"
#include "Empreinte.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Analyse::analyseEmpreinte(Empreinte e, unordered_map <int, Maladie> &mapMaladie)
// Algorithme : Créer une map temporaire avec les maladies
//pour chaque symptome descriminant (intervalle ou sequence string) parcourir la map et exclure les maladies 
//avec les maladies restante faire un calcule de probabilité de la maladie
{
	vector<string> symptomes;
	// on recupères les symptomes de l'empreinte
	for (istringstream iss(e.getMesures());;) 
	{
		string item; 
		getline(iss, item, ';');
		if (iss.fail()) break;
		symptomes.push_back(item);
	}// on recupères les symptomes de l'empreinte en split sur ';'
	
	unordered_map <int, Maladie> temp; //map temporaire des maladies
	unordered_map <int, Maladie>::iterator it;

	for (it = mapMaladie.begin(); it != mapMaladie.end(); ++it)
	{
		temp[it->first]=it->second; //copie de la map en parametre
	}

	for (unsigned int j(0); j < symptomes.size(); j++)
	{
		
		for (it = temp.begin(); it != temp.end(); )
		{
			if (j > it->second.getListeAttribut().size()) //pour chaque maladie on teste s'il y a pas plus de symptomes
														 //que des attributs dans la maladie tester, si oui on break
														 //cas possible si le capteur sera amelioré avec l'ajout d'attributs
			{
				break;
			}

			Attribut* attribut = it->second.getListeAttribut()[j];
			if (regex_match(symptomes[j], regex{ "[+-]?[0-9]+(.[0-9]+)?" }))// on test si le symptome numérique est dans l'intervalle définit
			{
				double valeurSymptome = atof(symptomes[j].c_str());

				if (!attribut->verification(valeurSymptome))//si c'est le cas, on supprime la maladie de la table sans supprimé le 
															// vector des pointeurs d'attributs
				{
					it->second = NULL;
					it=temp.erase(it);
				}
				else
				{
					++it;
				}
				

			}

			else if (symptomes[j] != "F" && symptomes[j] != "V")//on test si le symptome c'est un string
			{

				if (!attribut->verification(symptomes[j]))//cf commentaire au dessus
				{
					it->second = NULL;
					it = temp.erase(it);
				}
				else
				{
					++it;
				}
			}
				
		}
	}
	if (temp.begin() == temp.end())
	{
		cout << "L'analyse n'a pas donné de resultat." << endl;
		cout << "Veuillez faire des testes supplémentaires" << endl;
	}

	for (it = temp.begin(); it != temp.end(); ++it)//on parcourt les maladies restantes
													// details:: ajouter une condition si pas de maladies
	{
		double probabilite = 0;
		vector<Attribut*> attribut = it->second.getListeAttribut();
		int nbrAttribut = it->second.getListeAttribut().size();
		for (int i(0); i < nbrAttribut; i++)// chaque attribut de la maladie
		{
			if (regex_match(symptomes[i], regex{ "[+-]?[0-9]+(.[0-9]+)?" }))// comparaison avec symptome associé
			{
				double valeurSymptome = atof(symptomes[i].c_str());
				Attribut_intervalle *ai = (Attribut_intervalle*)(attribut[i]);
				if (valeurSymptome < ai->getMoyenne())
				{
					probabilite += (valeurSymptome-ai->getBorneInf()) / ((ai->getMoyenne() - ai->getBorneInf())*nbrAttribut);
				}
				else
				{
					probabilite += (ai->getBorneSup()-valeurSymptome) / ((ai->getBorneSup()-ai->getMoyenne())*nbrAttribut);
				}

			}

			else if (symptomes[i] == "F" || symptomes[i] == "V")
			{
				Attribut_intervalle *ai = (Attribut_intervalle*)(attribut[i]);
				if (ai->getMoyenne() == 0)
				{
					probabilite += 1 / nbrAttribut;
				}
				else
				{
					probabilite += ai->getMoyenne() / nbrAttribut;
				}
			}
			else
			{
				probabilite += 1.0 / nbrAttribut;
			}
		}
		if (temp.size() == 1 || probabilite > 0.20)
		{
			maladiesPotentielles[it->second.getNom()] = probabilite; // conditions pour un pourcentage minimal
			it->second = NULL;
		}
	}



} //----- Fin de Méthode analyseEmpreinte

//------------------------------------------------------ Getters - Setters

unordered_map<string, double> Analyse::getMaladiesPotentielles() const
{
	return this->maladiesPotentielles;
}

int Analyse::getId()
{
	return this->idAnalyse;
}

//------------------------------------------------- Surcharge d'opérateurs
ostream & operator << (ostream & out, const Analyse & a)
{
	unordered_map<string, double> maladies = a.getMaladiesPotentielles();
    out <<" Id : "<< a.idAnalyse << endl; 
	out << " Maladie : " << "\t" << "Pourcentage : " << endl;
	unordered_map<string, double>::iterator it;
	for (it=maladies.begin();it!=maladies.end();++it)
	{
		out <<"---------  "<< it->first << "\t-----------  " << it->second << endl;
	}
	return out;
}

Analyse&  Analyse::operator =(Analyse const &a)
{
	this->idAnalyse = a.idAnalyse;
	unordered_map<string, double> maladies = a.maladiesPotentielles;
	unordered_map<string, double>::iterator it;
	for (it=maladies.begin(); it != maladies.end(); ++it)
	{
		this->maladiesPotentielles[it->first] = it->second;
	}
	return *this;
}
//-------------------------------------------- Constructeurs - destructeur
/*Analyse::Analyse()
{
    idAnalyse = id++;
    pourcentage = 0;
}*/

Analyse::Analyse ( const Analyse & unAnalyse )
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Analyse>" << endl;
#endif
} //----- Fin de Analyse (constructeur de copie)


Analyse::Analyse ( )
{
    idAnalyse = idA++;
#ifdef MAP
    cout << "Appel au constructeur (par défaut) de <Analyse>" << endl;
#endif
} //----- Fin de Analyse


Analyse::~Analyse ( )
// Algorithme :
//
{
    idA--;
#ifdef MAP
    cout << "Appel au destructeur de <Analyse>" << endl;
#endif
} //----- Fin de ~Analyse


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
