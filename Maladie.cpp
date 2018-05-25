/*************************************************************************
Maladie  -  description
-------------------
début                : 27.04.2018
copyright            : (C) 2018 par Tifenn FLOCH
									Anatolii GASIUK
									Léo PAPE
									Baptiste THIVEND
e-mail               : @insa-lyon.fr
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
vector<Attribut*> listeAttribut;
//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void Maladie::ajouterAttribut(Attribut* attribut)
{
	this->listeAttribut.push_back(attribut);
}

//------------------------------------------------------ Getters - Setters
int Maladie::getIdMaladie()
{
	return this->idMaladie;
}

vector<Attribut*> Maladie::getListeAttribut()
{
	return this->listeAttribut;
}

//------------------------------------------------- Surcharge d'opérateurs
Maladie & Maladie::operator = (const Maladie & unMaladie)
// Algorithme :
//
{
	this->idMaladie = unMaladie.idMaladie;
	this->listeAttribut = unMaladie.listeAttribut;
	return *this;
} //----- Fin de operator =

ostream& operator<<(ostream &flux, Maladie const& maladie)
// Algorithme :
//
{
	flux << "id    " << "   valeur" << endl;
	for (unsigned int i(0); i < maladie.listeAttribut.size(); i++)
	{
		maladie.listeAttribut[i]->afficher(flux);

	}
	return flux;
} //----- Fin de Méthode

  //-------------------------------------------- Constructeurs - destructeur
Maladie::Maladie(const Maladie & unMaladie)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Maladie>" << endl;
#endif
} //----- Fin de Maladie (constructeur de copie)


Maladie::Maladie()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur par défaut de <Maladie>" << endl;
#endif
} //----- Fin de Maladie

Maladie::Maladie(int id)
// Algorithme :
//
{
	idMaladie = id;
#ifdef MAP
    cout << "Appel au constructeur de <Maladie>" << endl;
#endif
} //----- Fin de Maladie


Maladie::~Maladie()
// Algorithme :
//
{
	for (std::vector< Attribut* >::iterator it =this->listeAttribut.begin(); it != this->listeAttribut.end(); ++it)
	{
		delete (*it);
	}
	this->listeAttribut.clear();
#ifdef MAP
    cout << "Appel au destructeur de <Maladie>" << endl;
#endif
} //----- Fin de ~Maladie


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées

  //------------------------------------------------------- Méthodes privées

