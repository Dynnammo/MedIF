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

#include <string>

//------------------------------------------------------ Include personnel

#include "Medecin.cpp"
#include "Initialisation.cpp"

using namespace std;

	void Test::testAjouterPatient()
	{
		cout << "----------- Test Ajouter Patient -----------" << endl;
		Initialisation i;
		cout << "Liste des Patients AVANT : " << endl;
		cout << i.getListePatient() << endl;

		string n = "Marley";
		string p = "Bob";
		string m = "bm";

		Medecin.ajouterPatient(n,p,m);

		cout << "Liste des Patients APRES : " << endl;
		cout << i.getListePatient() << endl;
		cout << "----------- FIN Test Ajouter Patient -----------" << endl;
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

	void Test::testMesurerPatient(string mesures, Patient p, Medecin m) {

		m.mesurerPatient(mesures, p);

		list <Empreinte> le = p.getEmpreintes();

		list<Empreinte>::const_iterator it = le.end();
		string mes = it->getMesures;
		cout << mes;


	}