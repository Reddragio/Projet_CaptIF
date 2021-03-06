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
#include <cmath>

//------------------------------------------------------ Include personnel
#include "Services.h"


//------------------------------------------------------------- Constantes
double indicesO3[9] = {29.0,54.0,79.0,104.0,129.0,149.0,179.0,209.0,239.0};
double indicesSO2[9] = {39.0,79.0,119.0,159.0,199.0,249.0,299.0,399.0,499.0};
double indicesNO2[9] = {29.0,54.0,84.0,109.0,134.0,164.0,199.0,274.0,399.0};
double indicesPM10[9] = {6.0,13.0,20.0,27.0,34.0,41.0,49.0,64.0,79.0};

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

// Méthode semble fonctionner
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

// Méthode semble fonctionner
map<string,tuple<int, double, int>> Services::qualiteAirTerritoirePeriode(Point p, double rayon, Date debut, Date fin)
{
    unordered_set<string> sensorsId = getSensorsTerritoryIds(p, rayon);
    RequestView request = parser.getRequestView(sensorsId,debut,fin);

    unordered_map<string,long double> somme;
    unordered_map<string,long double> diviseur;
    for(unordered_map<string,Attribute>::const_iterator gaz = attributes.cbegin();gaz != attributes.cend();++gaz)
    {
        somme.insert(make_pair(gaz->first,0.0));
        diviseur.insert(make_pair(gaz->first,0.0));
    }

    Measure meas;
    //cout << "Date init: "<< request.getMeasure().getDate() << endl;
    //test bidouille
    //request.goToNext();
    while(request.goToNext()){
        meas = request.getMeasure();
        //cout << meas.getDate() << " # " << meas.getAttributeId() << " # " << meas.getValue() << endl;
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

// Méthode semble fonctionner
map<string,tuple<int, double, int>> Services::qualiteAirTerritoireMoment(Point p, double rayon, Date moment)
{
    unordered_set<string> sensorsId = getSensorsTerritoryIds(p, rayon);

    time_t temps = moment.getTemps();
    int msec = moment.getMsec();
    Date debut =Date(temps-2*3600,msec);//2 heures avant le moment
    Date fin =Date(temps+2*3600,msec);//2 heures après le moment
    RequestView request = parser.getRequestView(sensorsId,debut,fin);

    unordered_map<string,double> justeAvant;
    unordered_map<string,Date> dateJusteAvant;
    unordered_map<string,double> justeApres;
    unordered_map<string,Date> dateJusteApres;

    for(unordered_map<string,Attribute>::const_iterator gaz = attributes.cbegin();gaz != attributes.cend();++gaz)
    {
        justeAvant.insert(make_pair(gaz->first,0.0));
        dateJusteAvant.insert(make_pair(gaz->first,Date::getMoinsInfini()));
        justeApres.insert(make_pair(gaz->first,0.0));
        dateJusteApres.insert(make_pair(gaz->first,Date::getPlusInfini()));
    }

    Measure meas;
    string attrIdMeas;
    Date dateMeas;
    while(request.goToNext())
    {
        meas = request.getMeasure();
        attrIdMeas = meas.getAttributeId();
        dateMeas = meas.getDate();

        if(dateJusteAvant[attrIdMeas] < dateMeas && dateMeas <= moment)
        {
            justeAvant[attrIdMeas] = meas.getValue();
            dateJusteAvant[attrIdMeas] = dateMeas;
        }
        else if(moment <= dateMeas && dateMeas < dateJusteApres[attrIdMeas])
        {
            justeApres[attrIdMeas] = meas.getValue();
            dateJusteApres[attrIdMeas] = dateMeas;
        }
    }

    map<string,tuple<int, double, int>> resultat;
    double concentration;
    int indice;
    for(unordered_map<string,Attribute>::const_iterator gaz = attributes.cbegin();gaz != attributes.cend();++gaz)
    {
        //if(diviseur[gaz->first] > 0)
        if(dateJusteAvant[gaz->first] != Date::getMoinsInfini() && dateJusteApres[gaz->first] != Date::getPlusInfini())
        {
            concentration = (justeAvant[gaz->first] + justeApres[gaz->first])/2.0;
            indice = calculIndiceATMO(gaz->first,concentration);
            resultat.insert(make_pair(gaz->first,make_tuple(indice,concentration,2.0)));
        }
        else
        {
            resultat.insert(make_pair(gaz->first,make_tuple(-1,-1.0,0)));
        }
    }

    return resultat;
}

// Méthode semble fonctionner
map<string,tuple<int, double, int>> Services::qualiteAirPointPeriode(Point p, Date debut, Date fin)
{
    double epsilon = 0.01;
    unordered_set<string> sensorsId = getSensorsTerritoryIds(p, 10);//Rayon de 10km par défaut
    RequestView request = parser.getRequestView(sensorsId,debut,fin);

    unordered_map<string,long double> somme;
    unordered_map<string,long double> diviseur;
    unordered_map<string,bool> tresProcheTrouve;
    unordered_map<string,double> valeurTresProche;
    unordered_map<string,int> compteur;
    for(unordered_map<string,Attribute>::const_iterator gaz = attributes.cbegin();gaz != attributes.cend();++gaz)
    {
        somme.insert(make_pair(gaz->first,0.0));
        diviseur.insert(make_pair(gaz->first,0.0));
        tresProcheTrouve.insert(make_pair(gaz->first,false));
        valeurTresProche.insert(make_pair(gaz->first,0.0));
        compteur.insert(make_pair(gaz->first,0));
    }

    Measure meas;
    string attrIdMeas;
    while(request.goToNext()){
        meas = request.getMeasure();
        attrIdMeas = meas.getAttributeId();
        double distanceCentre = p.distance(sensors[meas.getSensorId()].getLocation());

        if(!tresProcheTrouve[attrIdMeas])
        {
            if(distanceCentre <= epsilon)
            {
                tresProcheTrouve[attrIdMeas] = true;
                valeurTresProche[attrIdMeas] = meas.getValue();
                compteur[attrIdMeas] = 1;
            }
            else
            {
                somme[attrIdMeas] += meas.getValue() * (1.0/distanceCentre);
                diviseur[attrIdMeas] += (1.0/distanceCentre);
                ++compteur[attrIdMeas];
            }
        }

    }

    map<string,tuple<int, double, int>> resultat;
    double concentration;
    int indice;
    for(unordered_map<string,Attribute>::const_iterator gaz = attributes.cbegin();gaz != attributes.cend();++gaz)
    {
        if(tresProcheTrouve[gaz->first] || diviseur[gaz->first] > 0){
            if(tresProcheTrouve[gaz->first])
            {
                concentration = valeurTresProche[gaz->first];
            }
            else
            {
                concentration = (double)(somme[gaz->first]/diviseur[gaz->first]);
            }
            indice = calculIndiceATMO(gaz->first,concentration);
            resultat.insert(make_pair(gaz->first,make_tuple(indice,concentration,compteur[gaz->first])));
        }
        else
        {
            resultat.insert(make_pair(gaz->first,make_tuple(-1,-1.0,0)));
        }
    }

    return resultat;
}

// Méthode semble fonctionner
map<string,tuple<int, double, int>> Services::qualiteAirPointMoment(Point p, Date moment)
{
    // Récupération des capteurs sur un rayon de 10 kms par défaut.
    unordered_set<string> sensorsId = getSensorsTerritoryIds(p, 10);
    // Récupération de la requestView pour le parcours des fichiers : récupération à 10 km et pour Temps = [moment - 2h; moment + 2h]
    time_t mom = moment.getTemps();
    int mSec = moment.getMsec();
    Date debut = Date(mom - 2*3600, mSec);
    Date fin = Date(mom + 2*3600, mSec);
    RequestView request = parser.getRequestView(sensorsId, debut, fin);

    unordered_map<string, double> valeurs;
    for(unordered_map<string,Attribute>::const_iterator gazs = attributes.cbegin(); gazs != attributes.cend(); ++gazs) {
        valeurs.insert(make_pair(gazs->first, -1.0));
    }

    Measure m;
    while(request.goToNext()) {
        m = request.getMeasure();
        if (valeurs[m.getAttributeId()] == -1.0) {
            valeurs[m.getAttributeId()] = m.getValue();
        }
    }

    map<string, tuple<int, double, int>> resultat;
    int indice;
    double concentration;
    for(unordered_map<string,Attribute>::const_iterator gazs = attributes.cbegin(); gazs != attributes.cend(); ++gazs) {
        if (valeurs[gazs->first] != -1.0) {
            concentration = valeurs[gazs->first];
            indice = calculIndiceATMO(gazs->first, concentration);
            resultat.insert(make_pair(gazs->first, make_tuple(indice, concentration, 1)));
        } else {
            resultat.insert(make_pair(gazs->first, make_tuple(0, -1.0, 0)));
        }
    }
    return resultat;
}

map<string,tuple<double, double, double, Date>> Services::evolutionGlobale(Point p, double rayon, Date debut, Date fin)
{
    unordered_set<string> sensorsId = getSensorsTerritoryIds(p, rayon);
    RequestView request = parser.getRequestView(sensorsId,debut,fin);

    unordered_map<string,double> valeurDebut;
    unordered_map<string,Date> dateValeurDebut;
    unordered_map<string,double> valeurFin;
    unordered_map<string,Date> dateValeurFin;

    for(unordered_map<string,Attribute>::const_iterator gaz = attributes.cbegin();gaz != attributes.cend();++gaz)
    {
        valeurDebut.insert(make_pair(gaz->first,-1.0));
        dateValeurDebut.insert(make_pair(gaz->first,Date::getPlusInfini()));
        valeurFin.insert(make_pair(gaz->first,-1.0));
        dateValeurFin.insert(make_pair(gaz->first,Date::getMoinsInfini()));
    }

    Measure meas;
    string attrIdMeas;
    Date dateMeas;
    while(request.goToNext())
    {
        meas = request.getMeasure();
        attrIdMeas = meas.getAttributeId();
        dateMeas = meas.getDate();

        if(debut <= dateMeas && dateMeas < dateValeurDebut[attrIdMeas])
        {
            valeurDebut[attrIdMeas] = meas.getValue();
            dateValeurDebut[attrIdMeas] = dateMeas;
        }
        else if(dateMeas <= fin && dateMeas > dateValeurFin[attrIdMeas])
        {
            valeurFin[attrIdMeas] = meas.getValue();
            dateValeurFin[attrIdMeas] = dateMeas;
        }
    }

    map<string,tuple<double, double, double, Date>> resultat;
    double concentration;
    int indice;
    double pourcentageEvo;
    double vDeb;
    double vFin;
    for(unordered_map<string,Attribute>::const_iterator gaz = attributes.cbegin();gaz != attributes.cend();++gaz)
    {
        vDeb = valeurDebut[gaz->first];
        vFin = valeurFin[gaz->first];
        if(vDeb != -1.0 && vFin != -1)
        {
            if(vDeb != 0.0)
            {
                pourcentageEvo = ((vFin-vDeb)/vDeb)*100.0;
            }
            else
            {
                pourcentageEvo = 0.0;
            }
            resultat.insert(make_pair(gaz->first,make_tuple(vDeb,vFin,pourcentageEvo,dateValeurFin[gaz->first])));
        }
        else
        {
            resultat.insert(make_pair(gaz->first,make_tuple(-1.0,-1.0,0.0,Date())));
        }
    }

    return resultat;
}

void Services::detecterCapteursDysfonctionnels(Point p, double rayon, unordered_map<string,bool> & fonctionnel)
{
    int occurenceMax = 5;
    double deltaMax = 100.0;

    unordered_set<string> sensorsId = getSensorsTerritoryIds(p, rayon);
    RequestView request = parser.getRequestView(sensorsId,Date::getMoinsInfini(),Date::getPlusInfini());

    unordered_map<string,unordered_map<string,double>> evolution;
    unordered_map<string,unordered_map<string,int>> nbIdentique;
    //unordered_map<string,bool> fonctionnel;

    for(unordered_set<string>::const_iterator sensor = sensorsId.cbegin();sensor != sensorsId.cend();++sensor)
    {
        evolution.insert(make_pair(*sensor,unordered_map<string,double>()));
        nbIdentique.insert(make_pair(*sensor,unordered_map<string,int>()));
        for(unordered_map<string,Attribute>::const_iterator gaz = attributes.cbegin();gaz != attributes.cend();++gaz)
        {
            evolution[*sensor].insert(make_pair(gaz->first,-1.0));
            nbIdentique[*sensor].insert(make_pair(gaz->first,0));
        }
        fonctionnel.insert(make_pair(*sensor,true));
    }

    Measure meas;
    string attrIdMeas;
    string sensorIdMeas;
    while(request.goToNext())
    {
        meas = request.getMeasure();
        attrIdMeas = meas.getAttributeId();
        sensorIdMeas = meas.getSensorId();

        if(evolution[sensorIdMeas][attrIdMeas] != -1)
        {
            if(evolution[sensorIdMeas][attrIdMeas] == meas.getValue())
            {
                ++nbIdentique[sensorIdMeas][attrIdMeas];
                if(nbIdentique[sensorIdMeas][attrIdMeas] >= occurenceMax)
                {
                    fonctionnel[sensorIdMeas] = false;
                }
            }
            else
            {
                nbIdentique[sensorIdMeas][attrIdMeas] = 0;
                if(abs(evolution[sensorIdMeas][attrIdMeas] - meas.getValue()) > deltaMax)
                {
                    fonctionnel[sensorIdMeas] = false;
                }
            }
        }
        evolution[sensorIdMeas][attrIdMeas] = meas.getValue();
    }

    //Retour par réference
}

bool Services::verifierCapteurs(string idCap)
{
    unordered_map<string,bool> fonctionnel;
    if(sensors.find(idCap) != sensors.end())
    {
        detecterCapteursDysfonctionnels(sensors[idCap].getLocation(),0,fonctionnel);
        return fonctionnel[idCap];
    }
    return false;
}

void Services::detecterComportementSimilaires(Point p, double rayon, unordered_map<string, unordered_map<string, bool>>& similitude)
{
    int serieSuffisante = 5;
    //Nombre de valeurs successives nécessaires pour juger qu'il existe un très probable similitude entre les 2 capteurs
    Date time = Date::getMoinsInfini();
    double epsilon = 0.5;

    unordered_set<string> sensorsId = getSensorsTerritoryIds(p, rayon);
    RequestView request = parser.getRequestView(sensorsId,Date::getMoinsInfini(),Date::getPlusInfini());

    unordered_map<string,unordered_map<string,unordered_map<string,int>>> serie;

    for(unordered_set<string>::const_iterator sensor1 = sensorsId.cbegin();sensor1 != sensorsId.cend();++sensor1)
    {
        similitude.insert(make_pair(*sensor1,unordered_map<string,bool>()));
        serie.insert(make_pair(*sensor1,unordered_map<string,unordered_map<string,int>>()));
        for(unordered_set<string>::const_iterator sensor2 = sensorsId.cbegin();sensor2 != sensorsId.cend();++sensor2)
        {
            if(*sensor1 != *sensor2)
            {
                similitude[*sensor1].insert(make_pair(*sensor2,false));
                serie[*sensor1].insert(make_pair(*sensor2,unordered_map<string,int>()));
                for(unordered_map<string,Attribute>::const_iterator gaz = attributes.cbegin();gaz != attributes.cend();++gaz)
                {
                    serie[*sensor1][*sensor2].insert(make_pair(gaz->first,0));
                }
            }
        }
    }

    Measure meas;
    string attrIdMeas;
    string sensorIdMeas;
    Date dateMeas;
    double valueMeas;
    unordered_map<string,unordered_map<string,double>> valeursPrec;
    while(request.goToNext())
    {
        meas = request.getMeasure();
        attrIdMeas = meas.getAttributeId();
        sensorIdMeas = meas.getSensorId();
        dateMeas = meas.getDate();
        valueMeas = meas.getValue();

        if ((dateMeas - time).toSeconds() >= 30*60){
            time = dateMeas;
            valeursPrec.clear();
        }

        for(unordered_map<string,unordered_map<string,double>>::const_iterator vPrec = valeursPrec.cbegin();vPrec != valeursPrec.cend();++vPrec)
        {
            if(sensorIdMeas != vPrec->first)
            {
                for(unordered_map<string,double>::const_iterator gazPrec = vPrec->second.cbegin();gazPrec != vPrec->second.cend();++gazPrec)
                {
                    if(gazPrec->first == attrIdMeas)
                    {
                        if(abs(gazPrec->second - valueMeas) < epsilon)
                        {
                            serie[sensorIdMeas][vPrec->first][gazPrec->first] += 1;
                            serie[vPrec->first][sensorIdMeas][gazPrec->first] += 1;
                            if(serie[sensorIdMeas][vPrec->first][gazPrec->first] >= serieSuffisante)
                            {
                                similitude[sensorIdMeas][vPrec->first] = true;
                                similitude[vPrec->first][sensorIdMeas] = true;
                            }
                        }
                        else
                        {
                            serie[sensorIdMeas][vPrec->first][gazPrec->first] = 0;
                            serie[vPrec->first][sensorIdMeas][gazPrec->first] = 0;
                        }
                    }
                }
            }
        }

        if(valeursPrec.find(sensorIdMeas) == valeursPrec.end())
        {
            valeursPrec.insert(make_pair(sensorIdMeas,unordered_map<string,double>()));
            valeursPrec[sensorIdMeas].insert(make_pair(attrIdMeas,valueMeas));
        }
        else
        {
            if(valeursPrec[sensorIdMeas].find(attrIdMeas) == valeursPrec[sensorIdMeas].end())
            {
                valeursPrec[sensorIdMeas].insert(make_pair(attrIdMeas,valueMeas));
            }
            else
            {
                valeursPrec[sensorIdMeas][attrIdMeas] = valueMeas;
            }
        }
    }

    //Retour par réference
}

unordered_map<string,Sensor> Services::listerCapteurs(Point p, double rayon)
{
    unordered_set<string> sensorsId = getSensorsTerritoryIds(p, rayon);
    unordered_map<string,Sensor> res;
    for(unordered_set<string>::const_iterator idS = sensorsId.cbegin();idS != sensorsId.cend();++idS)
    {
        res.insert(make_pair(*idS,sensors[*idS]));
    }
    return res;
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
    //cout << "Nombre de capteurs : " << sensors.size() << endl;
    //cout << "Nombre d'attributs : " << attributes.size() << endl;
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
