/*************************************************************************
Initialisation  -  description
-------------------
début                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Initialisation> (fichier Initialisation.h) ----------------
#if ! defined ( Initialisation_H )
#define Initialisation_H

//--------------------------------------------------- Interfaces utilisées
#include "Maladie.h"
#include "Patient.h"
#include "Medecin.h"
#include <vector>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Initialisation>
//
//
//------------------------------------------------------------------------

class Initialisation : public Ancetre
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	
	void init(String nomFichier);
	// Mode d'emploi :
	//
	// Contrat :
	//


	//------------------------------------------------- Surcharge d'opérateurs
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
	//----------------------------------------------------- Méthodes protégées

private:
	//------------------------------------------------------- Méthodes privées

protected:
	//----------------------------------------------------- Attributs protégés

private:
	//------------------------------------------------------- Attributs privés

	vector<Maladie> listeMaladie();
	vector<Medecin> listeMedecin();
	vector<Patient> listePatient();

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes privées

	//----------------------------------------------------------- Types privés

};

//---------------------------------------------- Types dépendants de <Initialisation>

#endif // Initialisation_H

