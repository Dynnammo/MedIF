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
#include "Test.h"
#include "Medecin.cpp"
#include "Initialisation.cpp"

using namespace std;

	void Test::testAjouterPatient(Medecin m)
	{
		cout << "----------- Test Ajouter Patient -----------" << endl;
		cout << "Liste des Patients AVANT : " << endl;
		Initialisation ini;
		list<Patient> listeP = ini.getlistePatient();
		for (list<Patient>::const_iterator it = listeP.cbegin(); it != listeP.cend(); it++)
		{
			cout << (*it).afficher() << endl;
		}

		string n = "Marley";
		string p = "Bob";
		string m = "bm";

		m.ajouterPatient(n,p,m);

		cout << "Liste des Patients APRES : " << endl;
		cout << i.getlistePatient().afficher() << endl;
		cout << "----------- FIN Test Ajouter Patient -----------" << endl;
	}

	void Test::testFaireAnalyse()
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
