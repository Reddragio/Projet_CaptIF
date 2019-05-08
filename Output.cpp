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
    cout << "Menu" << endl;
}

void Output::afficherCapteurs(const vector<Sensor> & sensors) {
    for (vector<Sensor>::const_iterator i = sensors.cbegin(); i != sensors.cend; i++) {
        cout << *i << endl;
    }
}

void Output::afficherResultatATMO((int methode, const vector<tuple<Attribute, int, double, int>> & resultat)) {
    cout << "--- Résultat ATMO ---" << endl;
    for (vector<tuple<Attribute, int, double, int>>::const_iterator i = resultat.cbegin(); i != resultat.cend; i++)
    {
        cout << "Type de gaz : " << *i.get(0) << ", ATMO : " << *i.get(1) << ", Concentration : " << *i.get(2) << ", Nombre de capteurs utilisés : " << *i.get(3) << endl;
    }
}

void afficherEvolution(const tuple<double, double, double, Date> & resultat) {
    cout << "--- Résultat d'évolution ---" << endl;

}




//-------------------------------------------- Constructeurs - destructeur

Output::Output() {
#ifdef MAP
    cout << "Appel au constructeur de <Point>" << "\r\n";
#endif

}

Output::~Output() {
#ifdef MAP
    cout << "Appel au destructeur de <Top10>" << "\r\n";
#endif
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
