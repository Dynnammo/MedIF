/*************************************************************************
Patient  -  description
-------------------
d�but                : 27.04.2018
copyright            : (C) 2018 par Tifenn FLOCH
Anatolii GASIUK
L�o PAPE
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

//--------------------------------------------------- Interfaces utilis�es
#include "Personne.h"
#include "Empreinte.h"
#include "Analyse.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <Patient>
//
//
//------------------------------------------------------------------------ 

class Test
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
	// type M�thode ( liste de param�tres );
	// Mode d'emploi :
	//
	// Contrat :
	

	
	//------------------------------------------------- Surcharge d'op�rateurs

	// Mode d'emploi :
	//
	// Contrat :
	//
	//------------------------------------------------- Surcharge d'op�rateurs
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
	//----------------------------------------------------- M�thodes prot�g�es

private:
	//------------------------------------------------------- M�thodes priv�es

protected:
	//----------------------------------------------------- Attributs prot�g�s


private:
	//------------------------------------------------------- Attributs priv�s
	
	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Patient>

#endif // PATIENT_H
#pragma once
