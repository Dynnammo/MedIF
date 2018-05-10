/*************************************************************************
Attribut_enumeration  -  description
-------------------
début                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Attribut_enumeration> (fichier Attribut_enumeration.h) ----------------
#if ! defined ( Attribut_enumeration_H )
#define Attribut_enumeration_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <string>
#include <iostream>
#include "Attribut.h"
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Attribut_enumeration>
//
//
//------------------------------------------------------------------------

class Attribut_enumeration : public Attribut
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	int getIdAttribut();
	// Mode d'emploi :
	//
	// Contrat :
	//

	int getNbValeurs();
	// Mode d'emploi :
	//
	// Contrat :
	//

	vector<string> getValeurs();
	// Mode d'emploi :
	//
	// Contrat :
	//

	void setNbValeurs(int val);
	// Mode d'emploi :
	//
	// Contrat :
	//

	void setValeur(string);
	// Mode d'emploi :
	//
	// Contrat :
	//

	//------------------------------------------------- Surcharge d'opérateurs
	Attribut_enumeration & operator = (const Attribut_enumeration & unAttribut_enumeration);
	// Mode d'emploi :
	//
	// Contrat :
	//

	ostream& afficher (ostream &flux);
	// Mode d'emploi :
	//
	// Contrat :
	//

	//-------------------------------------------- Constructeurs - destructeur
	Attribut_enumeration(const Attribut_enumeration & unAttribut_enumeration);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Attribut_enumeration();
	// Mode d'emploi :
	//
	// Contrat :
	//

	Attribut_enumeration(int id, int nbValeurs, vector<string> valeurs);
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Attribut_enumeration();
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

	int nbValeurs;
	vector<std::string> valeurs;

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes privées

	//----------------------------------------------------------- Types privés

};

//---------------------------------------------- Types dépendants de <Attribut_enumeration>

#endif // Attribut_enumeration_H

