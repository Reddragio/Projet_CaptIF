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
    friend ostream & operator << (ostream & out, const Sensor & sensor);

    Point getLocation() const;

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

};

//-------------------------------- Autres définitions dépendantes de <Reader>

#endif

