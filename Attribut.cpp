/*************************************************************************
Attribut  -  description
-------------------
d�but                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- R�alisation de la classe <Attribut> (fichier Attribut.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

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
	flux << this->idAttribut << "  " << " - " << endl;
	return flux;
} //----- Fin de operator <<

  //-------------------------------------------- Constructeurs - destructeur
Attribut::Attribut(const Attribut & unAttribut)
// Algorithme :
//
{

} //----- Fin de Attribut (constructeur de copie)


Attribut::Attribut()
// Algorithme :
//
{

} //----- Fin de Attribut

Attribut::Attribut(int id)
// Algorithme :
//
{
	this->idAttribut = id;
} //----- Fin de Attribut


Attribut::~Attribut()
// Algorithme :
//
{

} //----- Fin de ~Attribut


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- M�thodes prot�g�es

  //------------------------------------------------------- M�thodes priv�es

