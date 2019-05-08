/*************************************************************************
Sensor
-------------------
Date                 : 05/05/2019
Copyright            :
*************************************************************************/

//---------- Interface de la classe <Sensor> (fichier Sensor.h) ----------------
#ifndef PROJET_CAPTIF_SENSOR_H
#define PROJET_CAPTIF_SENSOR_H

//--------------------------------------------------- Interfaces utilisées
#include "Measure.h"
#include "Attribute.h"
#include "Point.h"

#include <vector>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types



class Sensor {
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques

    //------------------------------------------------- Surcharge d'opérateurs
    //ostream & operator << (ostream & out, const Sensor & sensor);
    //-------------------------------------------- Constructeurs - destructeur

    Sensor(string id, Point location, string description);

    virtual ~Sensor();


    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    string id;
    string status;
    string description;
    Point location;
    vector<Measure> measures;
    vector<Attribute> attributes;

};

//-------------------------------- Autres définitions dépendantes de <Reader>

#endif

