/*************************************************************************
Test  -  tests unitaires
-------------------
debut                : 31.05.2018
copyright            : (C) 2018 par Tifenn FLOCH
									Anatolii GASIUK
									Leo PAPE
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
/*	void Test::test()
	{
		cout << "----------- Test  -----------" << endl;

	
		cout << "----------- Fin de Test se Connecter -----------" << endl;
	}   

*/

	void Test::testInitialisation(string nomFichier, Initialisation &in)
	{
		cout << "----------- Test Initialisation Maladie -----------" << endl;
		unordered_map<int, Maladie> *mapTmp = &in.getListeMaladie();
		unordered_map<int, Maladie>::iterator it;
		cout << "----------- liste Maladies avant -----------" << endl;
		if (mapTmp->begin() == mapTmp->end())
		{
			cout << "Pas de maladie presente" << endl;
		}
		for (it = mapTmp->begin(); it != mapTmp->end(); ++it)
		{
			cout << it->second << endl;
		}
		
		in.init(nomFichier);
		cout << "----------- liste Maladies apres -----------" << endl;
		mapTmp = &in.getListeMaladie();
		if (mapTmp->begin() == mapTmp->end())
		{
			cout << "Pas de maladie presente" << endl;
		}
		for (it = mapTmp->begin(); it != mapTmp->end(); ++it)
		{
			cout << it->second << endl;
		}

		cout << "----------- Fin de Test Initialisation -----------" << endl;
	}

	void Test::testSplit(string lignef, string del )
	{
		vector<string> reponse;
		int pos = 0;
		while (pos != -1)
		{
			pos = lignef.find(del);
			if (del.size() != lignef.size())
			{

				if (pos != 0)
				{
					reponse.push_back(lignef.substr(0, pos));

				}
				if (pos != lignef.size() - 1 && pos != -1)
				{
					lignef.erase(0, pos + del.size());
				}
				else if (pos != -1)
				{
					lignef.erase(pos, pos + del.size());
					break;
				}
			}
			else
			{
				pos = -1;
				reponse.push_back(lignef);
			}

		}
		cout << "----------- Test Split -----------" << endl;
		cout << "----------- String entre -----------" << endl;
		cout << lignef << endl;
		cout << "----------- Sortie -----------" << endl;
		for (int i(0); i < reponse.size(); i++)
		{
			cout << reponse[i] << endl;
		}
		
		cout << "----------- Fin de Test se Connecter -----------" << endl;
	}

	void Test::testAnalyseEmpreinte(Empreinte e, unordered_map <int, Maladie> &mapMaladie)
	{
		cout << "----------- Test d'analyse d'empreinte -----------" << endl;
		Analyse a;
		unordered_map<string, double> maladiesPot = a.getMaladiesPotentielles();
		unordered_map<string, double>::iterator it;
		cout << "----------- liste des Maladies Potentielles Avant -----------" << endl;

		if (maladiesPot.begin() == maladiesPot.end())
		{
			cout << "Pas de maladie presente" << endl;
		}
		cout << a << endl;

		a.analyseEmpreinte(e, mapMaladie);

		cout << "----------- liste des Maladies Potentielles Apres -----------" << endl;
		cout << a << endl;

		cout << "----------- Fin de Test d'analyse d'empreinte -----------" << endl;
	}

	void Test::testInitialisationMedecin(string nomFichier, Initialisation &in)
	{
		cout << "----------- Test Initialisation Medecin -----------" << endl;
		cout << "----------- liste Medecin Avant -----------" << endl;
		if (in.getListeMedecin().size()==0)
		{
			cout << "Pas de Medecin present" << endl;
		}
		else
		{
			in.afficherMedecin();
		}
		
		in.initMedecin(nomFichier);
		cout << "----------- liste Medecin Apres -----------" << endl;

		if (in.getListeMedecin().size() == 0)
		{
			cout << "Pas de Medecin present" << endl;
		}
		else
		{
			in.afficherMedecin();
		}

		cout << "----------- Fin de Test Initialisation de Medecin -----------" << endl;
	}

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
		cout << "----------- FIN Test Ajouter Patient -----------\n" << endl;
	}

	void Test::testSeConnecter( Medecin m, vector <Medecin> liste)
	{
		cout << "----------- Test se Connecter -----------" << endl;

		bool estConnecte = m.seConnecter(liste);

		if (estConnecte) {

			cout << "Le medecin est bien connecte à l'appli." << endl;
		}
		else {

			cout << "Le medecin n'existe pas." << endl;
		}
		cout << "----------- FIN de Test se Connecter -----------\n" << endl;
	}

	void Test::testMesurerPatient(string mesures, Patient p, Medecin m)
	{
		cout << "----------- Test Mesurer Patient -----------" << endl;
		m.mesurerPatient(mesures, p);

		list <Empreinte> le = p.getEmpreintes();
	
		Empreinte e= le.back();
	
		cout << e.getMesures() << endl;
		cout << "-----------  FIN Test Mesurer Patient -----------\n" << endl;
	}

	void Test::testChargerEmpreinte(string nomFichier, vector<Patient> &liste, Medecin m, Initialisation &ini) {
		cout << "----------- Test Charger Empreinte -----------" << endl;
		
		m.chargerEmpreinte(nomFichier, liste);
		
	
		for(vector<Patient>::iterator it = liste.begin(); it != liste.end(); it++)
		{
			list<Empreinte> le = (*it).getEmpreintes();
			for (list<Empreinte>::const_iterator it2 = le.begin(); it2 != le.end(); it2++)
			{
				Empreinte temp = *it2;
				cout << temp.getMesures() << endl;
			}
		}
		cout << "-------------- FIN Test charger Empreinte -------------\n" << endl;
	}

	void Test::testRechercherAnalyse(Patient &p, Medecin &m) {
		
		int id= p.getAnalyses().back().getId();
		//Analyse test = p.getAnalyses().back();

		//cout << test << endl;
		Analyse a=m.rechercherAnalyse(id, p);

		cout <<"Analyse "<<a.getId()<<" a ete trouvee"<<a << endl;

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