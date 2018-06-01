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
	/*Initialisation i;

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
	cout << a << endl;*/

	// TEST DE VITESSE
	/*vector<string> vec;

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
	return 0;*/
}