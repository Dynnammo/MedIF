// ------------------------------------- INCLUDE SYSTEME
#include <iostream>
#include <vector>

using namespace std;
// ------------------------------------- INCLUDE PERSONNEL
#include "Menu.h"
#include "Initialisation.h"
#include "Medecin.h"


void Menu::menuPrincipal()
{
    cout << "Bienvenue dans l'application Med'IF !" << endl;
    cout << "Si vous souhaitez effectuer des tests, tapez 1." << endl;
    cout << "Si vous etes medecin et souhaitez utiliser l'application, tapez 0." << endl;
    bool test;
    cin >> test;
    cout << endl;

    if(test)
    {
        menuTest();
    }
    else
    {
        menuAppli();
    }
}

void Menu::menuTest()
{

}

void Menu::menuAppli()
{
    cout << "Vous etes bien arrive dans l'application Med'IF." << endl;
    cout << "Comme ceci est la premiere fois que l'application est lancée, elle doit être initialisee." << endl;
    cout << "Avec quel fichier souhaitez-vous faire l'initialisation ? Merci d'écrire le nom complet du fichier." << endl;
    string nomFichier;
    cin >> nomFichier;
    Initialisation i;
    i.init(nomFichier);
    cout << "Pour continuer votre aventure, veuillez vous connecter, s'il vous plait." << endl;
    cout << "Votre adresse mail : ";
    string mailMedecin;
    cin >> mailMedecin;
    cout << "Votre mot de passe : ";
    string mdpMedecin;
    cin >> mdpMedecin;
    Medecin m("Don't care", "Don't care", mailMedecin, mdpMedecin);
    vector<Medecin> listeMedecins = i.getListeMedecin();
    vector<Patient> listePatients = i.getListePatient();
    if (m.seConnecter(listeMedecins))
    {
        int option;
        while (option != 7)
        {
            cout << "Vous etes bien connecte a notre plateforme." << endl;
            cout << "Que souhaitez-vous faire maintenant ?" << endl;
            cout << "Veuillez choisir l'option qui vous convient : " << endl;
            cout << "---------------------------------------------" << endl;
            cout << "1. Enregistrer un nouveau patient" << endl;
            cout << "2. Effectuer les mesures sur un patient" << endl;
            cout << "3. Effectuer l'analyse d'une ou plusieurs empreintes" << endl;
            cout << "4. Rechercher une analyse" << endl;
            cout << "5. Afficher les analyses precedentes d'un patient" << endl;
            cout << "6. Afficher la liste des maladies enregistrees" << endl;
            cout << "7. Vous deconnecter" << endl;
            cout << "---------------------------------------------" << endl;
            cin >> option;

            switch (option)
            {
            case 1:
                menuAjoutPatient(m, listePatients);
                break;
            case 2:
                menuMesurerPatient(p);
                break;
            case 3:
                cout << "Vous avez choisi d'effectuer l'analyse d'empreintes." << endl;
                break;
            case 4:
                cout << "Vous avez choisi de rechercher une analyse." << endl;
                break;
            case 5:
                cout << "Vous avez choisi d'afficher les analyses precedentes d'un patient." << endl;
                break;
            case 6:
                cout << "Vous avez choisi d'afficher la liste des maladies enregistrees." << endl;
                break;
            case 7:
                m.seDeconnecter();
                cout << "A la revoyure !";
                break;
            default:
                cout << "Il semblerait que vous n'ayez pas choisi une option qui existe. Nous tacherons d'y remedier un jour...";
                break;
            }
        }
    }
    else
    {
        cout << "Vous n'etes pas inscrit dans notre base de donnees ou il y a une erreur dans mail ou mot de passe. Veuillez contacter votre service informatique pour plus d'informations." << endl;
    }
}

Patient Menu::menuAjoutPatient(Medecin m, vector<Patient> listePatients)
{
    cout << "Vous avez choisi d'enregistrer un nouveau patient." << endl;
    string nomPatient;
    string prenomPatient;
    string mailPatient;
    cout << "Veuillez entrer son nom : ";
    cin >> nomPatient;
    cout << "Veuillez entrer son prenom : ";
    cin >> prenomPatient;
    cout << "Veuillez entrer son adresse mail : ";
    cin >> mailPatient;
    Patient p = m.ajouterPatient(nomPatient, prenomPatient, mailPatient, listePatients);
    cout << "Patient bien ajoute." << endl;
    return p;
}

void Menu::menuMesurerPatient(Patient p)
{

}
