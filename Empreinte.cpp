

/*************************************************************************
Empreinte  -  description
-------------------
d�but                : 27.04.2018
copyright            : (C) 2018 par Tifenn FLOCH
									Anatolii GASIUK
									L�o PAPE
									Baptiste THIVEND
e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- R�alisation de la classe <Empreinte> (fichier Empreinte.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <iostream>
using namespace std;

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

//------------------------------------------------- Surcharge d'op�rateurs


//-------------------------------------------- Constructeurs - destructeur


Empreinte::~Empreinte ()
// Algorithme :
//
{
	id--;
#ifdef MAP
    cout << "Appel au destructeur de <Empreinte>" << endl;
#endif
} //----- Fin de ~Empreinte


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- M�thodes prot�g�es

  //------------------------------------------------------- M�thodes priv�es
