/*************************************************************************
Parser
-------------------
Date                 : 05/05/2019
Copyright            :
*************************************************************************/

//---------- Interface de la classe <Parser> (fichier Parser.h) ----------------
#ifndef PROJET_CAPTIF_PARSER_H
#define PROJET_CAPTIF_PARSER_H

#include "RequestView.h"

#include<vector>

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <tuple>
#include <string>
using namespace std;

#include "Sensor.h"
#include "Date.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types



class Parser {
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques

    void getSensorsAndAttributes(vector<Sensor> & resSensors,vector<Attribute> & resAttributes) const;

    set<Measure> getMeasures(const set<string> & sensorIds,Date debut, Date fin);

    RequestView getRequestView(const set<string> & sensorIds,Date debut, Date fin);

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur

    Parser();

    Parser(const vector<string> & filesInit);

    virtual ~Parser();


    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    vector<string> files;

};

//-------------------------------- Autres définitions dépendantes de <Parser>

#endif
