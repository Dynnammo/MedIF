/*************************************************************************
Attribut_intervalle  -  description
-------------------
d�but                : 27.04.2018
copyright            : (C) 2018 par Tifenn FLOCH
									Anatolii GASIUK
									L�o PAPE
									Baptiste THIVEND
e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- R�alisation de la classe <Attribut_intervalle> (fichier Attribut_intervalle.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Attribut_intervalle.h"
#include "Attribut.h"
#include <string>

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe
double borneSup;
double borneInf;
double moyenne;
//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
// type Attribut_intervalle::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

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

//------------------------------------------------- Surcharge d'op�rateurs
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
	flux << "Attribut : " << this->nomAttribut ;
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
 //----- Fin de Attribut_intervalle (constructeur de copie)


Attribut_intervalle::Attribut_intervalle(const Attribut_intervalle &a)
	:borneInf(a.borneInf),borneSup(a.borneSup),moyenne(a.moyenne), Attribut(a.idAttribut,a.nomAttribut)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Attribut_intervalle>" << endl;
#endif
} //----- Fin de Attribut_intervalle

Attribut_intervalle::Attribut_intervalle(string nom, int id, double borneS, double borneI, double moy)
// Algorithme :
//
{
	this->nomAttribut = nom;
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

  //----------------------------------------------------- M�thodes prot�g�es

  //------------------------------------------------------- M�thodes priv�es

