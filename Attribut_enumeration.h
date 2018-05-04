/*************************************************************************
Attribut_enumeration  -  description
-------------------
d�but                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Attribut_enumeration> (fichier Attribut_enumeration.h) ----------------
#if ! defined ( Attribut_enumeration_H )
#define Attribut_enumeration_H

//--------------------------------------------------- Interfaces utilis�es
#include <vector>
#include <string>
#include "Attribut.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Attribut_enumeration>
//
//
//------------------------------------------------------------------------

class Attribut_enumeration : public Attribut
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
	// type M�thode ( liste de param�tres );
	// Mode d'emploi :
	//
	// Contrat :
	//


	//------------------------------------------------- Surcharge d'op�rateurs
	Attribut_enumeration & operator = (const Attribut_enumeration & unAttribut_enumeration);
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

	Attribut_enumeration(int nbValeurs, string *valeurs);
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
	//----------------------------------------------------- M�thodes prot�g�es

private:
	//------------------------------------------------------- M�thodes priv�es

protected:
	//----------------------------------------------------- Attributs prot�g�s

private:
	//------------------------------------------------------- Attributs priv�s

	int nbValeurs;
	vector<string> valeurs;

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s

};

//---------------------------------------------- Types d�pendants de <Attribut_enumeration>

#endif // Attribut_enumeration_H
