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
    double fConv = 3.14159265358979323846/180.0;
    double lat1 = latitude*fConv;
    double lon1 = longitude*fConv;
    double lat2 = p.latitude*fConv;
    double lon2 = p.longitude*fConv;
    d= acos(sin(lat1)*sin(lat2)+cos(lat1)*cos(lat2)*cos(lon2-lon1))*6371;
    return d;
}

double Point::getLat(){
    return latitude;
}

double Point::getLng(){
    return longitude;
}

//------------------------------- Surcharge des opérateurs d'Entrée/Sortie

ostream & operator << (ostream & out, const Point & p) {
    out << "(" << p.latitude << "," << p.longitude <<")";
    return out;
}

//-------------------------------------------- Constructeurs - destructeur

Point::Point(double latitude, double longitude) {
    this->latitude = latitude;
    this->longitude = longitude;
#ifdef MAP
    cout << "Appel au constructeur de <Point>" << "\r\n";
#endif

}

Point::Point() {
    this->latitude = 0.0;
    this->longitude = 0.0;
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

