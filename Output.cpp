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
        //cout << *i << endl;
        //Pierre, fait un surcharge qui marche :)
    }
}

void Output::afficherResultatATMO(int methode, const vector<tuple<Attribute, int, double, int>> & resultat) {
    cout << "--- Résultat ATMO ---" << endl;
    for (vector<tuple<Attribute, int, double, int>>::const_iterator i = resultat.cbegin(); i != resultat.cend(); i++)
    {
        //cout << "Type de gaz : " << get<0>(*i) << ", ATMO : " << get<1>(*i) << ", Concentration : " << get<2>(*i) << ", Nombre de capteurs utilisés : " << get<3>(*i) << endl;
        //Faites ca une fois que vous aurez surchargé << pour les Attribute !!!
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

/*Output::~Output() {
#ifdef MAP
    cout << "Appel au destructeur de <Top10>" << "\r\n";
#endif
}*/


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
