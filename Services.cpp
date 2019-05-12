/*************************************************************************
Point
-------------------
Date                 : 05/05/2019
Copyright            :
*************************************************************************/

//---------- Réalisation de la classe <Point> (fichier Point.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système


//------------------------------------------------------ Include personnel
#include "Services.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

unordered_set<string> Services::getSensorsTerritoryIds(Point p, double rayon, Date debut, Date fin)
{
    return unordered_set<string>();
}

vector<tuple<Attribute, int, double, int>> Services::qualiteAirTerritoirePeriode(Point p, double rayon, Date debut, Date fin)
{
    set<string> sensorsId = getSensorsTerritoryIds(p, rayon, debut, fin);
    const vector<string>  filesInit= "";
    Parser parser = new Parser(&filesInit);
    RequestView request = parser.getRequestView(sensorsId,debut,fin);

    return vector<tuple<Attribute, int, double, int>>();
}

vector<tuple<Attribute, int, double, int>> Services::qualiteAirTerritoireMoment(Point p, double rayon, Date moment)
{
    return vector<tuple<Attribute, int, double, int>>();
}

vector<tuple<Attribute, int, double, int>> Services::qualiteAirPointPeriode(Point p, Date debut, Date fin)
{
    return vector<tuple<Attribute, int, double, int>>();
}

vector<tuple<Attribute, int, double, int>> Services::qualiteAirPointMoment(Point p, Date moment)
{
    return vector<tuple<Attribute, int, double, int>>();
}

vector<tuple<double, double, double, Date>> Services::evolutionGlobale(Point p, double rayon, Date debut, Date fin)
{
    return vector<tuple<double, double, double, Date>>();
}

void Services::detecterCapteursDysfonctionnels(Point p, double rayon, vector<tuple<Sensor, int>>& resultat)
{
}

bool Services::verifierCapteurs(string idCap)
{
    return false;
}

void Services::detecterComportementSimilaires(Point p, double rayon, unordered_map<Sensor, unordered_map<Sensor, bool>>& resultat)
{
}

vector<Sensor> Services::listerCapteurs(Point p, double rayon)
{
    return vector<Sensor>();
}

//-------------------------------------------- Constructeurs - destructeur

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

