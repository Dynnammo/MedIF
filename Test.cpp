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
				if (pos != (int)lignef.size() - 1 && pos != -1)
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
		for (unsigned int i(0); i < reponse.size(); i++)
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

	void Test::testChargerEmpreinte(string nomFichier, vector<Patient> &liste, Medecin m) {
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

	void Test::testEmpreinteSaine(Medecin m, vector<Patient> &liste, string nomFichier,Patient p, unordered_map<int, Maladie> &lm) {
		cout << "----------- Test Faire Analyse d'une Empreinte saine -----------" << endl;
		
		for (int i = 0; i < liste.size(); i++) {
			cout << "id patient :" << p.getIdPersonne();
		}
		m.chargerEmpreinte(nomFichier, liste);
		list <Analyse> la=m.faireAnalyse(p, lm);
	}
	
	void Test::testFaireAnalyse(Medecin m, Patient p, unordered_map<int, Maladie> &lm)
	{
		cout << "----------- Test Faire Analyse -----------" << endl;
		Empreinte e1("TT;158.785072773956;134.202843809773;155.578398714048");
		Empreinte e2("TT;-8.06041743387215;156.208637725086;127.004626704367");
		Empreinte e3("AT;-29.8670607474956;9.12582752675129;154.212716708429");

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

	///////////////////////////////////////Test fonctionnels de classe Initialisation
	void Test::testAfficherMaladies(unordered_map<int, Maladie> &m)
	{
		unordered_map<int, Maladie>::iterator it;
		for (it = m.begin(); it != m.end(); ++it)
		{
			cout << it->second << endl;
		}
	}

	void Test::testCreerMaladie(string nomFichier)
	{
		Initialisation ii;
		ii.init(nomFichier);
		unordered_map<int, Maladie> m = ii.getListeMaladie();
		unordered_map<int, Maladie>::iterator it;
		for (it = m.begin(); it != m.end(); ++it)
		{

			cout << it->second << endl;
		}

		if (m.begin() == m.end())
		{
			cout << "Attention : Pas de maladie Créee" << endl;
		}

	}

	///////////////////////////////////////Test fonctionnels de classe Analyse

	void Test::testAlertAnalysesupplementaires(Initialisation i)
	{
		Empreinte sain("AT;75;84;225");
		Empreinte malade("AA;172.984793832031;201.510355876721;149.614446667032");
		Empreinte aucunResultat("Toto;182,201,149");
		cout << "----------Debut de test fonctionnel : Alert pour analyses supplementaires----------" << endl;
		Analyse a;
		Analyse b;
		Analyse c;
		cout << "----------test pour personne en bonne sante------------" << endl;
		a.analyseEmpreinte(sain, i.getListeMaladie());
		cout << a << endl;
		cout << "----------test pour personne malade------------" << endl;
		b.analyseEmpreinte(malade, i.getListeMaladie());
		cout << b << endl;
		cout << "----------test pour personne sans resultat------------" << endl;
		c.analyseEmpreinte(aucunResultat, i.getListeMaladie());
		cout << "----------Fin de test fonctionnel : Alert pour analyses supplementaires----------" << endl;
	}

	void Test::testAlertAnalysesupplementairesPlusieursEmpreintes(Initialisation i)
	{
		cout << "----------Debut de test fonctionnel : Alert pour analyses supplementaires- pour plusieurs empreintes---------" << endl;

		vector<Empreinte> ve;

		ve.push_back(Empreinte("AA;25.9031133467853;131.884670383258;147.766366832492"));
		ve.push_back(Empreinte("AA;149.084428233379;-11.0641318146703;161.926491846857"));
		ve.push_back(Empreinte("AA;-41.3700728049188;11.9823805235924;182.606685356541"));
		ve.push_back(Empreinte("AT;75.715310469384;84.641826657236;221.676305582463"));
		ve.push_back(Empreinte("AT;79.3082936874793;90.4204976271684;149.529648264601"));
		ve.push_back(Empreinte("AT;-5.63242184270023;147.930197284059;124.357348523696"));
		ve.push_back(Empreinte("AT;164.822089406812;29.7361104819574;139.14984867508"));
		ve.push_back(Empreinte("AA;76.1269612581185;131.543560643103;182.610346524986"));
		ve.push_back(Empreinte("AA;172.984793832031;201.510355876721;149.614446667032"));
		ve.push_back(Empreinte("Toto;182,201,149"));


		for (int p(0); p < ve.size(); p++)
		{
			Analyse a;
			a.analyseEmpreinte(ve[p], i.getListeMaladie());
			cout << a << endl;
		}

		cout << "----------Fin de test fonctionnel : Alert pour analyses supplementaires- pour plusieurs empreintes---------" << endl;

	}