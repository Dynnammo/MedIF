/*************************************************************************
Personne
-------------------
d�but                : 27.04.2018
copyright            : (C) 2018 par Tifenn FLOCH
									Anatolii GASIUK
									L�o PAPE
									Baptiste THIVEND
e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Personne> (fichier Personne.h) ------
#if ! defined ( PERSONNE_H )
#define PERSONNE_H

#include <string>
#include <iostream>

using namespace std;

//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
static  int id1 = 0;
//------------------------------------------------------------------------ 
// R�le de la classe <Personne>
// d�finit les attributs communs aux m�decins et aux patients
//
//------------------------------------------------------------------------ 
class Personne
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
	// type M�thode ( liste de param�tres );
	// Mode d'emploi :
	//
	// Contrat :
	
	//------------------------------------------------- Surcharge d'op�rateurs
	Personne&  operator = ( Personne const &p)
	{
		this->idPersonne = p.idPersonne;
		return *this;
	} //----- Fin de operator =
	
	//------------------------------------------------------ Getters - Setters
	int getIdPersonne()
	{
		return idPersonne;
	}

	string getNom() {
		return nom;
	}

	string getPrenom() {
		return prenom;
	}

	string getMail() {
		return mail;
	}

	//-------------------------------------------- Constructeurs - destructeur
    Personne(const Personne & p)
		:prenom(p.prenom), nom(p.nom), idPersonne(p.idPersonne), mail(p.mail)
	{
#ifdef MAP
	    cout << "Appel au constructeur de copie de <Personne>" << endl;
#endif
	}//----- Fin de Personne (constructeur de copie)

    Personne()
	{
#ifdef MAP
	    cout << "Appel au constructeur par d�faut de <Personne>" << endl;
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
#ifdef MAP
	    cout << "Appel au destructeur de <Personne>" << endl;
#endif
	}//----- Fin de ~Personne

	//------------------------------------------------------------------ PRIVE 

protected:
	//----------------------------------------------------- M�thodes prot�g�es

private:
	//------------------------------------------------------- M�thodes priv�es

protected:
	//----------------------------------------------------- Attributs prot�g�s
	int idPersonne;
    string prenom;
	string nom;
	string mail;

private:
	//------------------------------------------------------- Attributs priv�s

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Personne>

#endif // PERSONNE_H
