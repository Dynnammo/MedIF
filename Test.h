/*************************************************************************
Test  -  tests unitaires
-------------------
d�but                : 31.05.2018
copyright            : (C) 2018 par Tifenn FLOCH
Anatolii GASIUK
L�o PAPE
Baptiste THIVEND
e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Test> (fichier Test.h) ------
#if ! defined ( TEST_H )
#define TEST_H

#include <string>
#include <iostream>

using namespace std;

//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <Test>
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


	//-------------------------------------------- Constructeurs - destructeur
	Test()
	{
#ifdef MAP
		cout << "Appel au constructeur de <Test>" << endl;
#endif
	}//----- Fin de Test (constructeur par d�faut)

	virtual ~Test()
	{
#ifdef MAP
		cout << "Appel au destructeur de <Test>" << endl;
#endif
	}//----- Fin de ~Test


	//--------------------------------------------- Tests de la classe Medecin
	void testAjouterPatient();
	void testFaireAnalyse();
	void testRechercherAnalyse();

	//--------------------------------------------- Tests de la classe Analyse


	//-------------------------------------- Tests de la classe Initialisation
};
#endif // PATIENT_H
#pragma once
