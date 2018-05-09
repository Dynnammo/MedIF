/*************************************************************************
Initialisation  -  description
-------------------
d�but                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Initialisation> (fichier Initialisation.h) ----------------
#if ! defined ( Initialisation_H )
#define Initialisation_H

//--------------------------------------------------- Interfaces utilis�es
#include "Maladie.h"
#include "Patient.h"
#include "Medecin.h"
#include <vector>
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Initialisation>
//
//
//------------------------------------------------------------------------

class Initialisation
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
	
	void init(string nomFichier);
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
	//----------------------------------------------------- M�thodes prot�g�es

private:
	//------------------------------------------------------- M�thodes priv�es

protected:
	//----------------------------------------------------- Attributs prot�g�s

private:
	//------------------------------------------------------- Attributs priv�s

	vector<Maladie> listeMaladie();
	vector<Medecin> listeMedecin();
	vector<Patient> listePatient();

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s

};

//---------------------------------------------- Types d�pendants de <Initialisation>

#endif // Initialisation_H

