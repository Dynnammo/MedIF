/*************************************************************************
Maladie  -  description
-------------------
d�but                : 27.04.2018
copyright            : (C) 2018 par Tifenn FLOCH
									Anatolii GASIUK
									L�o PAPE
									Baptiste THIVEND
e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- R�alisation de la classe <Maladie> (fichier Maladie.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
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
//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
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

//------------------------------------------------- Surcharge d'op�rateurs
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
} //----- Fin de M�thode

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
    cout << "Appel au constructeur par d�faut de <Maladie>" << endl;
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

  //----------------------------------------------------- M�thodes prot�g�es

  //------------------------------------------------------- M�thodes priv�es

