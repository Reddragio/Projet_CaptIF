/*************************************************************************
Measure
-------------------
Date                 : 05/05/2019
Copyright            :
*************************************************************************/

//---------- Réalisation de la classe <Measure> (fichier Measure.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système


//------------------------------------------------------ Include personnel
#include <cmath>

#include "Measure.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string Measure::getAttributeId() const
{
    return attributeId;
}

string Measure::getSensorId() const
{
    return sensorId;
}

double Measure::getValue() const
{
    return value;
}

Date Measure::getDate() const
{
    return dateMeasure;
}
//-------------------------------------------- Constructeurs - destructeur

Measure::Measure() {
#ifdef MAP
    cout << "Appel au constructeur de <Measure>" << "\r\n";
#endif

}

Measure::Measure(const string &sensorId, const string &attributeId, const Date &dateMeasure, double value) : sensorId(sensorId), attributeId(attributeId), dateMeasure(dateMeasure), value(value)
{

}

Measure::~Measure() {
#ifdef MAP
    cout << "Appel au destructeur de <Top10>" << "\r\n";
#endif
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

