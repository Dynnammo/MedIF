/*************************************************************************
Medecin  -  description
-------------------
début                : 27.04.2018
copyright            : (C) 2018 par Tifenn FLOCH
									Anatolii GASIUK
									Léo PAPE
									Baptiste THIVEND
e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Medecin> (fichier Medecin.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Medecin.h"
#include "Initialisation.h"

//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

bool Medecin::seConnecter(int id, string mdp)
{
	Initialisation ini;
	bool estConnecte = false;
	vector<Medecin> liste = ini.getListeMedecin();
	
	for (vector<Medecin>::const_iterator it = liste.cbegin(); it != liste.cend(); it++) {

		if (it->mdp == mdp && it->idPersonne==id) {
			estConnecte = true;
		}
	}

	return estConnecte;
}

void Medecin::seDeconnecter()
{
	this->~Medecin();
}

Patient Medecin::ajouterPatient(string n, string p, string m) 
{
	Initialisation ini;
	Patient patient (n, p, m);

	ini.setPatient(patient);
	return patient;
}


list<Analyse> Medecin::faireAnalyse(Patient p, list <Maladie> lm)
{
	list <Empreinte> le = p.getEmpreintes();
	Initialisation ini;
	Analyse a;
	for (list<Empreinte>::const_iterator it = le.cbegin(); it != le.cend(); it++) {

		a.analyseEmpreinte(*it,ini.getListeMaladie());
		p.setAnalyses(a);
	}

	return p.getAnalyses();
}


Analyse Medecin::rechercherAnalyse(int id, Patient p) {

	list <Analyse> liste= p.getAnalyses();
	Analyse a;
	Analyse tmp;

	for (list<Analyse>::const_iterator it = liste.cbegin(); it != liste.cend(); it++) {

		tmp = *it;

		
		if (a.getId() == id) {

			a = *it;
		}


	}
	return a;
}


void Medecin::afficherMaladies(list <Maladie> lm)
{
	for (list<Maladie>::const_iterator it = lm.cbegin(); it != lm.cend(); it++)
	{
		
	}

	
}

void Medecin::afficherAnalyses(Patient p) {
	list<Analyse> liste = p.getAnalyses();
	Analyse tmp;
	for (list<Analyse>::const_iterator it = liste.cbegin(); it != liste.cend(); it++) {
		tmp = *it;
		cout << tmp;
		

	}

}

void Medecin::mesurerPatient(string mesures, Patient p) {

	Empreinte e(mesures);
	p.setEmpreintes(e);

}
void Medecin::chargerEmpreinte(string nomFichier, list <Patient> liste) { //changer diagramme uml

	ifstream fichier(nomFichier, ios::in);  // on ouvre en lecture

	if (fichier)  // si l'ouverture a fonctionné
	{
		string line;
		string idP;
		int pos;
		int test;
		Patient p;
		string::size_type sz;
		while (getline(fichier, line)) {
			pos = line.find(';');
			idP = line.substr(0,pos);
			line.erase(0, pos + 1); //j'enlève l'id du patient de l'Empreinte
			cout << "test pour voir si l'idP est bon :" << idP;
			cout << "test pour voir si line est bon :" << line;
			for (list<Patient>::const_iterator it = liste.cbegin(); it != liste.cend(); it++) {
				p = *it;
				test = stoi(idP, &sz); //convertit l'id du Patient de string à int
				if (p.getIdPersonne() == test ) {

					mesurerPatient(line, p);
				}
			}
			
		}
	}
	else {
		cerr << "Impossible d'ouvrir le fichier !" << endl;
	}
}
// type ${file_base}::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------------ Getters - Setters


//------------------------------------------------- Surcharge d'opérateurs
Medecin & Medecin::operator = ( Medecin const & unMedecin)
// Algorithme :
//
{
	this->mdp = unMedecin.mdp;
	this->prenom = unMedecin.prenom;
	this->nom = unMedecin.nom;
	this->mail = unMedecin.mail;
	return *this;
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées

  //------------------------------------------------------- Méthodes privées
