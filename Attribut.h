/*************************************************************************
Attribut  -  description
-------------------
d�but                : 27.04.2018
copyright            : (C) 2018 par Tifenn FLOCH
									Anatolii GASIUK
									L�o PAPE
									Baptiste THIVEND
e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Attribut> (fichier Attribut.h) ----------------
#if ! defined ( ATTRIBUT_H )
#define ATTRIBUT_H

//--------------------------------------------------- Interfaces utilis�es
#include <iostream>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Attribut>
//
//
//------------------------------------------------------------------------

class Attribut
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
	// type M�thode ( liste de param�tres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual int getIdAttribut();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual bool verification(string valeur);

	virtual bool verification(double valeur);


	//------------------------------------------------- Surcharge d'op�rateurs
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

	Attribut(int id, string nom);
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
	//----------------------------------------------------- M�thodes prot�g�es

private:
	//------------------------------------------------------- M�thodes priv�es

protected:
	//----------------------------------------------------- Attributs prot�g�s
	int idAttribut;
	string nomAttribut;

private:
	//------------------------------------------------------- Attributs priv�s



	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s

};

//---------------------------------------------- Types d�pendants de <Attribut>

#endif // Attribut_H

