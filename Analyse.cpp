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

void Analyse::analyseEmpreinte(Empreinte e, unordered_map <int, Maladie> mapMaladie)
// Algorithme :
//
{
	vector<string> symptomes = split(e.getMesures(), ";");

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
	out << " Maladie : " << "/t" << "Pourcentage : " << endl;
	unordered_map<string, double>::iterator it;
	for (it=maladies.begin();it!=maladies.end();++it)
	{
		out <<"  "<< it->first << "/t" << it->second << endl;
	}
	return out;
}

Analyse&  Analyse::operator =(const &Analyse a)
{
	this->idAnalyse = a.getId();
	unordered_map<string, double> maladies = a.getMaladiesPotentielles();
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
