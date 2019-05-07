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

tuple<vector<Sensor>,vector<Attribute>> Parser :: getSensorsAndAttributes()
{
    vector<Sensor> sensors;
    vector<Attribute> attributes;


}

set<Measure> Parser :: getMeasures(set<String> sensorIds, Date debut, Date fin)
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

RequestView Parser :: getRequestView(set<String> sensorIds,Date debut, Date fin);
{

}



//-------------------------------------------- Constructeurs - destructeur

Parser::Parser(vector<String> files,RequestView requestView>) {
this.files = files;
this.requestView = requestView;
#ifdef MAP
cout << "Appel au constructeur de <Parser>" << "\r\n";
#endif

}

Parser::~Parser() {
#ifdef MAP
    cout << "Appel au destructeur de <Top10>" << "\r\n";
#endif
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


--
