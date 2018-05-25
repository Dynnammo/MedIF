/*************************************************************************
Initialisation  -  description
-------------------
d�but                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : anatoliigasiuk@insa-lyon.fr
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
#include <unordered_map>
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

	void initMedesin(string nomFichier);
	// Mode d'emploi :
	//
	// Contrat :
	//

	unordered_map<int, Maladie> getListeMaladie();
	// Mode d'emploi :
	//
	// Contrat :
	//

	Patient getPatient(string id);
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
	vector<string> Initialisation::split(string &lignef, string del);
protected:
	//----------------------------------------------------- Attributs prot�g�s

private:
	//------------------------------------------------------- Attributs priv�s
	vector<Medecin> listeMedecin;
	vector<Patient> listePatient;
	unordered_map <int, Maladie> mapMaladie;
	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s

};

//---------------------------------------------- Types d�pendants de <Initialisation>

#endif // Initialisation_H

