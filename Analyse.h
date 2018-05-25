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
#if ! defined ( Analyse_H )
#define Analyse_H

using namespace std;

//--------------------------------------------------- Interfaces utilisées
#include<unordered_map>
#include<string>
#include "Maladie.h"
#include "Empreinte.h"
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
static  int idA = 0;
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

	unordered_map<string,double> getMaladiesPotentielles();
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	Analyse analyseEmpreinte(Empreinte  e, unordered_map<int, Maladie> lm);
	int getId();
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//



//------------------------------------------------- Surcharge d'opérateurs
    friend ostream & operator << (ostream & out, Analyse & a);

	Analyse & operator =(Analyse a);

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

