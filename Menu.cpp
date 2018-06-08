// ------------------------------------- INCLUDE SYSTEME
#include <iostream>
#include <vector>

using namespace std;
// ------------------------------------- INCLUDE PERSONNEL
#include "Menu.h"
#include "Initialisation.h"
#include "Medecin.h"

static Initialisation i;
void Menu::menuPrincipal()
{
    cout << "Bienvenue dans l'application Med'IF !" << endl;
    cout << "Si vous souhaitez effectuer des tests, tapez 1." << endl;
    cout << "Si vous etes medecin et souhaitez utiliser l'application, tapez 0." << endl;
    int test;
    cin >> test;
    cout << test << endl;

    if(test)
        menuTest();
    else
        menuAppli();
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
    i.init(nomFichier);
    i.initMedecin("fichierMedecin.txt");
    i.afficherMedecin();
    
    cout << "Pour continuer votre aventure, veuillez vous connecter, s'il vous plait." << endl;
    cout << "Votre adresse mail : ";
    string mailMedecin;
    cin >> mailMedecin;
    cout << "Votre mot de passe : ";
    string mdpMedecin;
    cin >> mdpMedecin;
    Medecin m("Don't care", mailMedecin,"Don't care", mdpMedecin);
    vector<Medecin> listeMedecins = i.getListeMedecin();
    vector<Patient> listePatients = i.getListePatient();
    unordered_map<int, Maladie> lm = i.getListeMaladie();
    //if (m.seConnecter(listeMedecins))
    {
        int option=0;
        while (option != 6)
        {
            cout << "Vous etes bien connecte a notre plateforme." << endl;
            cout << "Que souhaitez-vous faire maintenant ?" << endl;
            cout << "Veuillez choisir l'option qui vous convient : " << endl;
            cout << "---------------------------------------------" << endl;
            cout << "1. Enregistrer un nouveau patient" << endl;
            cout << "2. Effectuer les mesures sur un patient" << endl;
            cout << "3. Effectuer l'analyse d'une ou plusieurs empreintes" << endl;
            cout << "4. Rechercher une analyse" << endl;
            cout << "5. Afficher la liste des maladies enregistrees" << endl;
            cout << "6. Vous deconnecter" << endl;
            cout << "---------------------------------------------" << endl;
            cin >> option;

            switch (option)
            {
            case 1:
                menuAjoutPatient(m, listePatients);
                break;
            case 2:
                menuMesurerPatient(m, listePatients);
                break;
            case 3:
                menuFaireAnalyse(m, lm);
                break;
            case 4:
                menuRechercherAnalyse(i, m);
                break;
            case 5:
                menuAfficherMaladie(i, m);
                break;
            case 6:
                m.seDeconnecter();
                cout << "A la revoyure !";
                break;
            default:
                cout << "Il semblerait que vous n'ayez pas choisi une option qui existe. Nous tacherons d'y remedier un jour...";
                break;
            }
        }
    }
    //else
    {
        cout << "Vous n'etes pas inscrit dans notre base de donnees ou il y a une erreur dans mail ou mot de passe. Veuillez contacter votre service informatique pour plus d'informations." << endl;
    }
}

void Menu::menuAjoutPatient(Medecin m, vector<Patient> &listePatients)
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
    i.setPatient(p);
    i.afficherPatient();
    cout << "Patient bien ajoute." << endl;
    cout << "=======================>>> Retour au menu" << endl;
}

void Menu::menuMesurerPatient(Medecin m, vector<Patient> listePatients)
{
    cout << "Vous avez choisi de faire les mesures de vos patients." << endl;
    cout << "Veuillez entrer le nom du fichier correspondant au mesures du capteur : ";
    string nomFichier;
    cin >> nomFichier;
    m.chargerEmpreinte(nomFichier, listePatients);
    cout << "Les empreintes ont bien ete enregistrees pour les patients." << endl;
    cout << "=======================>>> Retour au menu" << endl;
}

void Menu::menuFaireAnalyse(Medecin m, unordered_map<int, Maladie> &lm)
{
    i.afficherPatient();
    cout << "Vous avez choisi d'effectuer l'analyse d'empreintes." << endl;
    cout << "Veuillez entrer l'id du patient : " << endl;
    int idPatient;
    cin >> idPatient;
    Patient p = i.getPatient(idPatient);
    cout << p;
    list<Analyse> listeAnalyse = m.faireAnalyse(p, lm,true);
    cout << "L'analyse est terminee. Voulez-vous la voir ? (Y/N) ";
    string afficher;
    cin >> afficher;
    if (afficher=="Y")
    {
        for (list<Analyse>::const_iterator it = listeAnalyse.cbegin(); it != listeAnalyse.cend(); it++) {
            cout << *it << endl;
        }
    }
    cout << "=======================>>> Retour au menu" << endl;
}

void Menu::menuRechercherAnalyse(Initialisation i, Medecin m)
{
    if (i.getListePatient().size() == 0) {
        cout << "Vous n'avez aucun patient, donc aucune analyse" <<endl;
        return;
    }
    cout << "Vous avez choisi de rechercher une analyse." << endl;
    cout << "Veuillez entrer l'id du patient dont vous voulez rechercher l'analyse: ";
    i.afficherPatient();
    int idPatient;
    cin >> idPatient;
    Patient p = i.getPatient(idPatient);
    p.afficherAnalyse();
    cout << "Veuillez entrer l'id de l'analyse que vous recherchez : ";
    int idAnalyse;
    cin >> idAnalyse;
    cout << "Voici ce que nous avons trouve : " << endl;
    Analyse a = m.rechercherAnalyse(idAnalyse, p);
    cout << a << endl;
    cout << "=======================>>> Retour au menu" << endl;
}

void Menu::menuAfficherMaladie(Initialisation i, Medecin m)
{
    cout << "Vous avez choisi d'afficher la liste des maladies enregistrees." << endl;
    unordered_map <int, Maladie> listeMaladies = i.getListeMaladie();
    m.afficherMaladies(listeMaladies);
    cout << "=======================>>> Retour au menu" << endl;
}
