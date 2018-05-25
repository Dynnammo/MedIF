

/*************************************************************************
Empreinte  -  description
-------------------
début                : 27.04.2018
copyright            : (C) 2018 par Tifenn FLOCH
									Anatolii GASIUK
									Léo PAPE
									Baptiste THIVEND
e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Empreinte> (fichier Empreinte.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;


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


//------------------------------------------------- Surcharge d'opérateurs


  //-------------------------------------------- Constructeurs - destructeur

Empreinte:: Empreinte(string nomFichier)
// Algorithme :
//
{
	
	ifstream fichier("D:/Etudes/INSA/TP/GL et UML/MedIF"); //attention path à modifier selon les ordis
	string ligne;
	if (fichier) {
		while (getline(fichier, ligne)) {


			mesures += ligne;

		}
	}
	else {
		cerr << "erreur lors de l'ouverture du fichier" << endl;
		}

	idEmpreinte = id++;


	
} //----- Fin de Empreinte


Empreinte::~Empreinte ()
// Algorithme :
//
{
	id--;
} //----- Fin de ~Empreinte


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées

  //------------------------------------------------------- Méthodes privées
