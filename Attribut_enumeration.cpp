/*************************************************************************
Attribut_enumeration  -  description
-------------------
début                : 27.04.2018
copyright            : (C) 2018 par Tifenn FLOCH
									Anatolii GASIUK
									Léo PAPE
									Baptiste THIVEND
e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Attribut_enumeration> (fichier Attribut_enumeration.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>
#include <string>
#include <vector>

//------------------------------------------------------ Include personnel
#include "Attribut_enumeration.h"
#include "Attribut.h"
using namespace std;
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe
int nbValeurs;
vector <std::string> valeurs;
//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type Attribut_enumeration::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool Attribut_enumeration::verification(string valeur)
{
	if (find(valeurs.begin(), valeurs.end(), valeur)!=valeurs.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

//------------------------------------------------------ Getters - Setters
int Attribut_enumeration::getIdAttribut()
{
	return this->idAttribut;
}

int Attribut_enumeration::getNbValeurs()
{
	return this->nbValeurs;
}

vector<string> Attribut_enumeration::getValeurs()
{
	return this->valeurs;
}

void Attribut_enumeration::setNbValeurs(int nb)
{
	this->nbValeurs = nb;
}

void Attribut_enumeration::setValeur(string val)
{
	this->valeurs.push_back(val);
}
//------------------------------------------------- Surcharge d'opérateurs
Attribut_enumeration & Attribut_enumeration::operator = (const Attribut_enumeration & unAttribut_enumeration)
// Algorithme :
//
{
	this->idAttribut = unAttribut_enumeration.idAttribut;
	this->nbValeurs = unAttribut_enumeration.nbValeurs;
	this->valeurs = unAttribut_enumeration.valeurs;
	return *this;
} //----- Fin de operator =

ostream& Attribut_enumeration::afficher(ostream &flux)
// Algorithme :
//
{
	flux << "Attribut : " << this->nomAttribut << " \t " << "valeurs" << endl;
	for (unsigned int i(0); i < this->valeurs.size(); i++)
	{
		flux << "---------------" << " \t  " << this->valeurs[i] << endl;
	}
	return flux;
} //----- Fin de operator <<

  //-------------------------------------------- Constructeurs - destructeur
Attribut_enumeration::Attribut_enumeration(const Attribut_enumeration & unAttribut_enumeration)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Attribut_enumeration>" << endl;
#endif
} //----- Fin de Attribut_enumeration (constructeur de copie)


Attribut_enumeration::Attribut_enumeration()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Attribut_enumeration>" << endl;
#endif
} //----- Fin de Attribut_enumeration

Attribut_enumeration::Attribut_enumeration(string nom, int id,int nbValeurs, vector<string> valeurs)
// Algorithme :
//
{
	this->idAttribut = id;
	this->nomAttribut = nom;
	this->nbValeurs = nbValeurs;
	this->valeurs = valeurs;
#ifdef MAP
    cout << "Appel au constructeur de copie <Attribut_enumeration>" << endl;
#endif
} //----- Fin de Attribut_enumeration

Attribut_enumeration::~Attribut_enumeration()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Attribut_enumeration>" << endl;
#endif
} //----- Fin de ~Attribut_enumeration


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées

  //------------------------------------------------------- Méthodes privées

