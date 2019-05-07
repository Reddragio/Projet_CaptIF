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

#include <vector>
#include <fstream>
#include <set>


//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types



class RequestView {
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques

    boolean goToNext();

    Measure getMeasure();

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur

    RequestView();



    virtual ~RequestView();


    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    vector<String> files;
    ifstream actualFile;
    int indexFile;

    Measure actualMeasure;

    set<String> sensorsIds;
    Date debut;
    Date fin;


};

//-------------------------------- Autres définitions dépendantes de <Reader>

#endif
