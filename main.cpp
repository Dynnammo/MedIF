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
#include "Menu.h"

using namespace std;

static int id;



int main()
{
	
	id = 0;
	/* Initialisation des variables indispensable a tous les tests*/
	/*Test t;
	Initialisation i;
	Medecin m("Guittat", "Clement", "clement.guittat@insa-lyon.fr", "123");
	Patient p("Patient", "Tifenn", "tifenn.patient@jesuismalade.fr");
	Empreinte e("AT;102;63;215");
	p.setEmpreintes(e);
	cout << "Voici le medecin que nous allons utiliser : " << endl;
	cout << m;
	cout << "Voici le patient que nous allons utiliser : " << endl;
	cout << p;
	cout << endl;*/

	// test pour vérifier que l'initialisation des maladie renvoie une erreur s'il y a un problème avec le fichier
	//t.testInitialisation("fichierErrone.txt", i);

	// test pour vérifier que l'initialisation se passe correctement
	//t.testInitialisation("initMaladie.txt", i);

	//test pour vérifier que l'on charge correctement les empreintes
	//appelTestChargerEmpreinte(i, t, m, p);

	// test pour vérifier que l'initialisation des medecins renvoie une erreur s'il y a un problème avec le fichier
	//t.testInitialisationMedecin("fichierErrone.txt", i);

	// test pour vérifier que l'initialisation des medecins se passe correctement
	//t.testInitialisationMedecin("MedecinIni.txt", i);

	// test pour vérifier que analyse d'empreinte se passe correctement
	//t.testAnalyseEmpreinte(e, i.getListeMaladie());


	// test pour vérifier qu'un patient est bien ajouté à la liste du médecin qui l'ajoute
	//appelTestAjouterPatient(t, m, i);

	// test pour vérifier qu'un Medecin puisse se connecter.
	//appelTestSeConnecter(i, t,m);

	// test qui vérifie que les empreintes d'un patient sont bien analysées
	//appelTestFaireAnalyse(t, m, i);

	//test pour vérifier que l'empreinte est ajoutee au patient
	//appelTestMesurerPatient( t, m,p);

	

	//test pour vérifier que la methode split fonctionne correctement
	//t.testSplit("A.Z.E.R.T.Y.TEST;.Q.W.E.R.T.Y",".");

	//test pour rechercherAnalyse
	//appelTestRechercherAnalyse(t, p, m);
	//cout << "Nombre de tests unitaires passes avec succes: " << t.nbTestsUnitairesValides << endl;
	//testfonctionnel 2.1:

	//appelTestEmpreinteSaine(t, m, p, i);
	//cout << "Fin du programme" << endl;
	
	//-------------------------------------- Test fonctionnelles 

	//f.1  Test Verification de chargement d'empreinte(s) erronées
	//t.testChargerEmpreinteFausse(m,"fichierTestEmpreinteFausse.txt");
	//t.testChargerEmpreintesErronee(m,"fichierTestChargerEmpreintes.txt");

	//f.2 Test faire Analyse pour une ou plusieurs empreintes
	//t.testFaireAnalysefonc(m, i.getListeMaladie(), false); //pour une empreinte
	//t.testFaireAnalysefonc(m, i.getListeMaladie(), true); //pour plusieurs empreintes

	//f.4 - f.3  Test afficher/description les maladies
	//t.testAfficherMaladies(i.getListeMaladie());

	//f.5 Test créer Maladie
	//t.testCreerMaladie("uneMaladie.txt");
	//t.testCreerMaladie("desMaladies.txt");
	//t.testCreerMaladie("maladieSansAttribut.txt");
	
	//f.6 Test alert pour analyses supplémentaires
	//t.testAlertAnalysesupplementaires(i); // pour une empreinte : sain, malade, pas de resultat
	//t.testAlertAnalysesupplementairesPlusieursEmpreintes(i); // pour plusieurs empreintes


	//f.7 Test Pour ajouter Patien
	//t.testAjouterPatienfonct(m, i);
	//t.testAjouterPatienErreurfonct(m, i);


	//f.8 Test connecter Medecin
	//t.testConnecterMedecin(m, i.getListeMedecin());

	//-----------------------------------Tests non fonctionnels
	//Test  manipulation fichier
	//t.testCreerMaladieErreur(".tt.sxt");  //test non fonctionnel - mauvais format
	//t.testCreerMaladieErreur("fichierVide.txt"); //test non fonctionnel - fichier vide

	//Test Reutilisabilite d'application avec different nombre d'attribut dans l'empreinte mais dans l'ordre
	//t.testReutilisabilite(i);

	//Test Verification de vitesse d'initialisation
	//t.testVitesse(i);

	Menu m;
	m.menuPrincipal();
	//system("PAUSE");

	cout << endl;
	cout << endl;
	cout << endl;
	//cout << "Nombre de tests fonctionnels passes avec succes: " << t.nbTestsFonctionnelsValides << endl;


	///---------------------------------------------------------------------------------Tests Systemes

	//Test charger une empreinte erronée
	//t.testChargerEmpreinteFausse(m, "fichierTestEmpreinteFausse.txt");

	//t.testSysteme1(m, i.getListeMedecin(), i.getListePatient(), i.getListeMaladie(),false);
	
	system("PAUSE");
	return 0;
}
