/*************************************************************************
                           Initialisation  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Initialisation> (fichier Initialisation.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <vector>

//------------------------------------------------------ Include personnel
#include "Initialisation.h"
#include "Maladie.h"
#include "medecin.h"
#include "patient.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe
vector<Maladie> listeMaladie;
vector<Medecin> listeMedecin;
vector<Patient> listePatient;
//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type ${file_base}::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Initialisation::init(string nomFichier)
// Algorithme :
//
{

} //----- Fin de Méthode




//------------------------------------------------- Surcharge d'opérateurs
Initialisation & Initialisation::operator = ( const Initialisation & unInitialisation )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Initialisation::Initialisation ( const Initialisation & unInitialisation )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Initialisation>" << endl;
#endif
} //----- Fin de Initialisation (constructeur de copie)


Initialisation::Initialisation ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Initialisation>" << endl;
#endif
} //----- Fin de Initialisation


Initialisation::~Initialisation ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Initialisation>" << endl;
#endif
} //----- Fin de ~Initialisation


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

