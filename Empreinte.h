#pragma once
#pragma once
/*************************************************************************
Empreinte  -  description
-------------------
d�but                : 27.04.2018
copyright            : (C) 2018 par Tifenn FLOCH
									Anatolii GASIUK
									L�o PAPE
									Baptiste THIVEND
e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Empreinte> (fichier empreinte.h) ------
#if ! defined ( EMPREINTE_H )
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
// R�le de la classe <Empreinte>
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

	string getMesures() const
	{
		return mesures;
	}
	// Mode d'emploi :
	//
	// Contrat :


	//


	//------------------------------------------------- Surcharge d'op�rateurs

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

//----------------------------------------- Types d�pendants de <Empreinte>

#endif // EMPREINTE_H
#pragma once
