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

#include "Attribut.h"
#include "Attribut_enumeration.h"
#include "Attribut_intervalle.h"
#include "Maladie.h"
#include "Medecin.h"
#include "Initialisation.h"
#include "Test.h"

using namespace std;

vector<string> split(string lignef, string del)
{
	// Algorithme :
	//
	vector<string> reponse;
	int pos = 0;
	while (pos != -1)
	{
		pos = lignef.find(del);
		reponse.push_back(lignef.substr(0, pos));
		lignef.erase(0, pos + 1);
	}
	return reponse;
}

int main()
{

	/*Test t;

	Medecin m("Guittat", "Clement", "clement.guittat@insa-lyon.fr", "123");
	//t.testSeConnecter("MedecinIni.txt", m);
	Initialisation i;

	i.init("test2.txt");
	ifstream lecture("test3.txt");
	string ligne;

	getline(lecture, ligne);
	Empreinte e(ligne);

	Analyse a;
	unordered_map <string, double> maladies;
	unordered_map <int, Maladie> maladies2= i.getListeMaladie();

	for (int j(0); j < maladies2.size(); j++)
	{
	cout << i.getListeMaladie()[j] << endl;
	}

	a.analyseEmpreinte(e, i.getListeMaladie());
	cout << a << endl;
	vector<string> vec;

	string test = "A.Z.E.R.T.Y.A.Z.E.R.T.Y.G";
	time_t init = time(0);
	for (int i(0); i < 5000000; i++)
	{
	vec = split(test, ".");
	}
	time_t init2 = time(0);
	cout << init2 - init << endl;

	time_t tvec2 = time(0);
	vector<string> vec2(13);
	int p = 0;
	for (int k(0); k < 5000000; k++)
	{
	for (istringstream iss(test);;)
	{
	string item;
	getline(iss, item, '.');
	if (iss.fail()) break;
	vec2[p]=item;
	p++;
	}
	p = 0;
	}
	time_t tvec22 = time(0);
	cout << tvec22 - tvec2 << endl;
	*/
}
vector<string> split(string lignef, string del)
{
	// Algorithme :
	//
	vector<string> reponse;
	int pos = 0;
	while (pos != -1)
	{
		pos = lignef.find(del);
		reponse.push_back(lignef.substr(0, pos));
		lignef.erase(0, pos + 1);
	}
	return reponse;
}

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
	ini.setPatient(p2);
	vector <Patient> liste = ini.getListePatient();
	t.testChargerEmpreinte(nomFichier, liste , m,ini);

}
int main()
{
	/* Initialisation des variables indispensable a tous les tests*/
	Test t;
	Initialisation i;
	i.initMedecin("fichierMedecin.txt");
	Medecin m("Guittat", "Clement", "clement.guittat@insa-lyon.fr", "123");
	Patient p("Patient", "Tifenn", "tifenn.patient@jesuismalade.fr");
	cout << m;
	cout << p;
	i.afficherMedecin();
	i.afficherPatient();

	// test pour vérifier qu'un patient est bien ajouté à la liste du médecin qui l'ajoute
	//appelTestAjouterPatient(t, m, i);

	// test pour vérifier qu'un Medecin puisse se connecter.
	//appelTestSeConnecter(i, t,m);

	// test qui vérifie que les empreintes d'un patient sont bien analysées
	//appelTestFaireAnalyse(t, m, p, i);

	//test pour vérifier que l'empreinte est ajoutee au patient
	//appelTestMesurerPatient( t, m,p);

	//test pour vérifier que l'on charge correctement les empreintes
	appelTestChargerEmpreinte(i, t, m,p);

	cout << "Fin du programme" << endl;
	// pour eviter que la fenetre se ferme dans la foulee, un cin inutile
	string a;
	cin >> a;
	return 0;
}
