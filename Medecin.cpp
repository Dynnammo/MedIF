/*************************************************************************
Medecin  -  description
-------------------     
<<<<<<< HEAD
dï¿½but                : 27.04.2018
=======
début                : 27.04.2018
>>>>>>> 870942ccdf807d0da48bd030eb9f48ceb3916ae8
copyright            : (C) 2018 par Tifenn FLOCH
									Anatolii GASIUK
									Lï¿½o PAPE
									Baptiste THIVEND
e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- Rï¿½alisation de la classe <Medecin> (fichier Medecin.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systï¿½me
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Medecin.h"
//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Mï¿½thodes publiques

bool Medecin::seConnecter(vector<Medecin> liste)
{
	bool estConnecte = false;
	
	for (vector<Medecin>::const_iterator it = liste.cbegin(); it != liste.cend(); it++) {

		if (it->mdp == this->mdp && it->mail==this->mail) {
			estConnecte = true;
		}
	}

	return estConnecte;
}

void Medecin::seDeconnecter()
{
	this->~Medecin();
}

Patient Medecin::ajouterPatient(string n, string p, string m, vector <Patient> &patients) 
{
	
	Patient patient (n, p, m);
	patients.push_back(patient);
	
	return patient;
}


list<Analyse> Medecin::faireAnalyse(Patient p, unordered_map<int, Maladie> &lm)
{
	list <Empreinte> le = p.getEmpreintes();
	Analyse a;
	for (list<Empreinte>::const_iterator it = le.cbegin(); it != le.cend(); it++) {

		a.analyseEmpreinte(*it,lm);
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
		cout << *it << endl;
	}
}

void Medecin::afficherAnalyse(Patient p) {
	list<Analyse> liste = p.getAnalyses();
	Analyse tmp;
	for (list<Analyse>::const_iterator it = liste.cbegin(); it != liste.cend(); it++) {
		tmp = *it;
		cout << tmp;
	}

}

void Medecin::mesurerPatient(string mesures, Patient &p) {

	Empreinte e(mesures);
	p.setEmpreintes(e);

}

void Medecin::chargerEmpreinte(string nomFichier, list <Patient> liste) { //changer diagramme uml

	ifstream fichier(nomFichier, ios::in);  // on ouvre en lecture

	if (fichier)  // si l'ouverture a fonctionnï¿½
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
			line.erase(0, pos + 1); //j'enlï¿½ve l'id du patient de l'Empreinte
			cout << "test pour voir si l'idP est bon :" << idP;
			cout << "test pour voir si line est bon :" << line;
			for (list<Patient>::const_iterator it = liste.cbegin(); it != liste.cend(); it++) {
				p = *it;
				test = stoi(idP, &sz); //convertit l'id du Patient de string ï¿½ int
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
// type ${file_base}::Mï¿½thode ( liste de paramï¿½tres )
// Algorithme :
//
//{
//} //----- Fin de Mï¿½thode

//------------------------------------------------------ Getters - Setters


//------------------------------------------------- Surcharge d'opï¿½rateurs
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

ostream &operator<< (ostream &os, const Medecin &m){
	os << "Medecin" << endl;
	os << m.nom <<endl;
	os << m.prenom <<endl;
	os<< m.mdp <<endl;
	return os;
}

//-------------------------------------------- Constructeurs - destructeur


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Mï¿½thodes protï¿½gï¿½es

  //------------------------------------------------------- Mï¿½thodes privï¿½es
