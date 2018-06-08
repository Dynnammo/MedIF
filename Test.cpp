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

		bool estReussi = true;
		for (unsigned int i(0); i < reponse.size(); i++)
		{
			switch (i) {

			case 0:
				if (reponse[i] != "A") {
					estReussi = false;
				}
				break;


			case 1:
				if (reponse[i] != "Z") {
					estReussi = false;
				}
				break;

			case 2:
				if (reponse[i] != "E") {
					estReussi = false;
				}
				break;


			case 6:
				if (reponse[i] != "TEST;") {
					estReussi = false;
				}
				break;
			}


		}
		
		if (estReussi == true) {

			cout << "Le test split est reussi" << endl;
		}
		else {
			cout << "Le test split a echoue." << endl;
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

		bool estReussi = true;
		/*if (in.getListeMedecin().size()==0)
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
		}*/
		in.initMedecin(nomFichier);
		if (in.getListeMedecin().size() == 0)
		{
			estReussi = false;
		}
	
		if (estReussi == true) {

			cout << "Le test d'initialisation des Medecins est reussi" << endl;
		}
		else {
			cout << "Le test d'initialisation des Medecins a echoue." << endl;

		}

		cout << "----------- Fin de Test Initialisation de Medecin -----------" << endl;
	}

	void Test::testAjouterPatient(Medecin medecin, vector <Patient> & listeP)
	{
		cout << "----------- Test Ajouter Patient -----------" << endl;
		/*cout << "Liste des Patients AVANT : " << endl;
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
		}*/
		bool estReussi = true;
		string n = "Marley";
		string p = "Bob";
		string m = "bob.marley@gmail.com";
		Patient test = medecin.ajouterPatient(n, p, m, listeP);

		if (listeP.back().getNom() != test.getNom() || listeP.back().getPrenom() != test.getPrenom() || listeP.back().getMail() != test.getMail()) {
			estReussi = false;
		}

		if (estReussi == true) {

			cout << "Le test d'ajout de Patient est reussi" << endl;
		}
		else {

			cout << "Le test d'ajout de Patient a echoue" << endl;
		}
		
		cout << "----------- FIN Test Ajouter Patient -----------\n" << endl;
	}

	void Test::testSeConnecter( Medecin m, vector <Medecin> liste)
	{
		cout << "----------- Test se Connecter -----------" << endl;

		bool estConnecte = m.seConnecter(liste);

		if (estConnecte) {

			cout << "Le medecin est bien connecte à l'appli, test reussi." << endl;
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
	
		if (e.getMesures() == mesures) {

			cout << "Test de Mesure du Patient reussie" << endl;
		}
		else {
			cout << "Test de Mesure du Patient echoue" << endl;
		}
		cout << "-----------  FIN Test Mesurer Patient -----------\n" << endl;
	}

	void Test::testChargerEmpreinte(string nomFichier, vector<Patient> &liste, Medecin m) {

		bool estReussi = true;
		cout << "----------- Test Charger Empreinte -----------" << endl;
		
		m.chargerEmpreinte(nomFichier, liste);
		
	
		for (vector<Patient>::iterator it = liste.begin(); it != liste.end(); it++)
		{
			//cout <<"id du Patient"<< it->getIdPersonne() << endl;
			list<Empreinte> le = (*it).getEmpreintes();

			if (it->getIdPersonne() == 1) {

				Empreinte e = le.back();

				if (e.getMesures() == "False;1.1;14.3;13.2;2367") {

					cout << "Le test de chargement d'empreinte est reussi pour le patient d'id 1" << endl;
				}
				else {
					cout << "Le test de chargement d'empreinte a echoue pour le patient d'id 1" << endl;
					estReussi = false;
				}

				

			}

			if (it->getIdPersonne() == 4) {
				Empreinte e = le.back();
				if (e.getMesures() == "False;1.1;14.3;13.2;2368") {

					cout << "Le test de chargement d'empreinte est reussi pour le patient d'id 4" << endl;
				}
				else {
					cout << "Le test de chargement d'empreinte a echoue pour le patient d'id 4" << endl;
					estReussi = false;
				}

			}

			if (it->getIdPersonne() == 3) {
				Empreinte e = le.back();
				if (e.getMesures() == "False;1.1;14.3;13.2;2365") {

					cout << "Le test de chargement d'empreinte est reussi pour le patient d'id 3" << endl;
				}
				else {
					cout << "Le test de chargement d'empreinte a echoue pour le patient d'id 3" << endl;
					estReussi = false;
				}

			}
		}

		if (estReussi == true) {

			cout << "Le test de chargement d'empreinte a reussi pour tous les patients." << endl;
		}
			/*for (list<Empreinte>::const_iterator it2 = le.begin(); it2 != le.end(); it2++)
			{
				Empreinte temp = *it2;
				cout << temp.getMesures() << endl;
			}
		}*/
		cout << "-------------- FIN Test charger Empreinte -------------\n" << endl;
	}

	void Test::testRechercherAnalyse(Patient &p, Medecin &m) {
		
		cout << "----------- Test Rechercher Analyse -----------" << endl;
		int id= p.getAnalyses().back().getId();
		cout << "voici l'id recherche : " << id << endl;
		bool estReussi = true;
		//Analyse test = p.getAnalyses().back();

		//cout << test << endl;
		Analyse a=m.rechercherAnalyse(id, p);

		unordered_map <string, double> liste = a.getMaladiesPotentielles();
		unordered_map <string, double> liste2 = p.getAnalyses().back().getMaladiesPotentielles();

		unordered_map <string, double>::iterator it2 = liste2.begin();
		for (unordered_map <string, double>::iterator it = liste.begin(); it != liste.end(); it++) {
			if (it->first != it2->first || it2->second != it->second) {

				estReussi = false;
			}

			it2++;
		}
			
		if (estReussi == true) {

			cout << "Le test de recherche d'Analyse a reussi." << endl;
		}
		else {
			cout << "Le test de recherche d'Analyse a echoue." << endl;
		}

		cout << "-------------- FIN Test rechercher Analyse -------------\n" << endl;

		//cout <<"Analyse "<<a.getId()<<" a ete trouvee"<<a << endl;

	}

	void Test::testEmpreinteSaine(Medecin m, vector<Patient> &liste, string nomFichier,Patient p, unordered_map<int, Maladie> &lm) {
		cout << "----------- Test Faire Analyse d'une Empreinte saine -----------" << endl;
		
		/*for (int i = 0; i < liste.size(); i++) {
			cout << "id patient :" << p.getIdPersonne();
		}*/
		m.chargerEmpreinte(nomFichier, liste);
		//list <Analyse> la=m.faireAnalyse(p, lm,false);
	}
	
	void Test::testFaireAnalyse(Medecin m, Patient p, unordered_map<int, Maladie> &lm)
	{
		cout << "----------- Test Faire Analyse -----------" << endl;
		/*Empreinte e1("TT;158.785072773956;134.202843809773;155.578398714048");*/
		Empreinte e2("AA;25;131;147");
		Empreinte e3("AA;149;-11;161");
		Empreinte e4("AA;-41;11;182");
		Empreinte e5("AT;75;84;221");
		Empreinte e1("AT; 102; 63;203");

		// faire analyse pour 1 empreinte
		cout << "--- Analyse d'une empreinte ---" << endl;
		p.setEmpreintes(e1);
		list<Empreinte> le = p.getEmpreintes();
	

		m.faireAnalyse(p, lm, false);

		list<Analyse> la = p.getAnalyses();

		Analyse a = la.back();
		bool estReussi = true;
		unordered_map<string, double> maladies = a.getMaladiesPotentielles();

		int index = 0;
		for (unordered_map<string, double>::iterator it = maladies.begin(); it != maladies.end(); it++) {

			switch (index) {

			case 0:
				cout << "première analyse :" << it->first << " " << it->second << endl;
				if (it->first != "M3" && it->second != 0.484849) {
					
					estReussi = false;
				}
				break;


			case 1:
				if (it->first != "sain" && it->second != 0.733754) {
					estReussi = false;
				}
				break;



			}

			index++;
		}

			if (estReussi == true) {

				cout << "Le test faire une analyse est reussi." << endl;
			}
			else {

				cout << "Le test faire une analyse a echoue." << endl;
			}

			estReussi = true;


			p.setEmpreintes(e2);
			p.setEmpreintes(e3);
			p.setEmpreintes(e4);
			p.setEmpreintes(e5);
	
			m.faireAnalyse(p, lm, true);

			list <Analyse> listeA2 = p.getAnalyses();

		

			Analyse a1 = listeA2.back();
			listeA2.pop_back();

			unordered_map<string, double> maladies1 = a1.getMaladiesPotentielles();

			 index = 0;
			for (unordered_map<string, double>::iterator it = maladies1.begin(); it != maladies1.end(); it++) {

				switch (index) {

				case 0:
					cout << "première analyse :" << it->first << " " << it->second << endl;
					if (it->first != "M1" && it->second != 0.560838) {

						estReussi = false;
					}
					break;


				case 1:
					if (it->first != "M4" && it->second != 0.621925) {
						estReussi = false;
					}
					break;

				case 2:
					if (it->first != "sain" && it->second != 0.934547) {
						estReussi = false;
					}
					break;



				}

				index++;
			}
			Analyse a2 = listeA2.back();
			listeA2.pop_back();

			unordered_map<string, double> maladies2 = a2.getMaladiesPotentielles();

		 index = 0;
			for (unordered_map<string, double>::iterator it = maladies2.begin(); it != maladies2.end(); it++) {

				switch (index) {

				case 0:
					cout << "première analyse :" << it->first << " " << it->second << endl;
					if (it->first != "M4" && it->second != 0.886387) {

						estReussi = false;
					}
					break;

				}

				index++;
			}
			Analyse a3= listeA2.back();
			listeA2.pop_back();


			unordered_map<string, double> maladies3 = a3.getMaladiesPotentielles();

		index = 0;
			for (unordered_map<string, double>::iterator it = maladies3.begin(); it != maladies3.end(); it++) {

				switch (index) {

				case 0:
					cout << "première analyse :" << it->first << " " << it->second << endl;
					if (it->first != "M1" && it->second != 0.560838) {

						estReussi = false;
					}
					break;


				}

				index++;
			}
			Analyse a4 = listeA2.back();
			listeA2.pop_back();
	
			if (estReussi == true) {
				cout << "Test reussi pour plusieurs analyses" << endl;
			}
			else {
				cout << "Test echoue pour plusieurs analyses" << endl;
			}
			
			cout << "----------- Fin Test Faire Analyse -----------" << endl;
		}
	

	///////////////////////////////////////Test fonctionnels de classe Initialisation
	bool Test::testAfficherMaladies(unordered_map<int, Maladie> &m)
	{
		cout << "----------Debut de test fonctionnel : AfficherMaladies----------" << endl;
		if (m.size() != 0 && m.begin()->second.getListeAttribut().size() != 0)
		{
			cout << "----------Fin de test fonctionnel : AfficherMaladies----------" << endl;
			return true;
		}
		cout << "----------Fin de test fonctionnel : AfficherMaladies----------" << endl;
		return false;
	}

	bool Test::seConnecterMauvaisMdp(vector <Medecin> liste, string n, string m, string p, string motDePasse) {

		Medecin med(n, m, p, motDePasse);
		bool estCo=med.seConnecter(liste);

		return estCo;
	}

	bool Test::testCreerMaladie(string nomFichier)
	{
		cout << "----------Debut de test fonctionnel : CreerMaladie----------" << endl;
		Initialisation ii;
		ii.init(nomFichier);
		unordered_map<int, Maladie> m = ii.getListeMaladie();
		if (m.size() != 0 && m.begin()->second.getListeAttribut().size() != 0)
		{
			cout << "----------Fin de test fonctionnel : CreerMaladie----------" << endl;
			return true;
		}
		cout << "----------Fin de test fonctionnel : CreerMaladie----------" << endl;
		return false;
	}

	bool Test::testCreerMaladieErreur(string nomFichier)
	{
		cout << "----------Debut de test fonctionnel : CreerMaladieErreur----------" << endl;
		cout << "----------Fin de test fonctionnel : CreerMaladieErreur----------" << endl;
		return !this->testCreerMaladie(nomFichier);
	}

	///////////////////////////////////////Test fonctionnels de classe Analyse

	bool Test::testAlertAnalysesupplementaires(Initialisation i)
	{
		Empreinte sain("AT;75;84;225");
		Empreinte malade("AA;172.984793832031;201.510355876721;149.614446667032");
		Empreinte aucunResultat("Toto;182,201,149");
		cout << "----------Debut de test fonctionnel : Alert pour analyses supplementaires----------" << endl;
		Analyse a;
		Analyse b;
		Analyse c;

		a.analyseEmpreinte(sain, i.getListeMaladie());
		b.analyseEmpreinte(malade, i.getListeMaladie());
		c.analyseEmpreinte(aucunResultat, i.getListeMaladie());
		unordered_map <string, double> liste = a.getMaladiesPotentielles();
		unordered_map <string, double>::iterator it;
		for (it =liste.begin(); it != liste.end(); ++it)
		{
			if (it->second < 0.5)
			{
				cout << "----------Fin de test fonctionnel : Alert pour analyses supplementaires----------" << endl;
				return true;
			}
		}
		liste = b.getMaladiesPotentielles();
		for (it = liste.begin(); it != liste.end(); ++it)
		{
			if (it->second < 0.5)
			{
				cout << "----------Fin de test fonctionnel : Alert pour analyses supplementaires----------" << endl;
				return true;
			}
		}
		liste = c.getMaladiesPotentielles();
		for (it = liste.begin(); it != liste.end(); ++it)
		{
			if (it->second < 0.5)
			{
				cout << "----------Fin de test fonctionnel : Alert pour analyses supplementaires----------" << endl;
				return true;
			}
		}

		cout << "----------Fin de test fonctionnel : Alert pour analyses supplementaires----------" << endl;
		return false;
	}

	bool Test::testAlertAnalysesupplementairesPlusieursEmpreintes(Initialisation i)
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
		unordered_map<string, double>::iterator it;
		unordered_map <string, double> liste;

		for (int p(0); p < ve.size(); p++)
		{
			Analyse a;
			a.analyseEmpreinte(ve[p], i.getListeMaladie());
			 liste= a.getMaladiesPotentielles();
			for (it = liste.begin(); it != liste.end(); ++it)
			{
				if (it->second < 0.5)
				{
					cout << "----------Fin de test fonctionnel : Alert pour analyses supplementaires- pour plusieurs empreintes---------" << endl;
					return true;
				}
			}
		}

		cout << "----------Fin de test fonctionnel : Alert pour analyses supplementaires- pour plusieurs empreintes---------" << endl;
		return false;

	}