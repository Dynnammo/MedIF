#pragma once
#pragma once
/*************************************************************************
${file_base}  -  description
-------------------
début                : ${date}
copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <${file_base}> (fichier ${file_name}) ------
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
// Rôle de la classe <${file_base}>
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


	//-------------------------------------------- Constructeurs - destructeur

	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//
	Empreinte( string nomFichier);
	// Mode d'emploi :

	// Contrat :
	//

	virtual ~Empreinte();

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

//----------------------------------------- Types dépendants de <${file_base}>

#endif // XXX_H
#pragma once
