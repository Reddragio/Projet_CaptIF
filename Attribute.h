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

#include "Attribute.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types



class Attribute {
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques


    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur

    Attribute();

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


