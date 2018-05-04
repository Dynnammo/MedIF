#pragma once
#pragma once
/*************************************************************************
${file_base}  -  description
-------------------
début                : ${date}
copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <${file_base}> (fichier ${file_name}) ------
#if ! defined ( Patient_H )
#define PATIENT_H

#include "Personne.h"
#include "Patient.h"
#include <string>
#include <iostream>
#include <list>

using namespace std;


//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <${file_base}>
//
//
//------------------------------------------------------------------------ 

class Medecin : Personne
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques

	bool seConnecter(int id, string mp);
	void seDeconnecter();
	Patient ajouterPatient(string n, string p, string m);
	list <Analyse> faireAnalyse(Patient p);
	Analyse rechercherAnalyse(int id);
	void afficherMaladie(list <Maladie> lm);
	void mesurerPatient(Patient p, string nomFichier);

	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//


	//------------------------------------------------- Surcharge d'opérateurs

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
	// Mode d'emploi :

	// Contrat :
	//

	virtual ~ Medecin() {}

	// Mode d'emploi :
	//
	// Contrat :
	//

	//------------------------------------------------------------------ PRIVE 

protected:
	//----------------------------------------------------- Méthodes protégées

private:
	void afficherAnalyse(list <Analyse>);
	//------------------------------------------------------- Méthodes privées

protected:
	//----------------------------------------------------- Attributs protégés


private:
	//------------------------------------------------------- Attributs privés
	string mdp;
	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes privées

	//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <${file_base}>

#endif // XXX_H
#pragma once
