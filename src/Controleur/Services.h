//---------- Interface de la classe <Services> (fichier Services.h) ----------------
#ifndef PROJET_CAPTIF_SERVICES_H
#define PROJET_CAPTIF_SERVICES_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <string>
using namespace std;

#include "../Modele/Attribute.h"
#include "../Modele/Point.h"
#include "../Modele/Date.h"
#include "../Modele/Sensor.h"
#include "../Modele/Parser.h"
#include "../Modele/RequestView.h"

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
    unordered_set<string> getSensorsTerritoryIds(Point p, double rayon) const;

    map<string,tuple<int, double, int>> qualiteAirTerritoirePeriode(Point p, double rayon, Date debut, Date fin);

    map<string,tuple<int, double, int>> qualiteAirTerritoireMoment(Point p, double rayon, Date moment);

    map<string,tuple<int, double, int>> qualiteAirPointPeriode(Point p, Date debut, Date fin);

    map<string,tuple<int, double, int>> qualiteAirPointMoment(Point p, Date moment);

    map<string,tuple<double, double, double, Date>> evolutionGlobale(Point p, double rayon, Date debut, Date fin);

    void detecterCapteursDysfonctionnels(Point p, double rayon, unordered_map<string,bool> & fonctionnel);

    bool verifierCapteurs(string idCap);

    void detecterComportementSimilaires(Point p, double rayon,unordered_map<string,unordered_map<string,bool>> & similitude);

    unordered_map<string,Sensor> listerCapteurs(Point p, double rayon);

    unordered_map<string,Sensor> getSensors() const;

    unordered_map<string,Attribute> getAttributes() const;

    //-------------------------------------------- Constructeurs - Destructeur

    Services();

    Services(vector<string> fichiers);

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées
    int calculIndiceATMO(string gaz,double concentration) const;

    //----------------------------------------------------- Attributs protégés
    unordered_map<string,Sensor> sensors;
    unordered_map<string,Attribute> attributes;
    Parser parser;
};

//-------------------------------- Autres définitions dépendantes de <Services>

#endif // SERVICES_H