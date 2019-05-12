//---------- Interface de la classe <Services> (fichier Services.h) ----------------
#ifndef PROJET_CAPTIF_SERVICES_H
#define PROJET_CAPTIF_SERVICES_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

#include "Attribute.h"
#include "Point.h"
#include "Date.h"
#include "Sensor.h"
#include "Parser.h"
#include "RequestView.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Services>
//
//
//------------------------------------------------------------------------

class Services
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    unordered_set<string> getSensorsTerritoryIds(Point p, double rayon, Date debut, Date fin);

    vector<tuple<Attribute, int, double, int>> qualiteAirTerritoirePeriode(Point p, double rayon, Date debut, Date fin);

    vector<tuple<Attribute, int, double, int>> qualiteAirTerritoireMoment(Point p, double rayon, Date moment);

    vector<tuple<Attribute, int, double, int>> qualiteAirPointPeriode(Point p, Date debut, Date fin);

    vector<tuple<Attribute, int, double, int>> qualiteAirPointMoment(Point p, Date moment);

    vector<tuple<Attribute,double, double, double, Date>> evolutionGlobale(Point p, double rayon, Date debut, Date fin);

    void detecterCapteursDysfonctionnels(Point p, double rayon, vector<tuple<Sensor, int>> & resultat);

    bool verifierCapteurs(string idCap);

    void detecterComportementSimilaires(Point p, double rayon,unordered_map<Sensor,unordered_map<Sensor,bool>> & resultat);

    vector<Sensor> listerCapteurs(Point p, double rayon);

    //-------------------------------------------- Constructeurs - Destructeur

    Services();

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées
    vector<Sensor> sensors;
    vector<Attribute> attributes;
    Parser parser;
    //----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Services>

#endif // SERVICES_H