/*************************************************************************
Attribut_intervalle  -  description
-------------------
d�but                : 27.04.2018
copyright            : (C) 2018 par Tifenn FLOCH
									Anatolii GASIUK
									L�o PAPE
									Baptiste THIVEND
e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Attribut_intervalle> (fichier Attribut_intervalle.h) ----------------
#if ! defined ( Attribut_intervalle_H )
#define Attribut_intervalle_H

//--------------------------------------------------- Interfaces utilis�es
#include "Attribut.h"
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Attribut_intervalle>
//
//
//------------------------------------------------------------------------

class Attribut_intervalle : public Attribut
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
	// type M�thode ( liste de param�tres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	double getBorneSup();
	// Mode d'emploi :
	//
	// Contrat :
	//

	double getBorneInf();
	// Mode d'emploi :
	//
	// Contrat :
	//

	double getMoyenne();
	// Mode d'emploi :
	//
	// Contrat :
	//

	int getIdAttribut();
	// Mode d'emploi :
	//
	// Contrat :
	//

	void setBorneSup(double sup);
	// Mode d'emploi :
	//
	// Contrat :
	//

	void setBorneInf(double inf);
	// Mode d'emploi :
	//
	// Contrat :
	//

	void setMoyenne(double moy);
	// Mode d'emploi :
	//
	// Contrat :
	//

	bool verification(double valeur);
	//------------------------------------------------- Surcharge d'op�rateurs
	Attribut_intervalle & operator = (const Attribut_intervalle & unAttribut_intervalle);
	// Mode d'emploi :
	//
	// Contrat :
	//

	ostream& afficher(ostream &flux);
	// Mode d'emploi :
	//
	// Contrat :
	//

	//-------------------------------------------- Constructeurs - destructeur
	Attribut_intervalle(const Attribut_intervalle & unAttribut_intervalle);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Attribut_intervalle();
	// Mode d'emploi :
	//
	// Contrat :
	//

	Attribut_intervalle(string nom, int id, double borneS, double borneI, double moy);
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Attribut_intervalle();
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

	double borneSup;
	double borneInf;
	double moyenne;

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s

};

//---------------------------------------------- Types d�pendants de <Attribut_intervalle>

#endif // Attribut_intervalle_H

