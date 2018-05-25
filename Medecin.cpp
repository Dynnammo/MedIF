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

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


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
	this.~Medecin();
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

		a = a.analyseEmpreinte(*it,ini.getListeMaladie());
		p.setAnalyses(a);
	}

}


Analyse Medecin:: rechercherAnalyse(int id, Patient p) {

	list <Analyse> liste= p.getAnalyses();
	Analyse a;
	Analyse tmp;

	for (list<Analyse>::const_iterator it = liste.cbegin(); it != liste.cend(); it++) {

		tmp = *it;

		
		if (a.getId() == id) {

			a = *it;
		}

>>>>>>> aa25d10153cf67111a4718b3ed0e016802a33ef9
	}
}

<<<<<<< HEAD
void Medecin::afficherMaladies(list <Maladie> lm)
{
	for (list<Maladie>::const_iterator it = lm.cbegin(); it != lm.cend(); it++)
	{
		
	}
=======
	return a;
	
>>>>>>> aa25d10153cf67111a4718b3ed0e016802a33ef9
}


// type ${file_base}::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------------ Getters - Setters


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées

  //------------------------------------------------------- Méthodes privées
