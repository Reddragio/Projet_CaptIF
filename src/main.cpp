#include <iostream>
#include <fstream>
#include <algorithm>
#include "Controleur/CaptIF.h"
#include "Modele/RequestView.h"
#include <ctime>
using namespace std;

int main() {
    //cout << "Lancement du programme..." << endl;
    //cout << endl;
    //clock_t start;
    //double duree;
    //start = clock();
    //duree = (clock() - start) / (double)CLOCKS_PER_SEC;
    //cout << "Initialisation des Sensors et Attributs en "<< duree << "s" << endl;
    //cout << endl;

    cout << "### INITIALISATION ###" << endl;
    vector<string> fichiers;
    bool auMoinsUn = false;
    string rep;
    do{
        if(!auMoinsUn)
        {
            cout << "--> Veuillez rentrer le nom du 1er fichier csv" << endl;
        }
        else
        {
            cout << "--> Veuillez rentrer un a un le nom des autres fichiers csv" << endl;
            cout << "(Pour terminer, tapez simplement \"0\")" << endl;
        }
        cin >> rep;

        //raccourcis pour le dev
        //A ne pas utiliser dans la version finale
        if(rep=="NORMAL" || rep=="TEST"){
            break;
        }

        if(rep != "0")
        {
            ifstream test(rep);
            if(test){
                if(find(fichiers.begin(), fichiers.end(), rep) == fichiers.end()){
                    cout << "*** Fichier ajoute avec succes ***" << endl;
                    fichiers.push_back(rep);
                    auMoinsUn = true;
                }
                else
                {
                    cout << "ERREUR: Vous avez deja rentre ce fichier" << endl;
                }

            }
            else
            {
                cout << "ERREUR: le fichier n'existe pas" << endl;
            }
            test.close();
        }


    }while(rep != "0" || !auMoinsUn);

    if(rep=="NORMAL"){
        fichiers.push_back("Sensors.csv");
        fichiers.push_back("AttributeType.csv");
        fichiers.push_back("data.csv");
    }
    else if(rep=="TEST"){
        fichiers.push_back("dataTest.csv");
        fichiers.push_back("AttributeType.csv");
    }

    CaptIF application(fichiers);

    application.run();
    return 0;
}
// essai xiaofan
//esaie sofiane