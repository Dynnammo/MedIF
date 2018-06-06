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
#if ! defined ( MEDECIN_H )
#define MEDECIN_H

#include <string>
#include <iostream>
#include <list>

#include "Personne.h"
#include "Patient.h"
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

class Medecin : public Personne
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques

	bool seConnecter(vector<Medecin>);
	void seDeconnecter();
	Patient ajouterPatient(std::string n, std::string p, std::string m, vector <Patient> &patients);
	list <Analyse> faireAnalyse(Patient &p, unordered_map<int, Maladie> &lm);
	Analyse rechercherAnalyse(int id, Patient &p);
    void afficherMaladies(list <Maladie> lm);
	//void afficherAnalyse(Patient p);
	void mesurerPatient(std::string mesures, Patient &p);
	void chargerEmpreinte(std::string nomFichier, vector<Patient> &liste);

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
	Medecin & operator = (const Medecin & unMedecin);
	
	friend ostream &operator<<(ostream &os, const Medecin &m);
	//-------------------------------------------- Constructeurs - destructeur

	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//
	Medecin(const Medecin &m);

	Medecin();


	Medecin(std::string n, std::string m, std::string p, std::string motDePasse);

	virtual ~ Medecin();

	// Mode d'emploi :
	//
	// Contrat :
	//

	//------------------------------------------------------------------ PRIVE 

protected:
	//----------------------------------------------------- M�thodes prot�g�es

private:
	void afficherAnalyse(Patient p);
	//------------------------------------------------------- M�thodes priv�es

protected:
	//----------------------------------------------------- Attributs prot�g�s


private:
	//------------------------------------------------------- Attributs priv�s
	std::string mdp;
	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Medecin>

#endif // MEDECIN_H