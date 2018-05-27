/*************************************************************************
Attribut_intervalle  -  description
-------------------
début                : 27.04.2018
copyright            : (C) 2018 par Tifenn FLOCH
									Anatolii GASIUK
									Léo PAPE
									Baptiste THIVEND
e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Attribut_intervalle> (fichier Attribut_intervalle.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Attribut_intervalle.h"
#include "Attribut.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe
double borneSup;
double borneInf;
double moyenne;
//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type Attribut_intervalle::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool Attribut_intervalle :: verification(double valeur)
{
	if (valeur<borneSup && valeur>borneInf)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//------------------------------------------------------ Getters - Setters
double Attribut_intervalle::getBorneSup()
{
	return this->borneSup;
}

double Attribut_intervalle::getBorneInf()
{
	return this->borneInf;
}

double Attribut_intervalle::getMoyenne()
{
	return this->moyenne;
}

int Attribut_intervalle::getIdAttribut()
{
	return this->idAttribut;
}

void Attribut_intervalle::setBorneSup(double sup)
{
	this->borneSup = sup;
}

void Attribut_intervalle::setBorneInf(double inf)
{
	this->borneInf = inf;
}

void Attribut_intervalle::setMoyenne(double moy)
{
	this->moyenne = moy;
}

//------------------------------------------------- Surcharge d'opérateurs
Attribut_intervalle & Attribut_intervalle::operator = (const Attribut_intervalle & unAttribut_intervalle)
// Algorithme :
//
{

	this->borneInf = unAttribut_intervalle.borneInf;
	this->borneSup = unAttribut_intervalle.borneSup;
	this->moyenne = unAttribut_intervalle.moyenne;
	this->idAttribut = unAttribut_intervalle.idAttribut;
	return *this;
} //----- Fin de operator =

ostream& Attribut_intervalle::afficher (ostream &flux)
// Algorithme :
//
{
	flux << "idAttribut : " << this->idAttribut ;
	if (this->borneInf == 0 && this->borneSup == 1)
	{
		flux << " \t  " << "positif : "<< this->moyenne << endl;
	}
	else
	{
		flux << " \t  " << "intervalles : "<<this->borneInf << " - " << this->borneSup << " ; \t Moyenne : " << this->moyenne << endl;
	}

	
	return flux;
} //----- Fin de operator <<

  //-------------------------------------------- Constructeurs - destructeur
Attribut_intervalle::Attribut_intervalle(const Attribut_intervalle & unAttribut_intervalle)
// Algorithme :
//
{

} //----- Fin de Attribut_intervalle (constructeur de copie)


Attribut_intervalle::Attribut_intervalle()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Attribut_intervalle>" << endl;
#endif
} //----- Fin de Attribut_intervalle

Attribut_intervalle::Attribut_intervalle(int id, double borneS, double borneI, double moy)
// Algorithme :
//
{
	this->idAttribut = id;
	this->borneSup = borneS;
	this->borneInf = borneI;
	this->moyenne = moy;
#ifdef MAP
    cout << "Appel au constructeur de <Attribut_intervalle>" << endl;
#endif
} //----- Fin de Attribut_intervalle

Attribut_intervalle::~Attribut_intervalle()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Attribut_intervalle>" << endl;
#endif
} //----- Fin de ~Attribut_intervalle


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées

  //------------------------------------------------------- Méthodes privées

