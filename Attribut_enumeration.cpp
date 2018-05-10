/*************************************************************************
Attribut_enumeration  -  description
-------------------
d�but                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- R�alisation de la classe <Attribut_enumeration> (fichier Attribut_enumeration.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me

#include <iostream>
#include <string>
#include <vector>

//------------------------------------------------------ Include personnel
#include "Attribut_enumeration.h"
#include "Attribut.h"
using namespace std;
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe
int nbValeurs;
vector <std::string> valeurs;
//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
// type Attribut_enumeration::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

int Attribut_enumeration::getIdAttribut()
{
	return this->idAttribut;
}

int Attribut_enumeration::getNbValeurs()
{
	return this->nbValeurs;
}

vector<string> Attribut_enumeration::getValeurs()
{
	return this->valeurs;
}

void Attribut_enumeration::setNbValeurs(int nb)
{
	this->nbValeurs = nb;
}

void Attribut_enumeration::setValeur(string val)
{
	this->valeurs.push_back(val);
}
//------------------------------------------------- Surcharge d'op�rateurs
Attribut_enumeration & Attribut_enumeration::operator = (const Attribut_enumeration & unAttribut_enumeration)
// Algorithme :
//
{

	this->idAttribut = unAttribut_enumeration.idAttribut;
	this->nbValeurs = unAttribut_enumeration.nbValeurs;
	this->valeurs = unAttribut_enumeration.valeurs;
	return *this;
} //----- Fin de operator =

ostream& Attribut_enumeration::afficher(ostream &flux)
// Algorithme :
//
{
	flux << this->idAttribut << "   " << this->valeurs[0] << endl;
	for (unsigned int i(1); i < this->valeurs.size(); i++)
	{
		flux << "  " << "   " << this->valeurs[i] << endl;
	}
	return flux;
} //----- Fin de operator <<

  //-------------------------------------------- Constructeurs - destructeur
Attribut_enumeration::Attribut_enumeration(const Attribut_enumeration & unAttribut_enumeration)
// Algorithme :
//
{

} //----- Fin de Attribut_enumeration (constructeur de copie)


Attribut_enumeration::Attribut_enumeration()
// Algorithme :
//
{

} //----- Fin de Attribut_enumeration

Attribut_enumeration::Attribut_enumeration(int nbValeurs, vector<string> valeurs)
// Algorithme :
//
{
	this->nbValeurs = nbValeurs;
	this->valeurs = valeurs;
} //----- Fin de Attribut_enumeration

Attribut_enumeration::~Attribut_enumeration()
// Algorithme :
//
{

} //----- Fin de ~Attribut_enumeration


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- M�thodes prot�g�es

  //------------------------------------------------------- M�thodes priv�es

