/*************************************************************************
Output
-------------------
Date                 : 05/05/2019
Copyright            :
*************************************************************************/

//---------- Réalisation de la classe <Output> (fichier Output.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système


//------------------------------------------------------ Include personnel
#include <iostream>

#include "Output.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Output::afficherMessageAccueil() {
    cout << "Bienvenue sur l'application Capt'IF" << endl;
    //commentaire Sofiane
}

void Output::afficherMenu() {
    cout << "Menu" << endl;
    //COmmentaire Jacques
}

void Output::afficherCapteurs(const vector<Sensor> & sensors) {
    for (vector<Sensor>::const_iterator i = sensors.cbegin(); i != sensors.cend(); i++) {
        cout << *i << endl;
    }
}

void Output::afficherResultatATMO(int methode, const map<string,tuple<int, double, int>> & resultat) {
    cout << "--- Résultat ATMO ---" << endl;
    for (map<string,tuple<int, double, int>>::const_iterator i = resultat.cbegin(); i != resultat.cend(); i++)
    {
        cout << "Type de gaz : " << i->first << ", ATMO : " << get<0>(i->second) << ", Concentration : " << get<1>(i->second) << attributes[i->first].getUnit() <<", Nombre de capteurs utilises : " << get<2>(i->second) << endl;
    }
}

void afficherEvolution(const map<string,tuple<double, double, double, Date>> & resultat) {
    cout << "--- Résultat d'évolution ---" << endl;
    for (map<string,tuple<double, double, double, Date>>::const_iterator i = resultat.cbegin(); i != resultat.cend(); i++)
    {
        cout << "Type de gaz : " << i->first << ", Concentration initiale : " << get<0>(i->second) << ", Concentration finale: " << get<1>(i->second)  <<", Taux d'augmentation : " << get<2>(i->second) <<", Date de mesure : " << get<3>(i->second)<< endl;
    }
}

//-------------------------------------------- Constructeurs - destructeur

Output::Output() {
#ifdef MAP
    cout << "Appel au constructeur de <Point>" << "\r\n";
#endif

}

Output::Output(const unordered_map<string, Sensor> &sensors, const unordered_map<string, Attribute> &attributes)
        : sensors(sensors), attributes(attributes) {}

/*Output::~Output() {
#ifdef MAP
    cout << "Appel au destructeur de <Top10>" << "\r\n";
#endif
}*/


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
