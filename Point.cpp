/*************************************************************************
Point
-------------------
Date                 : 05/05/2019
Copyright            :
*************************************************************************/

//---------- Réalisation de la classe <Point> (fichier Point.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système


//------------------------------------------------------ Include personnel
#include <cmath>

#include "Point.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

double Point::distance(Point p) {
    double d;
    d = sqrt((latitude - p.latitude)*(latitude - p.latitude) + (longitude - p.longitude)*(latitude - p.longitude));
    return d;
}

/*
ostream & operator << (ostream & out, const Point & p) {
    out << "( " << p.longitude << "," << p.latitude " ) ";
    return out;
}*/




//-------------------------------------------- Constructeurs - destructeur

Point::Point(double latitude, double longitude) {
    this->latitude = latitude;
    this->longitude = longitude;
#ifdef MAP
    cout << "Appel au constructeur de <Point>" << "\r\n";
#endif

}

Point::~Point() {
#ifdef MAP
    cout << "Appel au destructeur de <Top10>" << "\r\n";
#endif
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

