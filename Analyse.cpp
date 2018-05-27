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
using namespace std;

//------------------------------------------------------ Include personnel
#include "Analyse.h"
#include "Maladie.h"
#include "Empreinte.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

vector<string> Analyse::split(string &lignef, string del)
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

void Analyse::analyseEmpreinte(Empreinte e, unordered_map <int, Maladie> &mapMaladie)
// Algorithme :
//
{
	vector<string> symptomes = split(e.getMesures(), ";");
	
	unordered_map <int, Maladie> temp;
	unordered_map <int, Maladie>::iterator it;

	for (it = mapMaladie.begin(); it != mapMaladie.end(); ++it)
	{
		temp[it->first]=it->second;
	}

	for (unsigned int j(0); j < symptomes.size(); j++)
	{
		
		for (it = temp.begin(); it != temp.end(); ++it)
		{
			if (j > it->second.getListeAttribut().size())
			{
				break;
			}

			Attribut* attribut = it->second.getListeAttribut()[j];
			if (regex_match(symptomes[j], regex{ "[+-]?[0-9]+(.[0-9]+)?" }))
			{
				double valeurSymptome = atof(symptomes[j].c_str());

				if (!attribut->verification(valeurSymptome))
				{
					it->second = NULL;
					it=temp.erase(it);
					--it;
				}
				

			}

			else if (symptomes[j] != "F" && symptomes[j] != "V")
			{

				if (!attribut->verification(symptomes[j]))
				{
					it->second = NULL;
					it = temp.erase(it);
					--it;
				}
			}
				
		}
	}
	for (it = temp.begin(); it != temp.end(); ++it)
	{
		double probabilite = 0;
		vector<Attribut*> attribut = it->second.getListeAttribut();
		int nbrAttribut = it->second.getListeAttribut().size();
		for (int i(0); i < nbrAttribut; i++)
		{
			if (regex_match(symptomes[i], regex{ "[+-]?[0-9]+(.[0-9]+)?" }))
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
		maladiesPotentielles[it->second.getNom()] = probabilite;
		it->second = NULL;
	}



} //----- Fin de Méthode

//------------------------------------------------------ Getters - Setters

unordered_map<string, double> Analyse::getMaladiesPotentielles()
// type Analyse::Méthode ( liste des paramètres )
// Algorithme :
//
{
	return this->maladiesPotentielles;
}

int Analyse::getId()
// type Analyse::Méthode ( liste des paramètres )
// Algorithme :
//
{
	return this->idAnalyse;
}

//------------------------------------------------- Surcharge d'opérateurs
ostream & operator << (ostream & out, Analyse & a)
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
