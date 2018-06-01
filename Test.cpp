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

#include "Medecin.h"
#include "Initialisation.h"
#include "Test.h"

using namespace std;

	void Test::testAjouterPatient(Medecin medecin)
	{
		cout << "----------- Test Ajouter Patient -----------" << endl;
		cout << "Liste des Patients AVANT : " << endl;
		Initialisation ini;
		vector <Patient> listeP = ini.getListePatient();
		/*for (list<Patient>::const_iterator it = listeP.cbegin(); it != listeP.cend(); it++)
		{
			cout << (*it).afficher() << endl;
		}*/

		string n = "Marley";
		string p = "Bob";
		string mdp = "bm";

		medecin.ajouterPatient(n,p,mdp,listeP);

		cout << "Liste des Patients APRES : " << endl;
		//cout << i.getlistePatient().afficher() << endl;
		cout << "----------- FIN Test Ajouter Patient -----------" << endl;
	}

	void Test::testSeConnecter(string nomFichier, Medecin m)
	{
		Initialisation ini;
		ini.initMedecin(nomFichier);
		vector<Medecin> vm;
		vm.push_back(m);
		bool estConnecte = m.seConnecter(vm);

		if (estConnecte) {

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
		it--;
		Empreinte temp = *it;

		cout << temp.getMesures();


	}