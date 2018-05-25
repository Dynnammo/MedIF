/*************************************************************************
Maladie  -  description
-------------------
début                : 27.04.2018
copyright            : (C) 2018 par Tifenn FLOCH
									Anatolii GASIUK
									Léo PAPE
									Baptiste THIVEND
e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Maladie> (fichier Maladie.h) ----------------
#if ! defined ( Maladie_H )
#define Maladie_H

//--------------------------------------------------- Interfaces utilisées

#include <iostream>
#include "Attribut.h"
#include "Attribut_enumeration.h"
#include "Attribut_intervalle.h"
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Maladie>
//
//
//------------------------------------------------------------------------

class Maladie
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	void ajouterAttribut(Attribut *attribut);
	// Mode d'emploi :
	//
	// Contrat :
	//

	int getIdMaladie();
	// Mode d'emploi :
	//
	// Contrat :
	//

	vector<Attribut*> getListeAttribut();
	// Mode d'emploi :
	//
	// Contrat :
	//

	//------------------------------------------------- Surcharge d'opérateurs
	Maladie & operator = (const Maladie & unMaladie);
	// Mode d'emploi :
	//
	// Contrat :
	//

	friend ostream& operator<<(ostream &flux, Maladie const& maladie);
	// Mode d'emploi :
	//
	// Contrat :
	//


	//-------------------------------------------- Constructeurs - destructeur
	Maladie(const Maladie & unMaladie);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Maladie();
	// Mode d'emploi :
	//
	// Contrat :
	//

	Maladie(int ad);
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Maladie();
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
	int idMaladie;
	vector<Attribut*> listeAttribut;

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes privées

	//----------------------------------------------------------- Types privés

};

//---------------------------------------------- Types dépendants de <Maladie>

#endif // Maladie_H

