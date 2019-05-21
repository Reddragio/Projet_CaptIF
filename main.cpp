#include <iostream>
#include "CaptIF.h"
#include "RequestView.h"
#include <ctime>

int main() {
    cout << "Lancement du programme..." << endl;
    cout << endl;
    clock_t start;
    double duree;

    vector<string> fichiers;
    fichiers.push_back("Sensors.csv");
    fichiers.push_back("AttributeType.csv");
    fichiers.push_back("data.csv");
    start = clock();
    CaptIF application(fichiers);
    duree = (clock() - start) / (double)CLOCKS_PER_SEC;
    cout << "Initialisation des Sensors et Attributs en "<< duree << "s" << endl;
    cout << endl;

    /*
    //Test de la RequestView
    set<string> sensorIds;
    sensorIds.insert("Sensor7");
    sensorIds.insert("Sensor8");

    //Debut chrono
    start = clock();
    //Test en lui même
    RequestView rtest(fichiers,sensorIds,Date(1980,0,0,0,0,0,0),Date(2050,0,0,0,0,0,0));
    vector<Measure> res;
    while(rtest.goToNext()){
        res.push_back(rtest.getMeasure());
    }
    //fin chrono
    duree = (clock() - start) / (double)CLOCKS_PER_SEC;
    cout << "Nombre de mesures retenues: "<<res.size() << endl;
    cout << "En: "<<duree << "s"<<endl;*/

    application.run();
    return 0;
}
// essai xiaofan
//esaie sofiane