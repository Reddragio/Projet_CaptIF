/*************************************************************************
Measure
-------------------
Date                 : 05/05/2019
Copyright            :
*************************************************************************/

//---------- Interface de la classe <Measure> (fichier Measure.h) ----------------
#ifndef PROJET_CAPTIF_MEASURE_H
#define PROJET_CAPTIF_MEASURE_H

//--------------------------------------------------- Interfaces utilisées
#include "Attribute.h"
#include "Date.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types



class Measure {
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur

    Measure();

    virtual ~Measure();


    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    Attribute attribute;
    Date dateMeasure;
    double value;

};

//-------------------------------- Autres définitions dépendantes de <Reader>

#endif


