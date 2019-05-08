/*************************************************************************
Parser
-------------------
Date                 : 05/05/2019
Copyright            :
*************************************************************************/

//---------- Réalisation de la classe <Parser> (fichier Parser.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système


//------------------------------------------------------ Include personnel
#include "Parser.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Parser::getSensorsAndAttributes(vector<Sensor> & resSensors,vector<Attribute> & resAttributes)
{

}

set<Measure> Parser::getMeasures(const set<string> & sensorIds,Date debut, Date fin)
{
    boolean next = true;
    set<Measure> measures;
    requestView.debut = debut;
    requestView.fin = fin;
    while(next)
    {
        if(requestView.actualMeasure.dateMeasure <= fin && requestView.actualMeasure.dateMeasure >= debut)
        {
            measures.insert(getMeasure());
            next = goToNext();
        }
    }
    return measures;
}

RequestView Parser::getRequestView(const set<string> & sensorIds,Date debut, Date fin)
{

}



//-------------------------------------------- Constructeurs - destructeur

Parser::Parser(const vector<string> & filesInit) {
    files = filesInit;
    #ifdef MAP
    cout << "Appel au constructeur de <Parser>" << "\r\n";
    #endif

}

Parser::~Parser() {
#ifdef MAP
    cout << "Appel au destructeur de <Parser>" << "\r\n";
#endif
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


