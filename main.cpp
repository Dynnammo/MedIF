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
#include <string>

#include "Attribut.h"
#include "Attribut_enumeration.h"
#include "Attribut_intervalle.h"
#include "Maladie.h"
#include "Medecin.h"
#include "Initialisation.h"
#include "Test.h"



using namespace std;


int main()
{

	Test t;

	Medecin m("Guittat", "Clement", "clement.guittat@insa-lyon.fr", "123");
	t.testSeConnecter("MedecinIni.txt", m);
	/*i.init("test2.txt");
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
	int a;
	cin >> a;
	return 0;
}