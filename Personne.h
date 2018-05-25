/*************************************************************************
Personne  -  description
-------------------
début                : 27.04.2018
copyright            : (C) 2018 par Tifenn FLOCH
									Anatolii GASIUK
									Léo PAPE
									Baptiste THIVEND
e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Personne> (fichier Personne.h) ------
#if ! defined ( PERSONNE_H )
#define PERSONNE_H

#include <string>
#include <iostream>

using namespace std;

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
static  int id1 = 0;
//------------------------------------------------------------------------ 
// Rôle de la classe <Personne>
// définit les attributs communs aux médecins et aux patients
//
//------------------------------------------------------------------------ 
class Personne
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	
	//------------------------------------------------------ Getters - Setters
	int getIdPersonne()
	{
		return idPersonne;
	}

	//------------------------------------------------- Surcharge d'opérateurs

	// Mode d'emploi :
	//
	// Contrat :
	//

	//-------------------------------------------- Constructeurs - destructeur

	// Constructeur par défaut
	Personne()
	{

	}

	// Constructeur
	Personne(string n, string p, string m)
	{
		idPersonne=id1++;
		prenom = p;
		nom = n;
		mail = m;
	}

	// Constructeur de copie
	Personne(Personne & p)
	{
		this->prenom = p.prenom;
		this->nom = p.nom;
		this->idPersonne = p.idPersonne;
		this->mail = p.mail; 
#ifdef MAP
	    cout << "Appel au constructeur de copie de <Personne>" << endl;
#endif
	}//----- Fin de Personne (constructeur de copie)

	Personne()
	{
#ifdef MAP
	    cout << "Appel au constructeur par défaut de <Personne>" << endl;
#endif
	}//----- Fin de Personne

	Personne(string n, string p, string m)
		: idPersonne(id1++), prenom(p), nom(n), mail(m)
	{
#ifdef MAP
	    cout << "Appel au constructeur de <Personne>" << endl;
#endif
	}//----- Fin de Personne

	virtual ~Personne()
	{
		id1--;
#ifdef MAP
	    cout << "Appel au destructeur de <Personne>" << endl;
#endif
	}//----- Fin de ~Personne

	//------------------------------------------------------------------ PRIVE 

protected:
	//----------------------------------------------------- Méthodes protégées

private:
	//------------------------------------------------------- Méthodes privées

protected:
	//----------------------------------------------------- Attributs protégés
	int idPersonne;
	string nom;
	string prenom;
	string mail;

private:
	//------------------------------------------------------- Attributs privés

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes privées

	//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Personne>

#endif // PERSONNE_H
