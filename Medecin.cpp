

/*************************************************************************
${file_base}  -  description
-------------------
d�but                : ${date}
copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <${file_base}> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <iostream>
using namespace std;


//------------------------------------------------------ Include personnel
#include "Medecin.h"
#include "Initialisation.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques

bool Medecin::seConnecter(int id, string mdp) {
	Initialisation ini();
	bool estConnecte = false;
	list<Medecin> liste = ini.getListeMedecin();
	
	for (list<Medecin>::const_iterator it = liste.cbegin(); it != liste.cend(); it++) {

		if (it->mdp == mdp && it->idPersonne==id) {
			estConnecte = true;
		}
	}

	return estConnecte;
}



Patient Medecin::ajouterPatient(string n, string p, string m) {
	Initialisation ini();
	Patient patient (n, p, m);

	ini.setPatient(patient);
	return patient;

}


list <Analyse>Medecin:: faireAnalyse(Patient p, list <Maladie> lm) {
	list <Empreinte> le = p.getEmpreintes();

	Analyse a;
	for (list<Empreinte>::const_iterator it = le.cbegin(); it != le.cend(); it++) {

		a = a.analyseEmpreinte(*it);
		p.setAnalyses(a);
	}

}


Analyse Medecin:: rechercherAnalyse(int id, Patient p) {

	list <Analyse> liste= p.getAnalyses();
	Analyse a;
	for (list<Analyse>::const_iterator it = liste.cbegin(); it != liste.cend(); it++) {

		if (it.getidAnalyse == id) {

			a = *it;
		}

	}

	return a;
	
}


// type ${file_base}::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode


//------------------------------------------------- Surcharge d'op�rateurs


//-------------------------------------------- Constructeurs - destructeur


// Algorithme :
//



 //----- Fin de ${file_base}


 //----- Fin de ~${file_base}


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- M�thodes prot�g�es

  //------------------------------------------------------- M�thodes priv�es
