/*************************************************************************
Point
-------------------
Date                 : 05/05/2019
Copyright            :
*************************************************************************/

//---------- Réalisation de la classe <Point> (fichier Point.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Services.h"


//------------------------------------------------------------- Constantes
double indicesO3[9] = {29.0,54.0,79.0,104.0,129.0,149.0,179.0,209.0,239.0};
double indicesSO2[9] = {39.0,79.0,119.0,159.0,199.0,249.0,299.0,399.0,499.0};
double indicesNO2[9] = {29.0,54.0,84.0,109.0,134.0,164.0,199.0,274.0,399.0};
double indicesPM10[9] = {6.0,13.0,20.0,27.0,34.0,41.0,49.0,64.0,79.0};

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

unordered_set<string> Services::getSensorsTerritoryIds(Point p, double rayon) const
{
    unordered_set<string> res;
    for(unordered_map<string,Sensor>::const_iterator capteur = sensors.cbegin();capteur != sensors.cend();++capteur)
    {
        if(p.distance(capteur->second.getLocation()) <= rayon)
        {
            res.insert(capteur->first);
        }
    }
    return res;
}

map<string,tuple<int, double, int>> Services::qualiteAirTerritoirePeriode(Point p, double rayon, Date debut, Date fin)
{
    unordered_set<string> sensorsId = getSensorsTerritoryIds(p, rayon);
    //cout << "Nb capteurs: "<<sensorsId.size() << endl;
    RequestView request = parser.getRequestView(sensorsId,debut,fin);

    unordered_map<string,long double> somme;
    unordered_map<string,long double> diviseur;
    for(unordered_map<string,Attribute>::const_iterator gaz = attributes.cbegin();gaz != attributes.cend();++gaz)
    {
        somme.insert(make_pair(gaz->first,0.0));
        diviseur.insert(make_pair(gaz->first,0.0));
    }

    Measure meas;
    while(request.goToNext()){
        meas = request.getMeasure();
        somme[meas.getAttributeId()] += meas.getValue();
        diviseur[meas.getAttributeId()] += 1;
    }

    map<string,tuple<int, double, int>> resultat;
    double concentration;
    int indice;
    for(unordered_map<string,Attribute>::const_iterator gaz = attributes.cbegin();gaz != attributes.cend();++gaz)
    {
        if(diviseur[gaz->first] > 0)
        {
            concentration = (double)(somme[gaz->first]/diviseur[gaz->first]);
            indice = calculIndiceATMO(gaz->first,concentration);
            resultat.insert(make_pair(gaz->first,make_tuple(indice,concentration,(int)diviseur[gaz->first])));
        }
        else
        {
            resultat.insert(make_pair(gaz->first,make_tuple(-1,-1.0,0)));
        }
    }

    return resultat;
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

vector<tuple<Attribute,double, double, double, Date>> Services::evolutionGlobale(Point p, double rayon, Date debut, Date fin)
{
    return vector<tuple<Attribute,double, double, double, Date>>();
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

unordered_map<string,Sensor> Services::getSensors() const
{
    return sensors;
}

unordered_map<string,Attribute> Services::getAttributes() const
{
    return attributes;
}

//-------------------------------------------- Constructeurs - destructeur

Services::Services(){

}

Services::Services(vector<string> fichiers){
    parser = Parser(fichiers);
    parser.getSensorsAndAttributes(sensors,attributes);
    cout << "Nombre de capteurs: " << sensors.size() << endl;
    cout << "Nombre d'attributs: " << attributes.size() << endl;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

int Services::calculIndiceATMO(string gaz,double concentration) const
{
    int indice = 0;
    if(gaz == "O3"){
        for(indice=0;indice <= 8 && !(concentration <= indicesO3[indice]);++indice);
    }
    else if(gaz == "SO2"){
        for(indice=0;indice <= 8 && !(concentration <= indicesSO2[indice]);++indice);
    }
    else if(gaz == "NO2"){
        for(indice=0;indice <= 8 && !(concentration <= indicesNO2[indice]);++indice);
    }
    else if(gaz == "PM10"){
        for(indice=0;indice <= 8 && !(concentration <= indicesPM10[indice]);++indice);
    }
    return indice+1;
}
