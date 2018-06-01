/*************************************************************************
Initialisation  -  description
-------------------
début                : 27.04.2018
copyright            : (C) 2018 par Tifenn FLOCH
									Anatolii GASIUK
									Léo PAPE
									Baptiste THIVEND
e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Initialisation> (fichier Initialisation.h) ----------------
#if ! defined ( INITIALISATION_H )
#define INITIALISATION_H

//--------------------------------------------------- Interfaces utilisees
#include "Maladie.h"
#include "Patient.h"
#include "Medecin.h"

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

//------------------------------------------------------------------------
// Role de la classe <Initialisation>
//
//
//------------------------------------------------------------------------

class Initialisation
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Methodes publiques
	
	void init(string nomFichier);
	// Mode d'emploi :
	//
	// Contrat :
	//

	void initMedecin(string nomFichier);
	// Mode d'emploi :
	//
	// Contrat :
	//

	unordered_map<int, Maladie>& getListeMaladie();
	// Mode d'emploi :
	//
	// Contrat :
	//

	Patient getPatient(int id);
	// Mode d'emploi :
	//
	// Contrat :
	//

	void setPatient(Patient p);
	// Mode d'emploi :
	//
	// Contrat :
	//

	vector<Medecin> getListeMedecin();
	// Mode d'emploi :
	//
	// Contrat :
	//
	
	vector<Patient> getListePatient();
	// Mode d'emploi :
	//
	// Contrat :
	//

	void afficherMedecin();
	// Mode d'emploi :
	//
	// Contrat :
	//

	void afficherPatient();
	// Mode d'emploi :
	//
	// Contrat :
	//

	//------------------------------------------------- Surcharge d'op�rateurs
	Initialisation & operator = (const Initialisation & unInitialisation);
	// Mode d'emploi :
	//
	// Contrat :
	//


	//-------------------------------------------- Constructeurs - destructeur
	Initialisation(const Initialisation & unInitialisation);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Initialisation();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Initialisation();
	// Mode d'emploi :
	//
	// Contrat :
	//

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Methodes protegees

private:
	//------------------------------------------------------- Methodes privees
    vector<string> split(string &lignef, string del);
protected:
	//----------------------------------------------------- Attributs proteges

private:
	//------------------------------------------------------- Attributs prives
	vector<Medecin> listeMedecin;
	vector<Patient> listePatient;
	unordered_map <int, Maladie> mapMaladie;
	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes privees

	//----------------------------------------------------------- Types prives

};

//---------------------------------------------- Types dependants de <Initialisation>

#endif // Initialisation_H

