/*************************************************************************
Medecin  -  description
-------------------     
d�but                : 27.04.2018
copyright            : (C) 2018 par Tifenn FLOCH
									Anatolii GASIUK
									L�o PAPE
									Baptiste THIVEND
e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- R�alisation de la classe <Medecin> (fichier Medecin.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <iostream>
#include <string>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "Medecin.h"
#include "Empreinte.h"
using namespace std;
//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques

bool Medecin::seConnecter(vector<Medecin> liste)
{
	bool estConnecte = false;
	
	for (vector<Medecin>::const_iterator it = liste.cbegin(); it != liste.cend(); it++) {

		if (it->mdp == this->mdp && it->mail==this->mail) {
			estConnecte = true;
			//break;
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


list<Analyse> Medecin::faireAnalyse(Patient &p, unordered_map<int, Maladie> &lm, bool opt)
{
	list <Empreinte> le = p.getEmpreintes();
	

	if (opt == true) {
		for (list<Empreinte>::const_iterator it = le.cbegin(); it != le.cend(); it++) {
			Analyse a;
			a.analyseEmpreinte(*it, lm);
			p.setAnalyses(a);
		}
	}
	else {
		Analyse a;
		Empreinte e = le.back();
		a.analyseEmpreinte(e, lm);
		p.setAnalyses(a);
	}

	p.viderListeEmpreintes();

	return p.getAnalyses();
}


Analyse Medecin::rechercherAnalyse(int id, Patient &p) {

	list <Analyse> liste= p.getAnalyses();
	Analyse a;
	Analyse temp;
	//cout << "voici l'id de l'analyse" << a.getId() << endl;

	for (list<Analyse>::const_iterator it = liste.cbegin(); it != liste.cend(); it++) {

		temp = *it;

		if (temp.getId() == id) {
			a = *it;
			cout << "id de l'analyse trouvee :" <<a.getId()<< endl;
			//cout << "Trouvee " << endl;
		} else {
			//cout << "Pas de resultat " << endl;
		}

	}
	return a;
}


void Medecin::afficherMaladies(unordered_map <int, Maladie> lm)
{
	for (unordered_map<int,Maladie>::const_iterator it = lm.begin(); it != lm.end(); ++it)
	{
		cout << it->second << endl;
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

void Medecin::chargerEmpreinte(string nomFichier, vector<Patient> &liste) { //changer diagramme uml

	ifstream fichier(nomFichier, ios::in);  // on ouvre en lecture

	if (fichier)  // si l'ouverture a fonctionn�
	{
		string line;
		string idP;
		int pos;
		int test;
		string::size_type sz;
		getline(fichier, line);

		vector<string> attributs;
		// on recupere les attributs de l'empreinte
		for (istringstream iss(line);;)
		{
			string item;
			getline(iss, item, ';');
			if (iss.fail()) break;
			attributs.push_back(item);
		}// on recupere les Attributs de l'empreinte en split sur ';'

		int nbrAttributs = attributs.size();
		while (getline(fichier, line)) {
			attributs.clear();
			// on recupere les attributs de chaque empreintes suivante
			for (istringstream iss(line);;)
			{
				string item;
				getline(iss, item, ';');
				if (iss.fail()) break;
				attributs.push_back(item);
			}//  en split sur ';'

			if (nbrAttributs != attributs.size())
			{
				cout << "Empreinte erronee était negligee." << endl;
			}
			else
			{
				pos = line.find(';');
				idP = line.substr(0, pos);
				line.erase(0, pos + 1); //j'enl�ve l'id du patient de l'Empreinte
				for (vector<Patient>::iterator it = liste.begin(); it != liste.end(); it++)
				{
					test = stoi(idP, &sz); //convertit l'id du Patient de string � int
					if (it->getIdPersonne() == test)
					{
						mesurerPatient(line, *it);
					}
				}
			}
		}
	}
	else {
		cerr << "Impossible d'ouvrir le fichier !" << endl;
	}
}


//------------------------------------------------------ Getters - Setters


//------------------------------------------------- Surcharge d'op�rateurs
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
	os<< m.mail <<endl;
	return os;
}

//-------------------------------------------- Constructeurs - destructeur
	Medecin::Medecin(const Medecin &m)
		:mdp(m.mdp), Personne(m.nom, m.prenom, m.mail)
	{
#ifdef MAP
   		cout << "Appel au constructeur de copie de <Medecin>" << endl;
#endif
	}

	Medecin::Medecin()	{
#ifdef MAP
   		cout << "Appel au constructeur par defaut de <Medecin>" << endl;
#endif
	} //----- Fin de Medecin

	Medecin::Medecin(string n, string m, string p, string motDePasse)
		:Personne(n, p, m), mdp(motDePasse)
	{
#ifdef MAP
    cout << "Appel au constructeur de <Medecin>" << endl;
#endif
	}
	
	Medecin::~ Medecin()
	{
#ifdef MAP
    cout << "Appel au destructeur de <Medecin>" << endl;
#endif
	} //----- Fin de ~Medecin//----- Fin de Medecin

  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- M�thodes prot�g�es

  //------------------------------------------------------- M�thodes priv�es
