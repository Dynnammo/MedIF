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
	string getMesures() const
	{
		return mesures;
	}

	//------------------------------------------------- Surcharge d'op�rateurs
	Empreinte & operator = (const Empreinte & uneEmpreinte)
	// Algorithme :
	//
	{
		this->idEmpreinte = uneEmpreinte.idEmpreinte;
		return *this;
	} //----- Fin de operator =

	friend std::ostream& operator <<(std::ostream&, const Empreinte&);

	//-------------------------------------------- Constructeurs - destructeur
	Empreinte(string m) :mesures(m) 
	{
#ifdef MAP
		cout << "Appel au constructeur de <Empreinte>" << endl;
#endif
	}

	virtual ~Empreinte()
		// Algorithme :
		//
	{
		id--;
#ifdef MAP
		cout << "Appel au destructeur de <Empreinte>" << endl;
#endif
	} //----- Fin de ~Empreinte


	//------------------------------------------------------- Attributs publics

	int idEmpreinte;

//------------------------------------------------------------------ PRIVE
private:
	//------------------------------------------------------- Attributs priv�s 
	string mesures;
};

ostream& operator<<(ostream &flux, const Empreinte & e)
{
	//Affichage des attributs
	flux << "idEmpreinte : " << e.idEmpreinte << " ; mesures : " << e.getMesures() << endl;
	return flux;
} //----- Fin de operator <<

#endif // EMPREINTE_H