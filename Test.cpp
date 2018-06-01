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
#include "Medecin.h"

using namespace std;

	void Test::testAjouterPatient(Medecin medecin, vector <Patient> & listeP)
	{
		cout << "----------- Test Ajouter Patient -----------" << endl;
		cout << "Liste des Patients AVANT : " << endl;
		for (unsigned int i(0); i<listeP.size(); i++)
		{
			listeP[i].afficher();
			cout << endl;
		}

		string n = "Marley";
		string p = "Bob";
		string mdp = "bm";

		Patient test = medecin.ajouterPatient(n,p,mdp, listeP);
		
		cout << "Liste des Patients APRES : " << endl;
		for (unsigned int i(0); i<listeP.size(); i++)
		{
			listeP[i].afficher();
			cout << endl;
		}
		cout << "----------- FIN Test Ajouter Patient -----------" << endl;
	}

	void Test::testSeConnecter( Medecin m, vector <Medecin> liste)
	{
		cout << "----------- Test se Connecter -----------" << endl;

		bool estConnecte = m.seConnecter(liste);

		if (estConnecte) {

			cout << "Le médecin est bien connecté à l'appli." << endl;
		}
		else {

			cout << "Le médecin n'existe pas." << endl;
		}
		cout << "----------- Fin de Test se Connecter -----------" << endl;
	}

	void Test::testMesurerPatient(string mesures, Patient p, Medecin m)
	{
		cout << "----------- Test Mesurer Patient -----------" << endl;
		m.mesurerPatient(mesures, p);

		list <Empreinte> le = p.getEmpreintes();
		Empreinte e = le.back();

		cout << e.getMesures();

		cout << "----------- Fin de Test se Connecter -----------" << endl;
	}

	void Test::testFaireAnalyse(Medecin m, Patient p, unordered_map<int, Maladie> &lm)
	{
		cout << "----------- Test Faire Analyse -----------" << endl;
		Empreinte e1("True;101;bloup;100%");
		Empreinte e2("False;0.001;bloup;0%");
		Empreinte e3("NA;50;blidou;50%");

		// faire analyse pour 1 empreinte
		cout << "--- Analyse d'une empreinte ---" << endl;
		p.setEmpreintes(e1);
		list<Empreinte> le = p.getEmpreintes();
		list<Analyse> la = p.getAnalyses();

		cout << "Liste des Empreintes AVANT : " << endl;
		for (list<Empreinte>::const_iterator it = le.cbegin(); it != le.cend(); it++)
		{
			cout << (*it) << endl;
		}

		cout << "Liste des Analyses AVANT : " << endl;
		for (list<Analyse>::const_iterator it = la.cbegin(); it != la.cend(); it++)
		{
			cout << (*it) << endl;
		}

		m.faireAnalyse(p, lm);

		cout << "Liste des Empreintes APRES : " << endl;
		for (list<Empreinte>::const_iterator it = le.cbegin(); it != le.cend(); it++)
		{
			cout << (*it) << endl;
		}

		cout << "Liste des Analyses APRES : " << endl;
		for (list<Analyse>::const_iterator it = la.cbegin(); it != la.cend(); it++)
		{
			cout << (*it) << endl;
		}

		// faire analyse pour plusieurs empreintes
		cout << "--- Analyse de plusieurs empreintes ---" << endl;
		p.setEmpreintes(e2);
		p.setEmpreintes(e3);

		cout << "Liste des Empreintes AVANT : " << endl;
		for (list<Empreinte>::const_iterator it = le.cbegin(); it != le.cend(); it++)
		{
			cout << (*it) << endl;
		}

		cout << "Liste des Analyses AVANT : " << endl;
		for (list<Analyse>::const_iterator it = la.cbegin(); it != la.cend(); it++)
		{
			cout << (*it) << endl;
		}

		m.faireAnalyse(p, lm);

		cout << "Liste des Empreintes APRES : " << endl;
		for (list<Empreinte>::const_iterator it = le.cbegin(); it != le.cend(); it++)
		{
			cout << (*it) << endl;
		}

		cout << "Liste des Analyses APRES : " << endl;
		for (list<Analyse>::const_iterator it = la.cbegin(); it != la.cend(); it++)
		{
			cout << (*it) << endl;
		}

		cout << "----------- Fin Test Faire Analyse -----------" << endl;
	}
}