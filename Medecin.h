#pragma once
#pragma once
/*************************************************************************
${file_base}  -  description
-------------------
d�but                : ${date}
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


//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <${file_base}>
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
	list <Analyse> faireAnalyse(Patient p);
	Analyse rechercherAnalyse(int id);
	void afficherMaladie(list <Maladie> lm);
	void mesurerPatient(Patient p, string nomFichier);

	// type M�thode ( liste de param�tres );
	// Mode d'emploi :
	//
	// Contrat :
	//


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

//----------------------------------------- Types d�pendants de <${file_base}>

#endif // XXX_H
#pragma once
