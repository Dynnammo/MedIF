/*************************************************************************
Patient -  description
-------------------
début                : 04.05.2018
copyright            : (C) 2018 par Tifenn Floch, Anatolii Gasiuk, 
									Léo Pape, Baptiste Thivend
*************************************************************************/

//---------- Interface de la classe <Patient> (fichier Patient.h) ------
#if ! defined ( Patient_H )
#define PATIENT_H

#include <string>
#include <iostream>
#include <list>

using namespace std;

//--------------------------------------------------- Interfaces utilisées
#include "Personne.h"
#include "Empreinte.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Patient>
//
//
//------------------------------------------------------------------------ 

class Patient : public Personne
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	void afficher() {

		cout << nom << " " << prenom << endl;
	}


	//------------------------------------------------------ Getters - Setters
	list <Empreinte> getEmpreintes() {

		return le;
	}

	list <Analyse> getAnalyses() {

		return la;
	}

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

	// Constructeur par défaut
	Patient()
	{

	}

	// Constructeur
	Patient(string n, string p, string m) {

		nom = n;	
		prenom = p;
		m = m;
	}

	// Constructeur de copie
	Patient(Patient & p)
	{
		this.la = p.la;
		this.le = p.le;
	}

	virtual ~Patient()
	{

	}


	//------------------------------------------------------------------ PRIVE 

protected:
	//----------------------------------------------------- Méthodes protégées

private:
	//------------------------------------------------------- Méthodes privées

protected:
	//----------------------------------------------------- Attributs protégés
	

private:
	//------------------------------------------------------- Attributs privés
	list <Analyse> la;
	list <Empreinte> le;
	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes privées

	//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Patient>

#endif // PATIENT_H
