/*************************************************************************
Maladie  -  description
-------------------
d�but                : 27.04.2018
copyright            : (C) 2018 par Tifenn FLOCH
									Anatolii GASIUK
									L�o PAPE
									Baptiste THIVEND
e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Maladie> (fichier Maladie.h) ----------------
#if ! defined ( Maladie_H )
#define Maladie_H

//--------------------------------------------------- Interfaces utilis�es

#include <iostream>
#include "Attribut.h"
#include "Attribut_enumeration.h"
#include "Attribut_intervalle.h"
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Maladie>
//
//
//------------------------------------------------------------------------

class Maladie
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
	// type M�thode ( liste de param�tres );
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

	//------------------------------------------------- Surcharge d'op�rateurs
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
	//----------------------------------------------------- M�thodes prot�g�es

private:
	//------------------------------------------------------- M�thodes priv�es

protected:
	//----------------------------------------------------- Attributs prot�g�s

private:
	//------------------------------------------------------- Attributs priv�s
	int idMaladie;
	vector<Attribut*> listeAttribut;

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s

};

//---------------------------------------------- Types d�pendants de <Maladie>

#endif // Maladie_H

