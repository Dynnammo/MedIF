/*************************************************************************
Patient  -  description
-------------------
d�but                : 27.04.2018
copyright            : (C) 2018 par Tifenn FLOCH
									Anatolii GASIUK
									L�o PAPE
									Baptiste THIVEND
e-mail               : @insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Patient> (fichier Patient.h) ------
#if ! defined ( PATIENT_H )
#define PATIENT_H

#include <string>
#include <iostream>
#include <list>

using namespace std;

//--------------------------------------------------- Interfaces utilis�es
#include "Personne.h"
#include "Empreinte.h"
#include "Analyse.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <Patient>
//
//
//------------------------------------------------------------------------ 

class Patient : public Personne
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
	// type M�thode ( liste de param�tres );
	// Mode d'emploi :
	//
	void afficherAnalyse(){
		
		for(list<Analyse>::iterator it = la.begin(); it!= la.end(); it++)
		{
			cout << *it;
		}
		
	}
	void afficherEmpreinte(){
		for(list<Empreinte>::iterator it = le.begin(); it!= le.end(); it++)
		{
			cout << *it;
		}
	}
	void viderListeEmpreintes() {

		le.clear();
	}
	// Contrat :


	//------------------------------------------------------ Getters - Setters
	list <Empreinte> getEmpreintes() 
	{
		return le;
	}

	list <Analyse> getAnalyses() 
	{
		return la;
	}

	void setAnalyses(Analyse &a)
	{
		la.push_back(a);
	}

	void setEmpreintes(Empreinte &e)
	{
		 le.push_back(e);
	}
	//------------------------------------------------- Surcharge d'op�rateurs

	// Mode d'emploi :
	//
	// Contrat :
	//
	//------------------------------------------------- Surcharge d'op�rateurs
	Patient & operator = ( Patient const & p)
	{
		this->idPersonne = p.idPersonne;
		return *this;
	} //----- Fin de operator =

	friend ostream &operator<<(ostream &os, const Patient  &p){
		os << "Patient"<< endl;
		os << "Nom " << p.nom << endl;
		os << "Prenom " << p.prenom << endl;
		os << "Mail " << p.mail << endl;
		return os;
	}

	//-------------------------------------------- Constructeurs - destructeur

	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Patient(const Patient & p)
	{
		this->idPersonne = p.idPersonne;
		this->nom = p.nom;
		this->prenom = p.prenom;
		this->mail = p.mail;
		this->la = p.la;
		this->le = p.le;
#ifdef MAP
	    cout << "Appel au constructeur de copie de <Maladie>" << endl;
#endif
	}//----- Fin de Patient (constructeur de copie)

	Patient()
	{
		this->nom = "";
		this->prenom = "";
		this->mail = "";
#ifdef MAP
    	cout << "Appel au constructeur de copie de <Patient>" << endl;
#endif
	}//----- Fin de Patient

	Patient(string n, string p, string m)
		: Personne(n,p,m)
	{
#ifdef MAP
    	cout << "Appel au constructeur de <Patient>" << endl;
#endif
	}//----- Fin de Patient


	virtual ~Patient()
	{
		
#ifdef MAP
	    cout << "Appel au destructeur de <Patient>" << endl;
#endif
	}//----- Fin de ~Patient


	//------------------------------------------------------------------ PRIVE 

protected:
	//----------------------------------------------------- M�thodes prot�g�es

private:
	//------------------------------------------------------- M�thodes priv�es

protected:
	//----------------------------------------------------- Attributs prot�g�s
	

private:
	//------------------------------------------------------- Attributs priv�s
	list <Analyse> la;
	list <Empreinte> le;
	//---------------------------------------------------------- Classes amies

	//-------------------------------------------------------- Classes priv�es

	//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Patient>

#endif // PATIENT_H
