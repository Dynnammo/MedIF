/*************************************************************************
Medecin  -  usager principal de l'application
-------------------
d�but                : 27.04.2018
copyright            : (C) 2018 par Tifenn FLOCH
									Anatolii GASIUK
									L�o PAPE
									Baptiste THIVEND
e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Medecin> (fichier Medecin.h) ------
#if ! defined ( MEDECIN_H )
#define MEDECIN_H

//--------------------------------------------------- INCLUDE SYSTEME
#include <string>
#include <iostream>
#include <list>
#include <cstdbool>

using namespace std;

//--------------------------------------------------- Interfaces utilisees
#include "Personne.h"
#include "Patient.h"
#include "Analyse.h"
#include "Maladie.h"

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Role de la classe <Medecin>
// le medecin est l'utilisateur de l'application. Il doit se connecter au debut
// et se deconnecter a la fin.
// il est charge de creer un nouveau patient, de faire les mesures d'empreintes
// et les analyses de celles-ci. Il peut aussi rechercher une analyse particuliere
// Il a aussi acces aux maladies pre-enregistrees.
//------------------------------------------------------------------------ 

class Medecin : public Personne
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Methodes publiques
	bool seConnecter(vector<Medecin>);
	// verifie que le medecin qui souhaite utiliser l'application est enregistre dans les donnnes
	void seDeconnecter();
	// detruit l'objet medecin en cours
	Patient ajouterPatient(string n, string p, string m, vector <Patient> &patients);
	// enregistrer un nouveau patient dans les donnees
	list <Analyse> faireAnalyse(Patient &p, unordered_map<int, Maladie> &lm, bool opt);
	// a partir des empreintes d'un patient, analyser ces donnees
	// pour savoir si le patient est malade
	Analyse rechercherAnalyse(int id, Patient &p);
	// permet de rechercher une analyse avec son identifiant et le patient concerne
    void afficherMaladies(unordered_map <int, Maladie> lm);
    // affiche toutes les maladies connues avec leurs symptomes
	void mesurerPatient(string mesures, Patient &p);
	// cree une empreinte avec les mesures du capteur et les associe au patient
	void chargerEmpreinte(string nomFichier, vector<Patient> &liste);
	// 	// simule l'arrivee de donnees (sous la forme d'un string) d'un capteur


	//------------------------------------------------- Surcharge d'operateurs
	Medecin & operator = (const Medecin & unMedecin);
	
	friend ostream &operator<<(ostream &os, const Medecin &m);
	
	//-------------------------------------------- Constructeurs - destructeur
	Medecin(const Medecin &m);

	Medecin();


	Medecin(string n, string m, string p, string motDePasse);

	virtual ~ Medecin();

	//------------------------------------------------------------------ PRIVE 
private:
	//----------------------------------------------------- Methodes privees
	void afficherAnalyse(Patient p);
	vector<string> split(string lignef, string del);
	//------------------------------------------------------- Attributs prives
	string mdp;

};
#endif // MEDECIN_H