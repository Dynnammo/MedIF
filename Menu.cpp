// ------------------------------------- INCLUDE SYSTEME
#include <iostream>
#include <vector>

using namespace std;
// ------------------------------------- INCLUDE PERSONNEL
#include "Menu.h"
#include "Initialisation.h"
#include "Medecin.h"
#include "Test.h"

static Initialisation i;
void Menu::menuPrincipal()
{

    cout << "Bienvenue dans l'application Med'IF !" << endl;
    cout << "Si vous souhaitez effectuer des tests, tapez 1." << endl;
    cout << "Si vous etes medecin et souhaitez utiliser l'application, tapez 0." << endl;
    int test;
    cin >> test;
    cout << test << endl;

    if(test)
        menuTest();
    else
        menuAppli();
}

void Menu::menuTest()
{
	DEBUT:
	cout << "Quels tests souhaitez vous effectuer?" << endl;
	cout << "0 - tests unitaires" << endl;
	cout << "1 - tests fonctionnels" << endl;
	cout << "2 - tests non fonctionnels" << endl;
	cout << "3 - Quitter l'application" << endl;
	int test;
	cin >> test;
	cout << test << endl;
	/* Initialisation des variables indispensable a tous les tests*/
	Test t;
	Medecin m("Guittat", "Clement", "clement.guittat@insa-lyon.fr", "123");
	Patient p("Patient", "Tifenn", "tifenn.patient@jesuismalade.fr");
	Empreinte e("AT;102;63;215");
	p.setEmpreintes(e);
	static int id;
	id = 0;
	switch (test)
	{
		case 0:
		{
			cout << "----------------Debuts des tests unitaires---------------" << endl << endl << endl;

			// test pour vérifier que l'initialisation des maladie renvoie une erreur s'il y a un problème avec le fichier
			t.testInitialisationFausse("fichierErrone.txt", i);
			cout << endl << endl << endl;

			// test pour vérifier que l'initialisation se passe correctement
			t.testInitialisation("initMaladie.txt", i);
			cout << endl << endl << endl;

			//test pour vérifier que l'on charge correctement les empreintes
			appelTestChargerEmpreinte(i, t, m, p);
			cout << endl << endl << endl;

			// test pour vérifier que l'initialisation des medecins renvoie une erreur s'il y a un problème avec le fichier
			t.testInitialisationMedecinFaux("fichierErrone.txt", i);
			cout << endl << endl << endl;

			// test pour vérifier que l'initialisation des medecins se passe correctement
			t.testInitialisationMedecin("MedecinIni.txt", i);
			cout << endl << endl << endl;

			// test pour vérifier que analyse d'empreinte se passe correctement
			t.testAnalyseEmpreinte(e, i.getListeMaladie());
			cout << endl << endl << endl;

			appelTestEmpreinteSaine(t, m, p, i);

			// test pour vérifier qu'un patient est bien ajouté à la liste du médecin qui l'ajoute
			appelTestAjouterPatient(t, m, i);
			cout << endl << endl << endl;

			// test pour vérifier qu'un Medecin puisse se connecter.
			appelTestSeConnecter(i, t,m);
			cout << endl << endl << endl;

			// test qui vérifie que les empreintes d'un patient sont bien analysées
			appelTestFaireAnalyse(t, m, i);
			cout << endl << endl << endl;

			//test pour vérifier que l'empreinte est ajoutee au patient
			appelTestMesurerPatient( t, m,p);
			cout << endl << endl << endl;



			//test pour vérifier que la methode split fonctionne correctement
			t.testSplit("A.Z.E.R.T.Y.TEST;.Q.W.E.R.T.Y",".");
			cout << endl << endl << endl;


			//test pour rechercherAnalyse
			appelTestRechercherAnalyse(t, p, m);
			cout << endl << endl << endl;
			cout << "Nombre de tests unitaires passes avec succes: " << t.nbTestsUnitairesValides << " / 12" << endl << endl;

			i.getListeMedecin().clear();
			i.getListePatient().clear();
			break;
		}

		case 1: 
		{
			cout << "----------------Debut de tests fonctionnels--------------------" << endl << endl << endl;
			i.init("initMaladie.txt");
			i.initMedecin("MedecinIni.txt");

			//f.1  Test Verification de chargement d'empreinte(s) erronées
			t.testChargerEmpreinteFausse(m,"fichierTestEmpreinteFausse.txt");
			cout << endl << endl << endl;
			t.testChargerEmpreintesErronee(m,"fichierTestChargerEmpreintes.txt");
			cout << endl << endl << endl;

			//f.2 Test faire Analyse pour une ou plusieurs empreintes
			t.testFaireAnalysefonc(m, i.getListeMaladie(), false); //pour une empreinte
			cout << endl << endl << endl;
			t.testFaireAnalysefonc(m, i.getListeMaladie(), true); //pour plusieurs empreintes
			cout << endl << endl << endl;

			//f.4 - f.3  Test afficher/description les maladies
			t.testAfficherMaladies(i.getListeMaladie());
			cout << endl << endl << endl;

			//f.5 Test créer Maladie
			t.testCreerMaladie("uneMaladie.txt");
			cout << endl << endl << endl;
			t.testCreerMaladie("desMaladies.txt");
			cout << endl << endl << endl;
			t.testCreerMaladie("maladieSansAttribut.txt");
			cout << endl << endl << endl;

			//f.6 Test alert pour analyses supplémentaires
			t.testAlertAnalysesupplementaires(i); // pour une empreinte : sain, malade, pas de resultat
			cout << endl << endl << endl;
			t.testAlertAnalysesupplementairesPlusieursEmpreintes(i); // pour plusieurs empreintes
			cout << endl << endl << endl;


			//f.7 Test Pour ajouter Patien
			t.testAjouterPatienfonct(m, i);
			cout << endl << endl << endl;
			t.testAjouterPatienErreurfonct(m, i);
			cout << endl << endl << endl;


			//f.8 Test connecter Medecin
			t.testConnecterMedecin(m, i.getListeMedecin());
			cout << endl << endl << endl;

			cout << "Nombre de tests fonctionnels passes avec succes: " << t.nbTestsFonctionnelsValides << " / 13" << endl << endl;
			i.getListeMedecin().clear();
			i.getListePatient().clear();
			break;
		}

		case 2:
		{
			cout << "----------------Debuts des tests non fonctionnels---------------" << endl << endl << endl;
			i.init("initMaladie.txt");
			//Test  manipulation fichier
			t.testCreerMaladieErreur(".tt.sxt");  //test non fonctionnel - mauvais format
			cout << endl << endl << endl;
			t.testCreerMaladieErreur("fichierVide.txt"); //test non fonctionnel - fichier vide
			cout << endl << endl << endl;

			//Test Reutilisabilite d'application avec different nombre d'attribut dans l'empreinte mais dans l'ordre
			t.testReutilisabilite(i);
			cout << endl << endl << endl;

			//Test Verification de vitesse d'initialisation
			t.testVitesse(i);
			cout << endl << endl << endl;

			cout << "Nombre de tests non fonctionnels passes avec succes: " << t.nbTestsNonFonctionnelsValides << " / 4" << endl << endl;

			i.getListeMedecin().clear();
			i.getListePatient().clear();
			break;
		}

		case 3:
		{
			return;
			break;
		}

		default :
		{
			cout << "L'option rentrée ne pas conforme aux choix présents" << endl;
			cout << "Veuillez recommencer : " << endl;
			goto DEBUT;
		}
	}

}

void Menu::appelTestSeConnecter(Initialisation ini, Test t, Medecin m)
{
	ini.initMedecin("MedecinIni.txt");

	vector <Medecin> medecins = ini.getListeMedecin();

	t.testSeConnecter(m, medecins);
}

void Menu::appelTestMesurerPatient(Test &t, Medecin m, Patient &p) {

	string mesures = "1;True;2.12;13;3.156;1236";

	t.testMesurerPatient(mesures, p, m);
}

void Menu::appelTestAjouterPatient(Test &t, Medecin m, Initialisation i)
{
	vector <Patient> listeP = i.getListePatient();
	t.testAjouterPatient(m, listeP);
}

void Menu::appelTestChargerEmpreinte(Initialisation ini, Test &t, Medecin m, Patient &p) {

	string nomFichier = "Mesures.txt";
	ini.setPatient(p);
	Patient p1("Janson", "Clay", "clay.janson@gmail.com");
	ini.setPatient(p1);
	Patient p2("Padilla", "Tonny", "tonny.padilla@gmail.com");

	Patient p3("Thivend", "Baptiste", "baptiste.thivend@gmail.com");
	ini.setPatient(p2);
	ini.setPatient(p3);
	vector <Patient> liste = ini.getListePatient();
	t.testChargerEmpreinte(nomFichier, liste, m);

}

void Menu::appelTestRechercherAnalyse(Test &t, Patient &p, Medecin m) {

	Analyse a;
	//Analyse b;
	//Analyse c;

	p.setAnalyses(a);
	//p.setAnalyses(b);
	//p.setAnalyses(c);




	t.testRechercherAnalyse(p, m);

}

void Menu::appelTestFaireAnalyse(Test &t, Medecin m, Initialisation i)
{
	unordered_map<int, Maladie> lm = i.getListeMaladie();
	t.testFaireAnalyse(m, lm, false);
}

////////////////////////////////////////fonction test fonctionnels


void Menu::appelTestEmpreinteSaine(Test &t, Medecin m, Patient &p, Initialisation i) {
	unordered_map<int, Maladie> lm = i.getListeMaladie();

	string nomFichier = "SaneMeasurement.txt";
	i.setPatient(p);
	vector <Patient> liste = i.getListePatient();
	t.testEmpreinteSaine(m, liste, nomFichier, p, lm);
}

void Menu::appelSeConnecterMauvaisMdp(Test &t, Initialisation ini) {
	ini.initMedecin("MedecinIni.txt");

	vector <Medecin> medecins = ini.getListeMedecin();
	string nom = "Dicaprio";
	string prenom = "Leonardo";
	string mail = "leonardo.dicaprio@gmail.com";
	string mdp = "101112";
	bool testReussi = t.seConnecterMauvaisMdp(medecins, nom, mail, prenom, mdp);

	if (testReussi == true) {
		cout << "Le test est reussi" << endl;
	}
	else {
		cout << "Le test a echoue" << endl;
	}
}


void Menu::menuAppli()
{
    cout << "Vous etes bien arrive dans l'application Med'IF." << endl;
    cout << "Comme ceci est la premiere fois que l'application est lancée, elle doit être initialisee." << endl;
    cout << "Avec quel fichier souhaitez-vous faire l'initialisation ? Merci d'écrire le nom complet du fichier." << endl;
    string nomFichier;
    cin >> nomFichier;
    i.init(nomFichier);
    i.initMedecin("fichierMedecin.txt");
    i.afficherMedecin();
    
    cout << "Pour continuer votre aventure, veuillez vous connecter, s'il vous plait." << endl;
    cout << "Votre adresse mail : ";
    string mailMedecin;
    cin >> mailMedecin;
    cout << "Votre mot de passe : ";
    string mdpMedecin;
    cin >> mdpMedecin;
    Medecin m("Don't care", mailMedecin,"Don't care", mdpMedecin);
    vector<Medecin> listeMedecins = i.getListeMedecin();
    unordered_map<int, Maladie> lm = i.getListeMaladie();
    //if (m.seConnecter(listeMedecins))
    {
        int option=0;
        while (option != 6)
        {
            cout << "Vous etes bien connecte a notre plateforme." << endl;
            cout << "Que souhaitez-vous faire maintenant ?" << endl;
            cout << "Veuillez choisir l'option qui vous convient : " << endl;
            cout << "---------------------------------------------" << endl;
            cout << "1. Enregistrer un nouveau patient" << endl;
            cout << "2. Effectuer les mesures sur un patient" << endl;
            cout << "3. Effectuer l'analyse d'une ou plusieurs empreintes" << endl;
            cout << "4. Rechercher une analyse" << endl;
            cout << "5. Afficher la liste des maladies enregistrees" << endl;
            cout << "6. Vous deconnecter" << endl;
            cout << "---------------------------------------------" << endl;
            cin >> option;

            switch (option)
            {
            case 1:
                menuAjoutPatient(m, i.getListePatient());
                break;
            case 2:
                menuMesurerPatient(m, i.getListePatient());
                break;
            case 3:
                menuFaireAnalyse(m, i.getListeMaladie());
                break;
            case 4:
                menuRechercherAnalyse(i, m);
                break;
            case 5:
                menuAfficherMaladie(i, m);
                break;
            case 6:
                m.seDeconnecter();
                cout << "A la revoyure !";
                break;
            default:
                cout << "Il semblerait que vous n'ayez pas choisi une option qui existe. Nous tacherons d'y remedier un jour...";
                break;
            }
        }
    }
    //else
    {
        cout << "Vous n'etes pas inscrit dans notre base de donnees ou il y a une erreur dans mail ou mot de passe. Veuillez contacter votre service informatique pour plus d'informations." << endl;
    }
}

void Menu::menuAjoutPatient(Medecin m, vector<Patient> &listePatients)
{
    AJOUT:
    cout << "Vous avez choisi d'enregistrer un nouveau patient." << endl;
    string nomPatient;
    string prenomPatient;
    string mailPatient;
    cout << "Veuillez entrer son nom : ";
    cin >> nomPatient;
    cout << "Veuillez entrer son prenom : ";
    cin >> prenomPatient;
    cout << "Veuillez entrer son adresse mail : ";
    cin >> mailPatient;
    Patient p(nomPatient, prenomPatient, mailPatient);
    i.setPatient(p);
    i.afficherPatient();
    cout << "Patient bien ajoute." << endl;
    cout << "Voulez-vous en ajouter un autre (Y/N)?" << endl;
    CHOIX: string rajout;cin >>rajout;
    if (rajout == "Y"){
        goto AJOUT;
    } else if (rajout == "N") {
        cout << "=======================>>> Retour au menu" << endl;
    } else {
        cout << "Mauvaise entrée" << endl;
        goto CHOIX;
    }    
}

void Menu::menuMesurerPatient(Medecin m, vector<Patient> &listePatients)
{
    cout << "Vous avez choisi de faire les mesures de vos patients." << endl;
    cout << "Veuillez entrer le nom du fichier correspondant au mesures du capteur : ";
    string nomFichier;
    cin >> nomFichier;
    m.chargerEmpreinte(nomFichier, listePatients);
    
    for(int i = 0; i < listePatients.size(); i++)
    {
        cout <<listePatients[i].getIdPersonne()<<endl;
        listePatients[i].afficherEmpreinte();
    }
    

    cout << "Les empreintes ont bien ete enregistrees pour les patients." << endl;
    cout << "=======================>>> Retour au menu" << endl;
}

void Menu::menuFaireAnalyse(Medecin m, unordered_map<int, Maladie> &lm)
{
    
    for(int it =0; it < i.getListePatient().size(); it++)
    {
        cout << i.getListePatient()[it].getIdPersonne();
        i.getListePatient()[it].afficherEmpreinte();
    }
    
    cout << "Vous avez choisi d'effectuer l'analyse d'empreintes." << endl;
    cout << "Veuillez entrer l'id du patient : " << endl;
    int idPatient;
    cin >> idPatient;
    Patient p = i.getPatient(idPatient);
    p.afficherEmpreinte();
    

    list<Analyse> listeAnalyse = m.faireAnalyse(p, lm,true);
    
    for(list<Analyse>::iterator it = listeAnalyse.begin(); it != listeAnalyse.end(); it++)
    {
        cout << *it;
    }
    
    cout << "L'analyse est terminee. Voulez-vous la voir ? (Y/N) ";
    string afficher;
    cin >> afficher;
    if (afficher=="Y")
    {
        for (list<Analyse>::const_iterator it = listeAnalyse.cbegin(); it != listeAnalyse.cend(); it++) {
            cout << *it << endl;
        }
    }
    cout << "=======================>>> Retour au menu" << endl;
}

void Menu::menuRechercherAnalyse(Initialisation i, Medecin m)
{
    if (i.getListePatient().size() == 0) {
        cout << "Vous n'avez aucun patient, donc aucune analyse" <<endl;
        return;
    }
    cout << "Vous avez choisi de rechercher une analyse." << endl;
    cout << "Veuillez entrer l'id du patient dont vous voulez rechercher l'analyse: ";
    i.afficherPatient();
    int idPatient;
    cin >> idPatient;
    Patient p = i.getPatient(idPatient);
    p.afficherAnalyse();
    cout << "Veuillez entrer l'id de l'analyse que vous recherchez : ";
    int idAnalyse;
    cin >> idAnalyse;
    cout << "Voici ce que nous avons trouve : " << endl;
    Analyse a = m.rechercherAnalyse(idAnalyse, p);
    cout << a << endl;
    cout << "=======================>>> Retour au menu" << endl;
}

void Menu::menuAfficherMaladie(Initialisation i, Medecin m)
{
    cout << "Vous avez choisi d'afficher la liste des maladies enregistrees." << endl;
    unordered_map <int, Maladie> listeMaladies = i.getListeMaladie();
    m.afficherMaladies(listeMaladies);
    cout << "=======================>>> Retour au menu" << endl;
}
