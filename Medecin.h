#pragma once
#pragma once
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

//---------- Interface de la classe <Medecin> (fichier Medecin.h) ------
#if ! defined ( Medecin_H )
#define Medecin_H

#include "Personne.h"
#include "Patient.h"
#include <string>
#include <iostream>
#include <list>
#include "Analyse.h"
#include "Maladie.h"
using namespace std;


//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <Medecin>
//
//
//------------------------------------------------------------------------ 

class Medecin : Personne
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques

	bool seConnecter(int id, string mp);
	void seDeconnecter();
	Patient ajouterPatient(string n, string p, string m);
	list <Analyse> faireAnalyse(Patient p, list <Maladie> lm);
	Analyse rechercherAnalyse(int id);
	void afficherMaladie(list <Maladie> lm);
	void mesurerPatient(Patient p, string nomFichier);
	list <Analyse> faireAnalyse(list <Maladie>, Patient p);
	void chargerEmpreinte(string nomFichier);

	// type M�thode ( liste de param�tres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	//------------------------------------------------------ Getters - Setters

	//------------------------------------------------- Surcharge d'op�rateurs

	// Mode d'emploi :
	//
	// Contrat :
	//


	//-------------------------------------------- Constructeurs - destructeur

	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//
	Medecin() {}

	Medecin(string motDePasse) :mdp(motDePasse) {}
	// Mode d'emploi :

	// Contrat :
	//

	virtual ~ Medecin();

	// Mode d'emploi :
	//
	// Contrat :
	//

	//------------------------------------------------------------------ PRIVE 

protected:
	//----------------------------------------------------- M�thodes prot�g�es

private:
	void afficherAnalyse(list <Analyse>);
	//------------------------------------------------------- M�thodes priv�es

protected:
	//----------------------------------------------------- Attributs prot�g�s


private:
	//------------------------------------------------------- Attributs priv�s
	string mdp;
	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Medecin>

#endif // MEDECIN_H
#pragma once
