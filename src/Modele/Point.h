/*************************************************************************
Point
-------------------
Date                 : 05/05/2019
Copyright            :
*************************************************************************/

//---------- Interface de la classe <Sensor> (fichier Point.h) ----------------
#ifndef PROJET_CAPTIF_POINT_H
#define PROJET_CAPTIF_POINT_H

//--------------------------------------------------- Interfaces utilisées
#include <ostream>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types



class Point {
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    double distance(Point p);

    double getLat();

    double getLng();

    //------------------------------------------------- Surcharge d'opérateurs

    friend ostream & operator << (ostream & out, const Point & p);

    //-------------------------------------------- Constructeurs - destructeur

    Point(double latitude, double longitude);

    Point();

    virtual ~Point();


    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    double latitude;
    double longitude;

};

//-------------------------------- Autres définitions dépendantes de <Reader>

#endif



