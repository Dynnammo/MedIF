/*************************************************************************
Patient  -  description
-------------------
début                : 27.04.2018
copyright            : (C) 2018 par Tifenn FLOCH
									Anatolii GASIUK
									Léo PAPE
									Baptiste THIVEND
e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Patient> (fichier Patient.h) ------
#if ! defined ( Patient_H )
#define Patient_H

#include <string>
#include <iostream>
#include <list>

using namespace std;

//--------------------------------------------------- Interfaces utilisées
#include "Personne.h"
#include "Empreinte.h"
#include "Analyse.h"
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
	void afficher()
	{

		cout << nom << " " << prenom << endl;
	}


	//------------------------------------------------------ Getters - Setters
	list <Empreinte> getEmpreintes() 
	{

		return le;
	}

	list <Analyse> getAnalyses() 
	{

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

	Patient(Patient & p)
	{
		this->la = p.la;
		this->le = p.le;
#ifdef MAP
	    cout << "Appel au constructeur de copie de <Maladie>" << endl;
#endif
	}//----- Fin de Patient (constructeur de copie)

	Patient()
	{
#ifdef MAP
    	cout << "Appel au constructeur de copie de <Patient>" << endl;
#endif
	}//----- Fin de Patient

	Patient(string n, string p, string m)
		: Personne(n,p,m)
	{
#ifdef MAP
    	cout << "Appel au constructeur de <Patient>" << endl;
#endif
	}//----- Fin de Patient


	virtual ~Patient()
	{
		this->la = p.la;
		this->le = p.le;
#ifdef MAP
	    cout << "Appel au destructeur de <Patient>" << endl;
#endif
	}//----- Fin de ~Patient


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
