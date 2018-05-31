/*************************************************************************
Test  -  tests unitaires
-------------------
début                : 31.05.2018
copyright            : (C) 2018 par Tifenn FLOCH
									Anatolii GASIUK
									Léo PAPE
									Baptiste THIVEND
e-mail               : @insa-lyon.fr
*************************************************************************/

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "Test.h"
#include "Medecin.cpp"
#include "Initialisation.cpp"

using namespace std;

	void Test::testAjouterPatient()
	{
		cout << "----------- Test Ajouter Patient -----------" << endl;
		Initialisation i;
		cout << "Liste des Patients AVANT : " << endl;
		cout << i.getlistePatient() << endl;

		string n = "Marley";
		string p = "Bob";
		string m = "bm";

		Medecin.ajouterPatient(n,p,m);

		cout << "Liste des Patients APRES : " << endl;
		cout << i.getlistePatient() << endl;
		cout << "----------- FIN Test Ajouter Patient -----------" << endl;
	}

	void Test::testFaireAnalyse()
	{

	}