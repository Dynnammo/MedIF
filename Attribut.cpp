/*************************************************************************
Attribut  -  description
-------------------
début                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Attribut> (fichier Attribut.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Attribut.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type Attribut::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
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

  //----------------------------------------------------- Méthodes protégées

  //------------------------------------------------------- Méthodes privées

