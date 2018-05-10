/*************************************************************************
Attribut_intervalle  -  description
-------------------
d�but                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- R�alisation de la classe <Attribut_intervalle> (fichier Attribut_intervalle.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
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
//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
// type Attribut_intervalle::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

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
	flux << this->idAttribut << "   " << this->borneInf << " - " << this->borneSup << " ; " << this->moyenne << endl;
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

} //----- Fin de Attribut_intervalle

Attribut_intervalle::Attribut_intervalle(int id, double borneS, double borneI, double moy)
// Algorithme :
//
{
	this->borneSup = borneS;
	this->borneInf = borneI;
	this->moyenne = moy;
} //----- Fin de Attribut_intervalle

Attribut_intervalle::~Attribut_intervalle()
// Algorithme :
//
{

} //----- Fin de ~Attribut_intervalle


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- M�thodes prot�g�es

  //------------------------------------------------------- M�thodes priv�es

