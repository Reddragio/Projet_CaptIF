 /*************************************************************************
Sensor
-------------------
Date                 : 05/05/2019
Copyright            :
*************************************************************************/

//---------- Réalisation de la classe <Sensor> (fichier Sensor.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système


//------------------------------------------------------ Include personnel
#include "Sensor.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

Point Sensor::getLocation() const{
    return location;
}

string Sensor::getDescription() const {
    return description;
}

//------------------------------- Surcharge des opérateurs d'Entrée/Sortie

ostream & operator << (ostream & out, const Sensor & sensor) {
    out << "ID : " << sensor.id << ", Desc : " << sensor.description << ", Status : " << boolalpha << sensor.status << ", Location : " << sensor.location;
    return out;
}

//-------------------------------------------- Constructeurs - destructeur

Sensor::Sensor(string id, Point location, string description) {
    this->id = id;
    this->status = true;
    this->location = location;
    this->description = description;
#ifdef MAP
    cout << "Appel au constructeur de <Point>" << "\r\n";
#endif

}

Sensor::Sensor() {
    this->id = "";
    this->status = true;
    this->location = Point();
    this->description = "";
#ifdef MAP
    cout << "Appel au constructeur de <Point>" << "\r\n";
#endif

}

Sensor::~Sensor() {
#ifdef MAP
    cout << "Appel au destructeur de <Top10>" << "\r\n";
#endif
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
