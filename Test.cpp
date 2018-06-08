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
#include <time.h>

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
		nbTestsUnitairesValides++;
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
			nbTestsUnitairesValides++;
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
		cout << "----------- liste des Maladies Potentielles Apres -----------" << endl;
		a.analyseEmpreinte(e, mapMaladie);

		unordered_map<string, double>maladiesPotentielles = a.getMaladiesPotentielles();

		if (maladiesPotentielles.size() != 0) {
			nbTestsUnitairesValides++;
		}
		cout << a << endl;

		cout << "----------- Fin de Test d'analyse d'empreinte -----------" << endl;
	}

	void Test::testInitialisationMedecin(string nomFichier, Initialisation &in)
	{
		cout << "----------- Test Initialisation Medecin -----------" << endl;
	

		bool estReussi = true;
		
		in.initMedecin(nomFichier);
		if (in.getListeMedecin().size() == 0)
		{
			estReussi = false;
		}
	
		if (estReussi == true) {

			cout << "Le test d'initialisation des Medecins est reussi" << endl;
			nbTestsUnitairesValides++;
		}
		else {
			cout << "Le test d'initialisation des Medecins a echoue." << endl;

		}

		cout << "----------- Fin de Test Initialisation de Medecin -----------" << endl;
	}

	void Test::testAjouterPatient(Medecin medecin, vector <Patient> & listeP)
	{
		cout << "----------- Test Ajouter Patient -----------" << endl;
	
		bool estReussi = true;
		string n = "Marley";
		string p = "Bob";
		string m = "bob.marley@gmail.com";
		Patient test = medecin.ajouterPatient(n, p, m, listeP);

		if (listeP.back().getNom() != test.getNom() || listeP.back().getPrenom() != test.getPrenom() || listeP.back().getMail() != test.getMail()) {
			estReussi = false;
		}

		if (estReussi == true) {
			nbTestsUnitairesValides++;
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
			nbTestsUnitairesValides++;

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
			nbTestsUnitairesValides++;
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
			//cout <<"id du Patient :"<< it->getIdPersonne() << endl;
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
			nbTestsUnitairesValides++;
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
			nbTestsUnitairesValides++;
			cout << "Le test de recherche d'Analyse a reussi." << endl;
		}
		else {
			cout << "Le test de recherche d'Analyse a echoue." << endl;
		}

		cout << "-------------- FIN Test rechercher Analyse -------------\n" << endl;

		//cout <<"Analyse "<<a.getId()<<" a ete trouvee"<<a << endl;

	}

	
	
	bool Test::testFaireAnalyse(Medecin m, unordered_map<int, Maladie> &lm, bool opt)
	{
		cout << "----------- Test Faire Analyse -----------" << endl;

		Patient p;
		vector<Empreinte> ve;

		ve.push_back(Empreinte("AA;25;131;147"));
		ve.push_back(Empreinte("AA;149;-11.;161"));
		ve.push_back(Empreinte("AA;-41;11;182"));
		ve.push_back(Empreinte("AT;75;84;221"));
		ve.push_back(Empreinte("AT;79;90;149"));
		ve.push_back(Empreinte("AT;-5;147;124"));
		ve.push_back(Empreinte("AT;164;29;139"));
		ve.push_back(Empreinte("AA;76;131;182"));
		ve.push_back(Empreinte("AA;172;201;149"));

		// faire analyse pour 1 empreinte
		vector<Analyse> refA;
		if (opt)
		{
			cout << "--- Analyse de plusieurs empreintes ---" << endl;
			for (int i(0); i < 9; i++)
			{
				Analyse a;
				a.analyseEmpreinte(ve[i], lm);
				p.setEmpreintes(ve[i]);
				refA.push_back(a);
			}

		}
		else
		{
			cout << "--- Analyse d'une empreinte ---" << endl;
			p.setEmpreintes(ve[0]);
			Analyse a;
			a.analyseEmpreinte(ve[0], lm);
			refA.push_back(a);
		}

		list<Empreinte> le = p.getEmpreintes();
		m.faireAnalyse(p, lm,opt);
		list<Analyse> la = p.getAnalyses();

		bool estReussi = true;
		list<Analyse>::iterator it;
		int index = 0;
		for (it=la.begin();it!=la.end();index++ ,++it)
		{
			if (refA[index].getMaladiesPotentielles().size() != (*it).getMaladiesPotentielles().size())
			{
				estReussi = false;
				break;
			}
			else
			{
				unordered_map<string, double> ref = refA[index].getMaladiesPotentielles();
				unordered_map<string, double>::iterator it_ref;
				it_ref= ref.begin();
				unordered_map<string, double> testA= (*it).getMaladiesPotentielles();
				unordered_map<string, double>::iterator it_test; 
				it_test= testA.begin();

				for (it_ref; it_ref != ref.end(); ++it_ref, ++it_test)
				{
					if (it_ref->first!=it_test->first || it_ref->second!=it_test->second)
					{
						estReussi = false;
						break;
					}
				
				}

			}
		}

		if (estReussi)
		{
			nbTestsUnitairesValides++;
			cout << "Le test faire une analyse a reussi." << endl;
		}
		else
		{
			cout << "Le test faire une analyse a echoue." << endl;
		}
		return estReussi;
	}

	///////////////////////////////////////Test fonctionnels de classe Medecin


	void Test::testEmpreinteSaine(Medecin m, vector<Patient> &liste, string nomFichier, Patient p, unordered_map<int, Maladie> &lm) {
		cout << "----------- Test Faire Analyse d'une Empreinte saine -----------" << endl;


		m.chargerEmpreinte(nomFichier, liste);

		bool estReussi = false;
		for (vector<Patient>::iterator it = liste.begin(); it != liste.end(); it++)
		{

			if (p.getIdPersonne() == it->getIdPersonne()) {
				list <Empreinte> le = it->getEmpreintes();


				list <Analyse> la = m.faireAnalyse(*it, lm, false);

				Analyse a = la.back();


				unordered_map <string, double> maladiesPots = a.getMaladiesPotentielles();

				for (unordered_map <string, double>::iterator it2 = maladiesPots.begin(); it2 != maladiesPots.end(); it2++) {

					if (it2->first == "sain" && ((it2->second) - 1)<0.01) {
						estReussi = true;
						

					}
				}

			}
		}

		if (estReussi == true) {
			nbTestsFonctionnelsValides++;
			cout << "Le test d'analyse d'empreinte saine est reussi." << endl;
		}
		else {
			cout << "Le test d'analyse d'empreinte saine a echoue." << endl;
		}

	}

	bool Test::testAjouterPatienfonct(Medecin medecin, Initialisation i)
	{
		cout << "----------Debut de test fonctionnel : AjouterPatient----------" << endl;
		Patient p("test1", "test2", "test3");
		int tailleAv = i.getListePatient().size();
		i.setPatient(p);
		if (i.getListePatient().size() == tailleAv + 1)
		{
			cout << "----------Fin de test fonctionnel : AjouterPatient----------" << endl;
			cout << "Le test AjouterPatienfonct est reussi" << endl;
			nbTestsFonctionnelsValides++;
			return true;
			
		}
		cout << "----------Fin de test fonctionnel : AjouterPatient----------" << endl;
		return false;
		
	}

	bool Test::testAjouterPatienErreurfonct(Medecin medecin, Initialisation i)
	{

		cout << "----------Debut de test fonctionnel : AjouterPatient----------" << endl;
		Patient p;
		int tailleAv = i.getListePatient().size();
		i.setPatient(p);
		if (i.getListePatient().size() == tailleAv + 1)
		{
			cout << "----------Fin de test fonctionnel : AjouterPatient----------" << endl;
			return false;
		}
		cout << "----------Fin de test fonctionnel : AjouterPatient----------" << endl;
		nbTestsFonctionnelsValides++;
		cout << "Le test AjouterPatienErreurfonct est reussi" << endl;
		return true;
	}


	///////////////////////////////////////Test fonctionnels de classe Initialisation
	bool Test::testAfficherMaladies(unordered_map<int, Maladie> &m)
	{
		cout << "----------Debut de test fonctionnel : AfficherMaladies----------" << endl;
		if (m.size() != 0 && m.begin()->second.getListeAttribut().size() != 0)
		{
			cout << "----------Fin de test fonctionnel : AfficherMaladies----------" << endl;
			
			nbTestsFonctionnelsValides++;
			cout << "Le test AfficherMaladies est reussi" << endl;
			return true;
		}
		cout << "----------Fin de test fonctionnel : AfficherMaladies----------" << endl;
		return false;
	}

	bool Test::seConnecterMauvaisMdp(vector <Medecin> liste, string n, string m, string p, string motDePasse) {

		Medecin med(n, m, p, motDePasse);
		bool estCo=med.seConnecter(liste);

		if (estCo == true) {
			cout<<"Le medecin n'a pas le bon id ou mdp, il ne peut pas se connecter au service, test reussi." << endl;
			nbTestsFonctionnelsValides++;
		}
		else {

			cout << "Le medecin a pu se connecter alors que ses informations ne sont pas correctes, test echoue." << endl;
		}
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
		
			nbTestsFonctionnelsValides++;
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
				nbTestsFonctionnelsValides++;
			}
		}
		liste = b.getMaladiesPotentielles();
		for (it = liste.begin(); it != liste.end(); ++it)
		{
			if (it->second < 0.5)
			{
				cout << "----------Fin de test fonctionnel : Alert pour analyses supplementaires----------" << endl;
				return true;
				nbTestsFonctionnelsValides++;
			}
		}
		liste = c.getMaladiesPotentielles();
		for (it = liste.begin(); it != liste.end(); ++it)
		{
			if (it->second < 0.5)
			{
				cout << "----------Fin de test fonctionnel : Alert pour analyses supplementaires----------" << endl;
				return true;
				nbTestsFonctionnelsValides++;
			}
		}

		cout << "----------Fin de test fonctionnel : Alert pour analyses supplementaires----------" << endl;
		return false;
	}

	bool Test::testAlertAnalysesupplementairesPlusieursEmpreintes(Initialisation i)
	{
		cout << "----------Debut de test fonctionnel : Alert pour analyses supplementaires- pour plusieurs empreintes---------" << endl;

		vector<Empreinte> ve;

		ve.push_back(Empreinte("AA;25;131;147"));
		ve.push_back(Empreinte("AA;149;-11.;161"));
		ve.push_back(Empreinte("AA;-41;11;182"));
		ve.push_back(Empreinte("AT;75;84;221"));
		ve.push_back(Empreinte("AT;79;90;149"));
		ve.push_back(Empreinte("AT;-5;147;124"));
		ve.push_back(Empreinte("AT;164;29;139"));
		ve.push_back(Empreinte("AA;76;131;182"));
		ve.push_back(Empreinte("AA;172;201;149"));
		ve.push_back(Empreinte("Toto;182,201,149"));
		unordered_map<string, double>::iterator it;
		unordered_map <string, double> liste;

		for (int p(0); p < ve.size(); p++)
		{
			Analyse a;
			a.analyseEmpreinte(ve[p], i.getListeMaladie());
			 liste= a.getMaladiesPotentielles();
			 cout << a << endl;
			for (it = liste.begin(); it != liste.end(); ++it)
			{
				if (it->second < 0.5)
				{
					cout << "----------Fin de test fonctionnel : Alert pour analyses supplementaires- pour plusieurs empreintes---------" << endl;
					return true;
					nbTestsFonctionnelsValides++;
				}
			}
		}

		cout << "----------Fin de test fonctionnel : Alert pour analyses supplementaires- pour plusieurs empreintes---------" << endl;
		return false;

	}

	///////////////////////////////////////////////////Test non fonctionnels
	bool Test::testVitesse(Initialisation i)
	{
		cout << "----------Debut de test non fonctionnel : Verification de progression lineaire en temps d'initialisation---------" << endl;
		string fichierTest = "fichierTest";
		time_t t_deb = clock();
		i.init("fichierTest1.txt");
		time_t t_fin = clock();
		int duree = t_fin - t_deb;

		for (int j(2); j < 11;j++)
		{
			fichierTest += to_string(j) + ".txt";
			t_deb = clock();
			i.init(fichierTest);
			t_fin = clock();
			if (3 * duree < t_fin - t_deb)
			{
				return false;
			}
			duree = t_fin - t_deb;
			fichierTest = "fichierTest";
		}

		cout << "----------Fin de test non fonctionnel : Verification de progression lineaire en temps d'initialisation---------" << endl;
		return true;
		nbTestsFonctionnelsValides++;
	}

	bool Test::testReutilisabilite(Initialisation i)
	{
		cout << "----------Debut de test non fonctionnel : Reutilisabilite en fonction de differents nombre d'attributs---------" << endl;
		Empreinte e1("AT;102;63");
		Empreinte e2("AT;102;63;215;5");
		Analyse a1;
		a1.analyseEmpreinte(e1, i.getListeMaladie());

		Analyse a2;
		a2.analyseEmpreinte(e2, i.getListeMaladie());

		if ((a1.getMaladiesPotentielles().size() > 0 && a1.getMaladiesPotentielles().begin()->second > 0) && (a2.getMaladiesPotentielles().size() > 0 && a2.getMaladiesPotentielles().begin()->second > 0))
		{
			return true;
			nbTestsFonctionnelsValides++;
		}
		else
		{
			return false;
		}

		cout << "----------Fin de test non fonctionnel : Reutilisabilite en fonction de differents nombre d'attributs---------" << endl;
	}