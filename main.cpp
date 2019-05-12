#include <iostream>
#include "CaptIF.h"
#include "RequestView.h"

int main() {
    vector<string> fichiers;
    fichiers.push_back("Sensors.csv");
    fichiers.push_back("AttributeType.csv");
    fichiers.push_back("data.csv");
    CaptIF application(fichiers);

    //Test de la RequestView
    set<string> sensorIds;
    sensorIds.insert("Sensor7");
    sensorIds.insert("Sensor8");
    RequestView rtest(fichiers,sensorIds,Date(1980,0,0,0,0,0,0),Date(2050,0,0,0,0,0,0));
    vector<Measure> res;
    while(rtest.goToNext()){
        res.push_back(rtest.getMeasure());
    }
    cout << "Nombre de mesures retenues: "<<res.size() << endl;

    application.run();
    return 0;
}
// essai xiaofan
//esaie sofiane