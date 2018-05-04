

/*************************************************************************
${file_base}  -  description
-------------------
d�but                : ${date}
copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <${file_base}> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include "stdafx.h"
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
// type ${file_base}::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode


//------------------------------------------------- Surcharge d'op�rateurs


  //-------------------------------------------- Constructeurs - destructeur

Empreinte:: Empreinte(string nomFichier)
// Algorithme :
//
{
	
	ifstream fichier("L:\Mes documents\Visual Studio 2015\Projects\MedIF\MedIF\nomFichier"); //attention path � modifier selon les ordis
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

  //----------------------------------------------------- M�thodes prot�g�es

  //------------------------------------------------------- M�thodes priv�es
