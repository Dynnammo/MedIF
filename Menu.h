#ifndef MENU_H
#define MENU_H

#include "Medecin.h"
#include "Patient.h"

class Menu
{
public :
    static void menuPrincipal();

private:
    static void menuTest();
    static void menuAppli();
    static Patient menuAjoutPatient(Medecin m, vector<Patient> listePatients);
    static void menuMesurerPatient(Patient p);
};

#endif // MENU_H
