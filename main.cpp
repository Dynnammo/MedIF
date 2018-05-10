#include "Attribut.h"
#include "Attribut_enumeration.h"
#include "Attribut_intervalle.h"
#include "Maladie.h"
#include <iostream>

using namespace std;

int main()
{
	string test = "bonjour";
	string test2 = "coucou";
	vector<string> testVec;
	testVec.push_back(test);
	testVec.push_back(test2);
	Maladie mal;
	Attribut_enumeration Ae(5, testVec);
	Attribut_intervalle Ai(5.36, 4.0, 1);
	mal.ajouterAttribut(&Ae);
	mal.ajouterAttribut(&Ai);
	cout << mal;

	return 0;
}