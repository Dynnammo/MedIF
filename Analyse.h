/*************************************************************************
Analyse  -  description
-------------------
début                : 27.04.2018
copyright            : (C) 2018 par Tifenn FLOCH
                                    Anatolii GASIUK
                                    Léo PAPE
                                    Baptiste THIVEND
e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Analyse> (fichier Analyse.h) ----------------
#if ! defined ( ANALYSE_H )
#define ANALYSE_H

//-------------------------------------------------------- Include système
#include<unordered_map>
#include<string>

using namespace std;

//--------------------------------------------------- Interfaces utilisées
#include "Maladie.h"
#include "Empreinte.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Analyse>
//
//
//------------------------------------------------------------------------

class Analyse
{
//----------------------------------------------------------------- PUBLIC

public:

//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

	void analyseEmpreinte(Empreinte e, unordered_map <int, Maladie> &mapMaladie);
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	//------------------------------------------------------ Getters - Setters
	int getId();

	unordered_map<string, double> getMaladiesPotentielles() const;

//------------------------------------------------- Surcharge d'opérateurs
    friend ostream & operator << (ostream & out, const Analyse & a);

	Analyse & operator =( Analyse const &a);

//-------------------------------------------- Constructeurs - destructeur
    Analyse ( const Analyse & unAnalyse );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Analyse ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Analyse ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    int idAnalyse;
	unordered_map<string, double> maladiesPotentielles;
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Analyse>

#endif // Analyse_H

