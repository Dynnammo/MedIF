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

//-------------------------------------------------------- Include système
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

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
	//------------------------------------------------------ Getters - Setters
	string getMesures() const;

	//------------------------------------------------- Surcharge d'op�rateurs
	Empreinte & operator = (const Empreinte & uneEmpreinte);

	friend ostream & operator << (ostream & out, const Empreinte & e);

	//-------------------------------------------- Constructeurs - destructeur
	Empreinte(string m);

	Empreinte(const Empreinte & unEmpreinte);

	virtual ~Empreinte();


	//------------------------------------------------------- Attributs publics

	int idEmpreinte;

//------------------------------------------------------------------ PRIVE
private:
	//------------------------------------------------------- Attributs priv�s 
	string mesures;
};
#endif // EMPREINTE_H