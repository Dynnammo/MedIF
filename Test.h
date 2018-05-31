/*************************************************************************
Patient  -  description
-------------------
début                : 27.04.2018
copyright            : (C) 2018 par Tifenn FLOCH
Anatolii GASIUK
Léo PAPE
Baptiste THIVEND
e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Patient> (fichier Patient.h) ------
#if ! defined ( TEST_H )
#define TEST_H

#include <string>
#include <iostream>
#include <list>

using namespace std;

//--------------------------------------------------- Interfaces utilisées
#include "Personne.h"
#include "Empreinte.h"
#include "Analyse.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Patient>
//
//
//------------------------------------------------------------------------ 

class Test
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	

	
	//------------------------------------------------- Surcharge d'opérateurs

	// Mode d'emploi :
	//
	// Contrat :
	//
	//------------------------------------------------- Surcharge d'opérateurs
	 //----- Fin de operator =


	  //-------------------------------------------- Constructeurs - destructeur

	  // Mode d'emploi (constructeur de copie) :
	  //
	  // Contrat :
	  //

	Test()
	{
	}//----- Fin de Patient (constructeur de copie)

	


	virtual ~Test()
	{

#ifdef MAP
		cout << "Appel au destructeur de <Patient>" << endl;
#endif
	}//----- Fin de ~Patient


	 //------------------------------------------------------------------ PRIVE 

protected:
	//----------------------------------------------------- Méthodes protégées

private:
	//------------------------------------------------------- Méthodes privées

protected:
	//----------------------------------------------------- Attributs protégés


private:
	//------------------------------------------------------- Attributs privés
	
	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes privées

	//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Patient>

#endif // PATIENT_H
#pragma once
