#pragma once
#pragma once
/*************************************************************************
Empreinte  -  description
-------------------
début                : 27.04.2018
copyright            : (C) 2018 par Tifenn FLOCH
									Anatolii GASIUK
									Léo PAPE
									Baptiste THIVEND
e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Empreinte> (fichier empreinte.h) ------
#if ! defined ( Empreinte_H )
#define EMPREINTE_H


#include <string>
#include <iostream>
#include <fstream>


using namespace std;


//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
static int id = 0;
//------------------------------------------------------------------------ 
// Rôle de la classe <Empreinte>
//
//
//------------------------------------------------------------------------ 

class Empreinte 
{
	//----------------------------------------------------------------- PUBLIC

public:
	
	//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//
	// Contrat :


	//


	//------------------------------------------------- Surcharge d'opérateurs

	// Mode d'emploi :
	//
	// Contrat :
	//
	Empreinte & operator = (const Empreinte & uneEmpreinte)
	// Algorithme :
	//
	{
		this->idEmpreinte = uneEmpreinte.idEmpreinte;
		return *this;
	} //----- Fin de operator =

	//-------------------------------------------- Constructeurs - destructeur

	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//
	Empreinte(string m) :mesures(m) 
	{
#ifdef MAP
		cout << "Appel au constructeur de <Empreinte>" << endl;
#endif
	}
	// Mode d'emploi :

	// Contrat :
	//

	virtual ~Empreinte()
		// Algorithme :
		//
	{
		id--;
#ifdef MAP
		cout << "Appel au destructeur de <Empreinte>" << endl;
#endif
	} //----- Fin de ~Empreinte

	// Mode d'emploi :
	//
	// Contrat :
	//

	//------------------------------------------------------------------ PRIVE 

protected:
	//----------------------------------------------------- Méthodes protégées

private:
	//------------------------------------------------------- Méthodes privées

public:
 int idEmpreinte;
protected:
	//----------------------------------------------------- Attributs protégés


private:
	//------------------------------------------------------- Attributs privés
	//static int idEmpreinte; 
	string mesures;
	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes privées

	//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Empreinte>

#endif // EMPREINTE_H
#pragma once
