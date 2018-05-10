/*************************************************************************
Maladie  -  description
-------------------
d�but                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
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
	for (unsigned int i(0); i < this->listeAttribut.size(); i++)
	{
		delete(this->listeAttribut[i]);
	}
} //----- Fin de ~Maladie


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- M�thodes prot�g�es

  //------------------------------------------------------- M�thodes priv�es

