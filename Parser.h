/*************************************************************************
Parser
-------------------
Date                 : 05/05/2019
Copyright            :
*************************************************************************/

/* Cette classe permet de créer le fichier nécessaire pour visualiser les
interactions entre les différents noeuds */

//---------- Interface de la classe <Parser> (fichier Parser.h) ----------------
#ifndef PROJET_CAPTIF_PARSER_H
#define PROJET_CAPTIF_PARSER_H

#include "RequestView.h"

#include<vector>

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types



class Parser {
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques

    tuple<vector<Sensor>,vector<Attribute>> getToNext();

    set<Measure> getMeasures(set<String> sensorIds, Date debut, Date fin);

    RequestView getRequestView(set<String> sensorIds,Date debut, Date fin);

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur

    Parser();

    Parser(vector<String> files)

    virtual ~Parser();


    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    vector<String> files;

    RequestView requestView;

};

//-------------------------------- Autres définitions dépendantes de <Reader>

#endif
