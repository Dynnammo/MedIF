#ifndef MENU_H
#define MENU_H

#include "Initialisation.h"
#include "Medecin.h"
#include "Patient.h"
#include "Test.h"

class Menu
{
public :
    static void menuPrincipal();

private:
    static void menuTest();
    static void menuAppli();
    static void menuAjoutPatient(Medecin m, vector<Patient> &listePatients);
    static void menuMesurerPatient(Medecin m, vector<Patient> &listePatients);
    static void menuFaireAnalyse(Medecin m, unordered_map<int, Maladie> &lm);
    static void menuRechercherAnalyse(Initialisation i, Medecin m);
    static void menuAfficherMaladie(Initialisation i, Medecin m);
	static void appelTestSeConnecter(Initialisation ini, Test t, Medecin m);
	static void appelTestMesurerPatient(Test &t, Medecin m, Patient &p);
	static void appelTestAjouterPatient(Test &t, Medecin m, Initialisation i);
	static void appelTestChargerEmpreinte(Initialisation ini, Test &t, Medecin m, Patient &p);
	static void appelTestRechercherAnalyse(Test &t, Patient &p, Medecin m);
	static void appelTestFaireAnalyse(Test &t, Medecin m, Initialisation i);
	static void appelTestEmpreinteSaine(Test &t, Medecin m, Patient &p, Initialisation i);
	static void appelSeConnecterMauvaisMdp(Test &t, Initialisation ini);
};


#endif // MENU_H

