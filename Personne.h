/*************************************************************************
Personne -  description
-------------------
d�but                : 04.05.2018
copyright            : (C) 2018 par Tifenn Floch, Anatolii Gasiuk, 
									L�o Pape, Baptiste Thivend
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
	
	//------------------------------------------------------ Getters - Setters
	int getIdPersonne()
	{
		return idPersonne;
	}

	//------------------------------------------------- Surcharge d'op�rateurs

	// Mode d'emploi :
	//
	// Contrat :
	//

	//-------------------------------------------- Constructeurs - destructeur

	// Constructeur par d�faut
	Personne()
	{

	}

	// Constructeur
	Personne(string n, string p, string m)
	{
		idPersonne=id1++;
		prenom = p;
		nom = m;
		mail = m;
	}

	// Constructeur de copie
	Personne(Personne & p)
	{
		this.prenom = p.prenom;
		this.nom = p.nom;
		this.idPersonne = p.idPersonne;
		this.mail = p.mail;
	}

	// Destructeur de la classe Personne
	virtual ~Personne()
	{
		id1--;
	}

	//------------------------------------------------------------------ PRIVE 

protected:
	//----------------------------------------------------- M�thodes prot�g�es

private:
	//------------------------------------------------------- M�thodes priv�es

protected:
	//----------------------------------------------------- Attributs prot�g�s
	int idPersonne;
	string nom;
	string prenom;
	string mail;

private:
	//------------------------------------------------------- Attributs priv�s

	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Personne>

#endif // PERSONNE_H
