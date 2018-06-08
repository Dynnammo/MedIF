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
//#include <typeinfo.h>
//------------------------------------------------------ Include personnel
#include "Maladie.h"
#include "Attribut.h"
#include "Attribut_enumeration.h"
#include "Attribut_intervalle.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe
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

string Maladie::getNom()
{
	return this->nomMaladie;
}

void Maladie::setNom(string nom)
{
	this->nomMaladie = nom;
}

void Maladie::setId(int id)
{
	this->idMaladie = id;
}

//------------------------------------------------- Surcharge d'op�rateurs
Maladie & Maladie::operator = ( Maladie const & unMaladie)
// Algorithme :
//
{
	this->idMaladie = unMaladie.idMaladie;
	this->nomMaladie = unMaladie.nomMaladie;
	vector<Attribut*> temp = unMaladie.listeAttribut;
	for (unsigned int i(0); i < temp.size(); i++)
	{
		if (typeid(*temp[i]) == typeid((Attribut_intervalle())))
		{
			Attribut *a = new Attribut_intervalle(*(Attribut_intervalle*)(temp[i]));
			this->listeAttribut.push_back(a);
		}
		else
		{
			Attribut *a = new Attribut_enumeration(*(Attribut_enumeration*)(temp[i]));
			this->listeAttribut.push_back(a);
		}
		
	}
	return *this;
} //----- Fin de operator =

ostream& operator<<(ostream &flux, Maladie const& maladie)
// Algorithme :
//
{
	flux << "Maladie : " << maladie.nomMaladie << endl;
	for (unsigned int i(0); i < maladie.listeAttribut.size(); i++)
	{
		maladie.listeAttribut[i]->afficher(flux);

	}
	return flux;
} //----- Fin de M�thode

  //-------------------------------------------- Constructeurs - destructeur
Maladie::Maladie(const Maladie &m)
	:idMaladie(m.idMaladie), nomMaladie(m.nomMaladie)
{
	vector<Attribut*> temp = m.listeAttribut;
	for (unsigned int i(0); i < temp.size(); i++)
	{
		if (typeid(*temp[i]) == typeid((Attribut_intervalle())))
		{
			Attribut *a = new Attribut_intervalle(*(Attribut_intervalle*)(temp[i]));
			this->listeAttribut.push_back(a);
		}
		else
		{
			Attribut *a = new Attribut_enumeration(*(Attribut_enumeration*)(temp[i]));
			this->listeAttribut.push_back(a);
		}

}
#ifdef MAP
    cout << "Appel au constructeur de copie de <Maladie>" << endl;
#endif
} //----- Fin de Maladie (constructeur de copie)


Maladie::Maladie()
// Algorithme :
//
{
	this->qualite = 0;
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
	for (unsigned int i(0); i<this->listeAttribut.size();i++)
	{
		delete this->listeAttribut[i];
	}
	this->listeAttribut.clear();
#ifdef MAP
    cout << "Appel au destructeur de <Maladie>" << endl;
#endif
} //----- Fin de ~Maladie


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- M�thodes prot�g�es

  //------------------------------------------------------- M�thodes priv�es

