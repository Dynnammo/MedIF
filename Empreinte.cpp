

/*************************************************************************
${file_base}  -  description
-------------------
début                : ${date}
copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <${file_base}> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include "stdafx.h"
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
// type ${file_base}::Méthode ( liste de paramètres )
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
	
	ifstream fichier("L:\Mes documents\Visual Studio 2015\Projects\MedIF\MedIF\nomFichier"); //attention path à modifier selon les ordis
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


	
} //----- Fin de ${file_base}


Empreinte::~Empreinte ()
// Algorithme :
//
{
	id--;
} //----- Fin de ~${file_base}


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées

  //------------------------------------------------------- Méthodes privées
