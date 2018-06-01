/*************************************************************************
Empreinte  -  description
-------------------
d�but                : 01.06.2018
copyright            : (C) 2018 par Tifenn FLOCH
Anatolii GASIUK
L�o PAPE
Baptiste THIVEND
e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- R�alisation de la classe <Empreinte> (fichier Empreinte.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "Empreinte.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
// type Empreinte::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode


//------------------------------------------------------ Getters - Setters
string Empreinte::getMesures() const
{
	return mesures;
}

//------------------------------------------------- Surcharge d'op�rateurs
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
	:idEmpreinte(unEmpreinte.idEmpreinte), mesures(unEmpreinte.mesures)
{
	///mesures = unEmpreinte.getMesures();
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
	id--;
#ifdef MAP
	cout << "Appel au destructeur de <Empreinte>" << endl;
#endif
	} //----- Fin de ~Empreinte


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- M�thodes prot�g�es

  //------------------------------------------------------- M�thodes priv�es

