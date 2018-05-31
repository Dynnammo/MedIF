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
#include "Test.h"

//------------------------------------------------------ Include personnel


using namespace std;

	void Test::testAjouterPatient()
	{

	}

	void Test::testFaireAnalyse()
	{

	}

	void Test::testSeConnecter(string nomFichier, Medecin m) {
		Initialisation ini;
		ini.initMedecin(nomFichier);
		bool estConnecte = m.seConnecter();

		if (estConnecte == true) {

			cout << "Le médecin est bien connecté à l'appli." << endl;
		}
		else {

			cout << "Le médecin n'existe pas." << endl;
		}
	}
