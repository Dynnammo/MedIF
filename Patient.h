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
#include <string>
#include <iostream>
#include <list>
#include "Empreinte.h"

using namespace std;


//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <${file_base}>
//
//
//------------------------------------------------------------------------ 

class Patient  :public Personne
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	void Afficher() {

		cout << nom << " " << prenom;
	}
	/*list <Analyse> getAnalyses() {

		return la;
	}*/

	list <Empreinte> getEmpreintes() {

		return le;
	}
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
	Patient(){}

	Patient(string n, string p, string m) {

		nom = n;	
		prenom = p;
		m = m;
	}


	
	// Mode d'emploi :
	
	// Contrat :
	//

	virtual ~Patient() {}
		
	// Mode d'emploi :
	//
	// Contrat :
	//

	//------------------------------------------------------------------ PRIVE 

protected:
	//----------------------------------------------------- Méthodes protégées

private:
	//------------------------------------------------------- Méthodes privées

protected:
	//----------------------------------------------------- Attributs protégés
	

private:
	//------------------------------------------------------- Attributs privés
	//list <Analyse> la;
	list <Empreinte> le;
	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes privées

	//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <${file_base}>

#endif // XXX_H
