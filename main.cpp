#include "Attribut.h"
#include "Attribut_enumeration.h"
#include "Attribut_intervalle.h"
#include "Maladie.h"
#include <iostream>
#include "Initialisation.h"

using namespace std;

int main()
{
	string test = "bonjour";
	string test2 = "coucou";
	vector<string> testVec;
	testVec.push_back(test);
	testVec.push_back(test2);
	Maladie mal;
	Attribut_enumeration Ae(0,5, testVec);
	Attribut_intervalle Ai(1, 5.36, 4.0, 1);
	mal.ajouterAttribut(&Ae);
	mal.ajouterAttribut(&Ai);
	cout << mal;
	Initialisation i;
	i.init("test.txt");
	

	return 0;
}