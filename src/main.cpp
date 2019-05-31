#include <iostream>
#include "Controleur/CaptIF.h"
#include "Modele/RequestView.h"
#include <ctime>

int main() {
    cout << "Lancement du programme..." << endl;
    cout << endl;
    clock_t start;
    double duree;

    vector<string> fichiers;
    /*fichiers.push_back("Sensors.csv");
    fichiers.push_back("AttributeType.csv");
    fichiers.push_back("data.csv");*/
    //Tests files
    fichiers.push_back("dataTest.csv");
    fichiers.push_back("AttributeType.csv");
    start = clock();
    CaptIF application(fichiers);
    duree = (clock() - start) / (double)CLOCKS_PER_SEC;
    cout << "Initialisation des Sensors et Attributs en "<< duree << "s" << endl;
    cout << endl;

    application.run();
    return 0;
}
// essai xiaofan
//esaie sofiane