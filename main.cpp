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
void appelTestSeConnecter(Initialisation ini, Test t, Medecin m) {

	ini.initMedecin("MedecinIni.txt");

	vector <Medecin> medecins = ini.getListeMedecin();
	
	t.testSeConnecter(m, medecins);
}

void appelTestMesurerPatient(Initialisation ini, Test t, Medecin m, Patient p) {
	


	string mesures = "1;True;2.12;13;3.156;1236";

	t.testMesurerPatient(mesures, p, m);
	

}

int main()
{
	Test t;
	Initialisation i;
	i.initMedecin("fichierMedecin.txt");
	Medecin m("Guittat", "Clement", "clement.guittat@insa-lyon.fr", "123");
	Patient p("Patient","Tifenn","tifenn.patient@jesuismalade.fr");
	cout << m;
	cout << p;
	i.afficherMedecin();
	i.afficherPatient();
	cout << "Fin du programme"<<endl;
	//m.faireAnalyse()
	//t.testSeConnecter("MedecinIni.txt", m);
	Initialisation i;
}