/*************************************************************************
Maladie  -  description
-------------------
début                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Maladie> (fichier Maladie.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <vector>
//------------------------------------------------------ Include personnel
#include "Maladie.h"
#include "Attribut.h"
#include "Attribut_enumeration.h"
#include "Attribut_intervalle.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe
int idMaladie;
vector<Attribut> listeAttribut;
//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
ostream& operator<<(ostream &flux, Maladie const& maladie)
// Algorithme :
//
{
	cout<<
} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Maladie & Maladie::operator = (const Maladie & unMaladie)
// Algorithme :
//
{
} //----- Fin de operator =


  //-------------------------------------------- Constructeurs - destructeur
Maladie::Maladie(const Maladie & unMaladie)
// Algorithme :
//
{

} //----- Fin de Maladie (constructeur de copie)


Maladie::Maladie()
// Algorithme :
//
{
} //----- Fin de Maladie

Maladie::Maladie(int id)
// Algorithme :
//
{
	idMaladie = id;

} //----- Fin de Maladie


Maladie::~Maladie()
// Algorithme :
//
{

} //----- Fin de ~Maladie


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées

  //------------------------------------------------------- Méthodes privées

