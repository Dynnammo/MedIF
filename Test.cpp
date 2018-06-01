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

	void Test::testAjouterPatient(Medecin medecin, Initialisation ini)
	{
		cout << "----------- Test Ajouter Patient -----------" << endl;
		cout << "Liste des Patients AVANT : " << endl;
		vector <Patient> listeP = ini.getListePatient();
		for (unsigned int i(0); i<listeP.size(); i++)
		{
			listeP[i].afficher();
			cout << endl;
		}

		string n = "Marley";
		string p = "Bob";
		string mdp = "bm";

		medecin.ajouterPatient(n,p,mdp, listeP);

		cout << "Liste des Patients APRES : " << endl;
		listeP = ini.getListePatient();
		for (unsigned int i(0); i<listeP.size(); i++)
		{
			listeP[i].afficher();
			cout << endl;
		}
		cout << "----------- FIN Test Ajouter Patient -----------" << endl;
	}

	void Test::testSeConnecter(string nomFichier, Medecin m)
	{
		Initialisation ini;
		ini.initMedecin(nomFichier);

		bool estConnecte = m.seConnecter(liste);

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