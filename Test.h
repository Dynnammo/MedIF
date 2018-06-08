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
#include"Medecin.h"
#include <list>
#include <string>
#include "Initialisation.h"

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
		nbTestsFonctionnelsValides = 0;
		nbTestsUnitairesValides = 0;
		nbTestsNonFonctionnelsValides = 0;
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
	void testAjouterPatient(Medecin medecin, vector <Patient> & listeP);
	void testSeConnecter(Medecin m, vector <Medecin> liste);
	void testMesurerPatient(string mesures, Patient p, Medecin m);
	bool testFaireAnalyse(Medecin m, unordered_map<int, Maladie> &lm, bool opt);
	void testChargerEmpreinte(string nomFichier, vector<Patient> &liste, Medecin m);
	void testRechercherAnalyse(Patient &p, Medecin &m);
	void testInitialisationMedecinFaux(string nomFichier, Initialisation &in);


	//--------------------------------------------- Tests fonctionnels de la classe Medecin

	void testEmpreinteSaine(Medecin m, vector<Patient> &liste, string nomFichier, Patient p, unordered_map<int, Maladie> &lm);
	bool testAjouterPatienfonct(Medecin medecin, Initialisation i);
	bool testAjouterPatienErreurfonct(Medecin medecin, Initialisation i);
	bool testChargerEmpreintesErronee(Medecin m, string nomFichier);
	bool testChargerEmpreinteFausse(Medecin m, string nomFichier);
	bool testConnecterMedecin(Medecin m, vector <Medecin> liste);
	bool testFaireAnalysefonc(Medecin m, unordered_map<int, Maladie> &lm, bool opt);

	//--------------------------------------------- Tests de la classe Analyse

	//--------------------------------------------- Tests fonctionnels de la classe Analyse
	bool testAlertAnalysesupplementaires(Initialisation i);
	bool testAlertAnalysesupplementairesPlusieursEmpreintes(Initialisation i);
	//-------------------------------------- Tests de la classe Initialisation
	void testInitialisation(string nomFichier, Initialisation &ini);
	void testInitialisationMedecin(string nomFichier, Initialisation &ini);
	void testAnalyseEmpreinte(Empreinte e, unordered_map <int, Maladie> &mapMaladie);
	void testSplit(string test, string del);

	//-------------------------------------- Test fonctionnelles de la classe Initialisation
	bool testAfficherMaladies(unordered_map <int, Maladie> &mapMaladie);
	bool testCreerMaladie(string nomFichier);
	bool testCreerMaladieErreur(string nomFichier);
	bool seConnecterMauvaisMdp(vector <Medecin> liste, string n, string m, string p, string motDePasse);
	void testInitialisationFausse(string nomFichier, Initialisation &in);

	//----------------------------------------Test non Fonctionnels
	bool testVitesse(Initialisation i);
	bool testReutilisabilite(Initialisation i);

	//----------------------------------------Test Systeme

	bool testSysteme1(Medecin, vector <Medecin> listeMedecins, vector<Patient> &listePatients, unordered_map<int, Maladie> &lm, bool opt);
public:
	//----------------------------------------------------- Attributs publics
	int nbTestsUnitairesValides;
	int nbTestsFonctionnelsValides;
	int nbTestsNonFonctionnelsValides;
};
#endif // TEST_H
#pragma once
