#ifndef MENU_H
#define MENU_H

#include "Initialisation.h"
#include "Medecin.h"
#include "Patient.h"

class Menu
{
public :
    static void menuPrincipal();

private:
    static void menuTest();
    static void menuAppli();
    static void menuAjoutPatient(Medecin m, vector<Patient> &listePatients);
    static void menuMesurerPatient(Medecin m, vector<Patient> listePatients);
    static void menuFaireAnalyse(Initialisation i, Medecin m, unordered_map<int, Maladie> &lm);
    static void menuRechercherAnalyse(Initialisation i, Medecin m);
    static void menuAfficherMaladie(Initialisation i, Medecin m);
};

#endif // MENU_H
