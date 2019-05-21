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
}

void Output::afficherMenu() {
    cout << " Methode 1--- qualiteAirTerritoirePeriode" << endl;
    cout << " Methode 2--- qualiteAirTerritoireMoment" << endl;
    cout << " Methode 3--- qualiteAirPointPeriode" << endl;
    cout << " Methode 4--- qualiteAirPointMoment" << endl;
    cout << " Methode 5--- evolutionGlobale" << endl;
    cout << " Methode 6--- detecterCapteursDysfonctionnels" << endl;
    cout << " Methode 7--- listerCapteurs" << endl;
    cout << " Methode 8--- verifierCapteurs" << endl;
    cout << " Methode 9--- detecterComportementSimilaires" << endl;
}

void Output::afficherCapteurs(const vector<Sensor> & sensors) {
    for (vector<Sensor>::const_iterator i = sensors.cbegin(); i != sensors.cend(); i++) {
        cout << *i << endl;
    }
}

void Output::afficherResultatATMO(int methode, const map<string,tuple<int, double, int>> & resultat) {
    cout << "--- ATMO ---" << endl;
    for (map<string,tuple<int, double, int>>::const_iterator i = resultat.cbegin(); i != resultat.cend(); i++)
    {
        cout << "Type de gaz : " << i->first << ", ATMO : " << get<0>(i->second) << ", Concentration : " << get<1>(i->second) << attributes[i->first].getUnit() <<", Nombre de valeurs utiles: " << get<2>(i->second) << endl;
    }
}

void Output::afficherEvolution(int methode, const map<string,tuple<double, double, double, Date>> & resultat) {
    cout << "--- Résultat d'évolution ---" << endl;
    for (map<string,tuple<double, double, double, Date>>::const_iterator i = resultat.cbegin(); i != resultat.cend(); i++)
    {
        cout << "Type de gaz : " << i->first << ", Concentration initiale : " << get<0>(i->second) << ", Concentration finale: " << get<1>(i->second)  <<", Taux d'augmentation : " << get<2>(i->second) <<", Date de mesure : " << get<3>(i->second)<< endl;
    }
}

void Output::afficherCapteursEtBugs(const vector<tuple<Sensor, int>> & resultat)
{

}

void Output::afficherSimilarites(const unordered_map<string,unordered_map<string,bool>> & resultat)
{

}

void Output::afficherResultatCapteur(bool resultat)
{

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
