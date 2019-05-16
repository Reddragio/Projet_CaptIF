/*************************************************************************
RequestView
-------------------
Date                 : 05/05/2019
Copyright            :
*************************************************************************/

/* Cette classe permet de créer le fichier nécessaire pour visualiser les
interactions entre les différents noeuds */

//---------- Interface de la classe <RequestView> (fichier RequestView.h) ----------------
#ifndef PROJET_CAPTIF_REQUESTVIEW_H
#define PROJET_CAPTIF_REQUESTVIEW_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <fstream>
#include <unordered_set>
#include <string>
using namespace std;

#include "Measure.h"
#include "Date.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types



class RequestView {
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques

    bool goToNext();

    Measure getMeasure();

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur

    RequestView(vector<string> filesInit, unordered_set<string> sensorsIdsInit, Date debutInit, Date finInit);

    RequestView();

    virtual ~RequestView();

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    vector<string> files;
    ifstream actualFile;
    int indexFile;
    bool first;

    Measure actualMeasure;

    unordered_set<string> sensorsIds;
    Date debut;
    Date fin;

};

//---------------------------- Autres définitions dépendantes de <RequestView>

#endif
