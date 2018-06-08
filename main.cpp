/*************************************************************************
main  -  description
-------------------
début                : 27.04.2018
copyright            : (C) 2018 par Tifenn FLOCH
									Anatolii GASIUK
									Léo PAPE
									Baptiste THIVEND
e-mail               : @insa-lyon.fr
*************************************************************************/
#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <sstream>
#include <stdlib.h>

#include "Attribut.h"
#include "Attribut_enumeration.h"
#include "Attribut_intervalle.h"
#include "Maladie.h"
#include "Medecin.h"
#include "Initialisation.h"
#include "Test.h"

using namespace std;

static int id;

void appelTestSeConnecter(Initialisation ini, Test t, Medecin m)
{
	ini.initMedecin("MedecinIni.txt");

	vector <Medecin> medecins = ini.getListeMedecin();
	
	t.testSeConnecter(m, medecins);
}

void appelTestMesurerPatient( Test t, Medecin m, Patient p) {
	
	string mesures = "1;True;2.12;13;3.156;1236";

	t.testMesurerPatient(mesures, p, m);
}

void appelTestAjouterPatient(Test t, Medecin m, Initialisation i)
{
	vector <Patient> listeP = i.getListePatient();
	t.testAjouterPatient(m, listeP);
}

void appelTestChargerEmpreinte(Initialisation ini, Test t, Medecin m,Patient p) {
	
	string nomFichier = "Mesures.txt";
	ini.setPatient(p);
	Patient p1("Janson", "Clay", "clay.janson@gmail.com");
	ini.setPatient(p1);
	Patient p2("Padilla", "Tonny", "tonny.padilla@gmail.com");

	Patient p3("Thivend", "Baptiste", "baptiste.thivend@gmail.com");
	ini.setPatient(p2);
	ini.setPatient(p3);
	vector <Patient> liste = ini.getListePatient();
	t.testChargerEmpreinte(nomFichier, liste , m);

}

void appelTestRechercherAnalyse(Test t, Patient p, Medecin m) {

	Analyse a;
	Analyse b;
	Analyse c;

	p.setAnalyses(a);
	p.setAnalyses(b);
	p.setAnalyses(c);
		
	list <Analyse> liste = p.getAnalyses();

	for (list<Analyse>::iterator it = liste.begin(); it != liste.end(); it++)
	{
		t.testRechercherAnalyse(p, m);
	}
}

void appelTestFaireAnalyse(Test t, Medecin m, Initialisation i)
{
	unordered_map<int, Maladie> lm = i.getListeMaladie();
	t.testFaireAnalyse(m, lm, false);
}

////////////////////////////////////////fonction test fonctionnels
void afficherMaladie(Maladie m)
{
	cout << m << endl;
}

void appelTestEmpreinteSaine(Test t, Medecin m, Patient p, Initialisation i) {
	unordered_map<int, Maladie> lm = i.getListeMaladie();

	string nomFichier = "SaneMeasurement.txt";
	i.setPatient(p);
	vector <Patient> liste = i.getListePatient();
	t.testEmpreinteSaine(m, liste, nomFichier, p, lm);
}

void appelSeConnecterMauvaisMdp(Test t,Initialisation ini ) {
	ini.initMedecin("MedecinIni.txt");

	vector <Medecin> medecins = ini.getListeMedecin();
	string nom = "Dicaprio";
	string prenom = "Leonardo";
	string mail = "leonardo.dicaprio@gmail.com";
	string mdp = "101112";
	bool testReussi=t.seConnecterMauvaisMdp(medecins, nom, mail, prenom,mdp);

	if (testReussi == true) {
		cout << "Le test est reussi" << endl;
	}
	else {
		cout << "Le test a echoue" << endl;
	}
}

int main()
{
	id = 0;
	/* Initialisation des variables indispensable a tous les tests*/
	Test t;
	Initialisation i;
	Medecin m("Guittat", "Clement", "clement.guittat@insa-lyon.fr", "123");
	Patient p("Patient", "Tifenn", "tifenn.patient@jesuismalade.fr");
	Empreinte e("AT;102;63");
	p.setEmpreintes(e);
	cout << "Voici le medecin que nous allons utiliser : " << endl;
	cout << m;
	cout << "Voici le patient que nous allons utiliser : " << endl;
	cout << p;
	cout << endl;

	// test pour vérifier que l'initialisation des maladie renvoie une erreur s'il y a un problème avec le fichier
	//t.testInitialisation("fichierErrone.txt", i);

	// test pour vérifier que l'initialisation se passe correctement
	t.testInitialisation("initMaladie.txt", i);

	// test pour vérifier que l'initialisation des medecins renvoie une erreur s'il y a un problème avec le fichier
	//t.testInitialisationMedecin("fichierErrone.txt", i);

	// test pour vérifier que l'initialisation des medecins se passe correctement
	//t.testInitialisationMedecin("MedecinIni.txt", i);

	// test pour vérifier que analyse d'empreinte se passe correctement
	t.testAnalyseEmpreinte(e, i.getListeMaladie());


	// test pour vérifier qu'un patient est bien ajouté à la liste du médecin qui l'ajoute
	//appelTestAjouterPatient(t, m, i);

	// test pour vérifier qu'un Medecin puisse se connecter.
	//appelTestSeConnecter(i, t,m);

	// test qui vérifie que les empreintes d'un patient sont bien analysées
	//appelTestFaireAnalyse(t, m, i);

	//test pour vérifier que l'empreinte est ajoutee au patient
	//appelTestMesurerPatient( t, m,p);

	//test pour vérifier que l'on charge correctement les empreintes
	//appelTestChargerEmpreinte(i, t, m,p);

	//test pour vérifier que la methode split fonctionne correctement
	//t.testSplit("A.Z.E.R.T.Y.TEST;.Q.W.E.R.T.Y",".");

	//test pour rechercherAnalyse
	//appelTestRechercherAnalyse(t, p, m);

	//testfonctionnel 2.1:

	//appelTestEmpreinteSaine(t, m, p, i);
	cout << "Fin du programme" << endl;
	
	//-------------------------------------- Test fonctionnelles 
	//test afficher/description les maladies
	//t.testAfficherMaladies(i.getListeMaladie());

	//test afficher/description une maladies
	//afficherMaladie(i.getListeMaladie().begin()->first);

	//test créer Maladie
	// t.testCreerMaladie("uneMaladie.txt") << endl;
	//t.testCreerMaladie("desMaladies.txt") << endl;
	//t.testCreerMaladieErreur(".tt.sxt") << endl;  //test non fonctionnel - mauvais format
	//t.testCreerMaladie("maladieSansAttribut.txt");
	//t.testCreerMaladieErreur("fichierVide.txt"); //test non fonctionnel - fichier vide

	// Test alert pour analyses supplémentaires
	//t.testAlertAnalysesupplementaires(i) << endl; // pour une empreinte : sain, malade, pas de resultat
	//t.testAlertAnalysesupplementairesPlusieursEmpreintes(i); // pour plusieurs empreintes

	//Test Pour ajouter Patien
	//t.testAjouterPatienfonct(m, i);

	//Test Patien avec attribut nom ou prenom ou mail ou id manquant
	//t.testAjouterPatienErreurfonct(m, i);
	
	system("PAUSE");
	return 0;
}
