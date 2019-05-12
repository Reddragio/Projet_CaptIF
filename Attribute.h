/*************************************************************************
Attribute
-------------------
Date                 : 05/05/2019
Copyright            :
*************************************************************************/

//---------- Interface de la classe <Attribute> (fichier Attribute.h) ----------------
#ifndef PROJET_CAPTIF_ATTRIBUTE_H
#define PROJET_CAPTIF_ATTRIBUTE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "Attribute.h"
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types



class Attribute {
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques


    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur

    Attribute();

    Attribute(const string &id, const string &unit, const string &description);

    virtual ~Attribute();


    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    string id;
    string unit;
    string description;
};

//-------------------------------- Autres définitions dépendantes de <Reader>

#endif


