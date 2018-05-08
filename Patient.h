/*************************************************************************
Patient -  description
-------------------
d�but                : 04.05.2018
copyright            : (C) 2018 par Tifenn Floch, Anatolii Gasiuk, 
									L�o Pape, Baptiste Thivend
*************************************************************************/

//---------- Interface de la classe <Patient> (fichier Patient.h) ------
#if ! defined ( Patient_H )
#define PATIENT_H

#include <string>
#include <iostream>
#include <list>

using namespace std;

//--------------------------------------------------- Interfaces utilis�es
#include "Personne.h"
#include "Empreinte.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <Patient>
//
//
//------------------------------------------------------------------------ 

class Patient : public Personne
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
	// type M�thode ( liste de param�tres );
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

	// Constructeur par d�faut
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
	//----------------------------------------------------- M�thodes prot�g�es

private:
	//------------------------------------------------------- M�thodes priv�es

protected:
	//----------------------------------------------------- Attributs prot�g�s
	

private:
	//------------------------------------------------------- Attributs priv�s
	list <Analyse> la;
	list <Empreinte> le;
	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Patient>

#endif // PATIENT_H
