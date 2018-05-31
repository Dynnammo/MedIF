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

#include "Medecin.h"
#include "Initialisation.h"

using namespace std;

	void Test::testAjouterPatient(Medecin m)
	{
		cout << "----------- Test Ajouter Patient -----------" << endl;
		cout << "Liste des Patients AVANT : " << endl;
		Initialisation ini;
		vector<Patient> listeP = ini.getListePatient();
		for (vector<Patient>::const_iterator it = listeP.cbegin(); it != listeP.cend(); it++)
		{
			(*it).afficher();
		}

		string n = "Marley";
		string p = "Bob";
		string mdp = "bm";

		m.ajouterPatient(n,p,mdp);

		cout << "Liste des Patients APRES : " << endl;
		//cout << ini.getListePatient().afficher() << endl;
		cout << "----------- FIN Test Ajouter Patient -----------" << endl;
	}

	void Test::testSeConnecter(string nomFichier, Medecin m)
	{
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
		string mes = it->getMesures();
		cout << mes;


	}