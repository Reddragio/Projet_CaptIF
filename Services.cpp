#include "Services.h"

unordered_set<string> Services::getSensorsTerritoryIds(Point p, double rayon, Date debut, Date fin)
{
    return unordered_set<string>();
}

vector<tuple<Attribute, int, double, int>> Services::qualiteAirTerritoirePeriode(Point p, double rayon, Date debut, Date fin)
{
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
