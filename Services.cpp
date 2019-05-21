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

map<string,tuple<int, double, int>> Services::qualiteAirTerritoireMoment(Point p, double rayon, Date moment)
{
    unordered_set<string> sensorsId = getSensorsTerritoryIds(p, rayon);
    map<string,tuple<int, double, int>> resultat;
    //cout << "Nb capteurs: "<<sensorsId.size() << endl;
    time_t temps = moment.getTemps();
    int msec = moment.getMsec();
    Date debut =Date(temps+2*60*60,msec);
    Date fin =Date(temps-2*60*60,msec);
    RequestView request = parser.getRequestView(sensorsId,fin,debut);

    unordered_map<string,long double> mesureJustAvant;
    unordered_map<string,long double> mesureJustApres;
    unordered_map<string,long double> diviseur;

    Date actuel;
    Date dateJustAvant;
    Date dateJustApres;
    time_t DiffAvant = 2*60*60;
    time_t DiffApres = 2*60*60;

    for(unordered_map<string,Attribute>::const_iterator gaz = attributes.cbegin();gaz != attributes.cend();++gaz)
    {
        mesureJustAvant.insert(make_pair(gaz->first,0.0));
        mesureJustApres.insert(make_pair(gaz->first,0.0));
        diviseur.insert(make_pair(gaz->first,0.0));
    }
    Measure meas;
    while(request.goToNext())
    {
        meas = request.getMeasure();
        actuel = meas.getDate();
        if(actuel.getTemps()==temps)
        {
            mesureJustAvant[meas.getAttributeId()] = meas.getValue();
            mesureJustApres[meas.getAttributeId()] = meas.getValue();
            diviseur[meas.getAttributeId()] = 2;
            DiffAvant =0;
            DiffApres =0;
        }
        if((actuel.getTemps()<temps) && (temps - actuel.getTemps()< DiffAvant))
        {
            mesureJustAvant[meas.getAttributeId()] = meas.getValue();
            DiffAvant = temps - actuel.getTemps();
            if(mesureJustApres[meas.getAttributeId()]){
                diviseur[meas.getAttributeId()] = 2;
            }else {
                diviseur[meas.getAttributeId()] = 1;
            }
        }
        if((actuel.getTemps()>temps) &&(actuel.getTemps() - temps < DiffApres))
        {
            mesureJustApres[meas.getAttributeId()] = meas.getValue();
            DiffApres = actuel.getTemps() - temps;
            if(mesureJustAvant[meas.getAttributeId()]){
                diviseur[meas.getAttributeId()] = 2;
            }else{
                diviseur[meas.getAttributeId()] = 1;
            }
        }
    }


    double concentration;
    int indice;
    for(unordered_map<string,Attribute>::const_iterator gaz = attributes.cbegin();gaz != attributes.cend();++gaz)
    {
        if(diviseur[gaz->first] > 0)
        {
            concentration = (double)((mesureJustAvant[gaz->first]+mesureJustApres[gaz->first])/diviseur[gaz->first]);
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

map<string,tuple<int, double, int>> Services::qualiteAirPointPeriode(Point p, Date debut, Date fin)
{
    unordered_set<string> sensorsPres = getSensorsTerritoryIds(p, 0.01);
    map<string,tuple<int, double, int>> resultat;
    //cout << "Nb capteurs: "<<sensorsId.size() << endl;
    RequestView requestPres = parser.getRequestView(sensorsPres,debut,fin);

    unordered_map<string,long double> sommePres;
    unordered_map<string,long double> diviseurPres;

    for(unordered_map<string,Attribute>::const_iterator gaz = attributes.cbegin();gaz != attributes.cend();++gaz)
    {
        sommePres.insert(make_pair(gaz->first,0.0));
        diviseurPres.insert(make_pair(gaz->first,0.0));
    }

    Measure meas;
    while(requestPres.goToNext()){
        meas = requestPres.getMeasure();
        sommePres[meas.getAttributeId()] += meas.getValue();
        diviseurPres[meas.getAttributeId()] += 1;
    }


    double concentration;
    int indice;

    unordered_set<string> sensorsId = getSensorsTerritoryIds(p, 10);
    RequestView request = parser.getRequestView(sensorsId,debut,fin);

    unordered_map<string,long double> somme;
    unordered_map<string,long double> diviseur;
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
            while(request.goToNext()) {
                meas = request.getMeasure();
                if (meas.getAttributeId() == (gaz->first)) {
                    somme[meas.getAttributeId()] +=
                            (1 / p.distance(sensors(sensorsId).getLocation())) * meas.getValue();
                    diviseur[meas.getAttributeId()] += 1 / p.distance(request.getSensor().getLocation());
                }
            }
            if(diviseur[gaz->first] > 0)
            {
                concentration = (double)(somme[gaz->first]/diviseur[gaz->first]);
                indice = calculIndiceATMO(gaz->first,concentration);
                resultat.insert(make_pair(gaz->first,make_tuple(indice,concentration,(int)diviseur[gaz->first])));

            }else
            {
                resultat.insert(make_pair(gaz->first,make_tuple(-1,-1.0,0)));
            }
        }
    }
    return resultat;
}

map<string,tuple<int, double, int>> Services::qualiteAirPointMoment(Point p, Date moment)
{
    return map<string,tuple<int, double, int>>();
}

map<string,tuple<double, double, double, Date>> Services::evolutionGlobale(Point p, double rayon, Date debut, Date fin)
{
    unordered_set<string> sensors = getSensorsTerritoryIds(p, rayon);
    map<string,tuple< double, double, double,Date>> resultat;
    RequestView requestPres = parser.getRequestView(sensors,debut,fin);

    unordered_map<string,long double> PremierMesure;
    unordered_map<string,long double> DernierMesure;
    unordered_map<string,Date> DateMesure;

    time_t dateValeurDebut = LONG_MAX;
    time_t dateValeurFin = LONG_MIN;

    for(unordered_map<string,Attribute>::const_iterator gaz = attributes.cbegin();gaz != attributes.cend();++gaz)
    {
        PremierMesure.insert(make_pair(gaz->first,0.0));
        DernierMesure.insert(make_pair(gaz->first,0.0));
    }

    Measure meas;
    meas = requestPres.getMeasure();
    while(requestPres.goToNext()){
        meas = requestPres.getMeasure();
        if((debut.getTemps()<meas.getDate().getTemps())&&(meas.getDate().getTemps()<=dateValeurDebut)){
            dateValeurDebut = meas.getDate().getTemps();
            PremierMesure[meas.getAttributeId()] = meas.getValue();
        }
        if((dateValeurFin<meas.getDate().getTemps())&&(meas.getDate().getTemps()<=fin.getTemps())){
            dateValeurFin = meas.getDate().getTemps();
            DateMesure[meas.getAttributeId()] = meas.getDate();
            DernierMesure[meas.getAttributeId()] = meas.getValue();

        }
    }

    double concentrationA;
    double concentrationD;
    double TauxAugmenter;
    Date dateM;


    for(unordered_map<string,Attribute>::const_iterator gaz = attributes.cbegin();gaz != attributes.cend();++gaz)
    {
        if(PremierMesure[gaz->first])
        {
            concentrationA = (double) (PremierMesure[gaz->first]);
            concentrationD = (double) (DernierMesure[gaz->first]);
            dateM = (Date) DateMesure[gaz->first];
            TauxAugmenter = (concentrationD - concentrationA) / concentrationA;
            resultat.insert(make_pair(gaz->first, make_tuple(concentrationA, concentrationD, TauxAugmenter, dateM)));
        }else{
            resultat.insert(make_pair(gaz->first,make_tuple(-1.0,-1.0,0,debut)));
        }

    }
    return resultat;
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
