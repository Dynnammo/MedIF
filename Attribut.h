/*************************************************************************
Attribut  -  description
-------------------
début                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Attribut> (fichier Attribut.h) ----------------
#if ! defined ( Attribut_H )
#define Attribut_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Attribut>
//
//
//------------------------------------------------------------------------

class Attribut
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual int getIdAttribut();
	// Mode d'emploi :
	//
	// Contrat :
	//


	//------------------------------------------------- Surcharge d'opérateurs
	Attribut & operator = (const Attribut & unAttribut);
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ostream& afficher(ostream &flux);
	// Mode d'emploi :
	//
	// Contrat :
	//


	//-------------------------------------------- Constructeurs - destructeur
	Attribut(const Attribut & unAttribut);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Attribut();
	// Mode d'emploi :
	//
	// Contrat :
	//

	Attribut(int id);
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Attribut();
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
	int idAttribut;

private:
	//------------------------------------------------------- Attributs privés



	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes privées

	//----------------------------------------------------------- Types privés

};

//---------------------------------------------- Types dépendants de <Attribut>

#endif // Attribut_H

