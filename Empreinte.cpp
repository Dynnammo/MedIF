/*************************************************************************
Empreinte  -  description
-------------------
début                : 01.06.2018
copyright            : (C) 2018 par Tifenn FLOCH
Anatolii GASIUK
Léo PAPE
Baptiste THIVEND
e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Empreinte> (fichier Empreinte.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "Empreinte.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type Empreinte::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------------ Getters - Setters
string Empreinte::getMesures() const
{
	return mesures;
}

//------------------------------------------------- Surcharge d'opérateurs
Empreinte & Empreinte::operator = (const Empreinte & uneEmpreinte)
{
	this->idEmpreinte = uneEmpreinte.idEmpreinte;
	return *this;
} //----- Fin de operator =


ostream & operator << (ostream & out, const Empreinte & e)
{
	//Affichage des attributs
	out << "idEmpreinte : " << e.idEmpreinte << " ; mesures : " << e.getMesures() << endl;
	return out;
} //----- Fin de operator <<

//-------------------------------------------- Constructeurs - destructeur
Empreinte::Empreinte(const Empreinte & unEmpreinte)
	:idEmpreinte(unEmpreinte.idEmpreinte)
{
	mesures = unEmpreinte.getMesures();
#ifdef MAP
	cout << "Appel au constructeur de copie de <Empreinte>" << endl;
#endif
} //----- Fin de Empreinte (constructeur de copie)

Empreinte::Empreinte(string m) 
	:mesures(m)
{
#ifdef MAP
	cout << "Appel au constructeur de <Empreinte>" << endl;
#endif
}

Empreinte::~Empreinte()
{
#ifdef MAP
	cout << "Appel au destructeur de <Empreinte>" << endl;
#endif
	} //----- Fin de ~Empreinte


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées

  //------------------------------------------------------- Méthodes privées

