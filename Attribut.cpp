/*************************************************************************
Attribut  -  description
-------------------
d�but                : 27.04.2018
copyright            : (C) 2018 par Tifenn FLOCH 
									Anatolii GASIUK
									L�o PAPE
									Baptiste THIVEND
e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- R�alisation de la classe <Attribut> (fichier Attribut.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "Attribut.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
// type Attribut::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

bool Attribut::verification(string valeur)
{
	return true;
}

bool Attribut::verification(double valeur)
{
	return true;
}

//------------------------------------------------------ Getters - Setters
int Attribut::getIdAttribut()
{
	return this->idAttribut;
}

//------------------------------------------------- Surcharge d'op�rateurs
Attribut & Attribut::operator = (const Attribut & unAttribut)
// Algorithme :
//
{
	this->idAttribut = unAttribut.idAttribut;
	return *this;
} //----- Fin de operator =

ostream& Attribut::afficher(ostream &flux)
// Algorithme :
//
{
	flux <<"Attribut : "<< this->nomAttribut << "  " << " - " << endl;
	return flux;
} //----- Fin de operator <<

  //-------------------------------------------- Constructeurs - destructeur
Attribut::Attribut(const Attribut & a)
	:idAttribut(a.idAttribut),nomAttribut(a.nomAttribut)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Attribut>" << endl;
#endif
} //----- Fin de Attribut (constructeur de copie)


Attribut::Attribut()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur par d�faut de <Attribut>" << endl;
#endif
} //----- Fin de Attribut

Attribut::Attribut(int id, string nom)
// Algorithme :
//
{
	this->idAttribut = id;
	this->nomAttribut = nom;
#ifdef MAP
    cout << "Appel au constructeur de <Attribut>" << endl;
#endif
} //----- Fin de Attribut


Attribut::~Attribut()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Attribut>" << endl;
#endif
} //----- Fin de ~Attribut


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- M�thodes prot�g�es

  //------------------------------------------------------- M�thodes priv�es

