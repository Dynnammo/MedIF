#pragma once
#pragma once
/*************************************************************************
${file_base}  -  description
-------------------
d�but                : ${date}
copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <${file_base}> (fichier ${file_name}) ------
#if ! defined ( Empreinte_H )
#define EMPREINTE_H


#include <string>
#include <iostream>
#include <fstream>


using namespace std;


//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
static int id = 0;
//------------------------------------------------------------------------ 
// R�le de la classe <${file_base}>
//
//
//------------------------------------------------------------------------ 

class Empreinte 
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
	//----------------------------------------------------- M�thodes prot�g�es

private:
	//------------------------------------------------------- M�thodes priv�es

public:
 int idEmpreinte;
protected:
	//----------------------------------------------------- Attributs prot�g�s


private:
	//------------------------------------------------------- Attributs priv�s
	//static int idEmpreinte; 
	string mesures;
	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <${file_base}>

#endif // XXX_H
#pragma once
