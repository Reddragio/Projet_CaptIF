/*************************************************************************
Parser
-------------------
Date                 : 05/05/2019
Copyright            :
*************************************************************************/

//---------- Réalisation de la classe <Parser> (fichier Parser.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <fstream>
#include <regex>
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Parser.h"

//------------------------------------------------------------- Constantes
static const regex patternSensor(R"([[:print:]]+;(-?\d+\.\d+);(-?\d+\.\d+);[[:print:]]*;)");
static const regex patternAttribute(R"([[:print:]]+;[^[:print:]]{0,2}[[:print:]]+/[[:print:]]+;[[:print:]]*;)");

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Parser::getSensorsAndAttributes(unordered_map<string,Sensor> & resSensors,unordered_map<string,Attribute> & resAttributes) const
{
    string line;
    int debut=0;
    int fin=0;
    //variables liées au Sensor:
    string idSensor;
    double latitude;
    double longitude;
    string descSensor;
    //variables liées à l'Attribute:
    string idAttribute;
    string unit;
    string descAttribute;
    for(vector<string>::const_iterator nameFile = files.cbegin();nameFile != files.cend();++nameFile)
    {
        //Ouverture du fichier
        ifstream file(*nameFile);
        //Lecture de ses données
        while(file){
            getline(file,line);
            //cout << line << endl;
            if(!(line.length() >= 17 && line[16] == ':')){
                //Si ce n'est pas une ligne qui contient une mesure
                if(regex_match(line,patternSensor))
                {
                    debut = 0;
                    fin = line.find(';',debut);
                    idSensor = line.substr(debut,fin-debut);
                    debut = fin+1;
                    fin = line.find(';',debut);
                    latitude = stod(line.substr(debut,fin-debut));
                    debut = fin+1;
                    fin = line.find(';',debut);
                    longitude = stod(line.substr(debut,fin-debut));
                    debut = fin+1;
                    fin = line.find(';',debut);
                    descSensor = line.substr(debut,fin-debut);
                    //Ajout du nouveau Sensor:
                    resSensors.insert(make_pair(idSensor,Sensor(idSensor,Point(latitude,longitude),descSensor)));
                }
                else if(regex_match(line,patternAttribute))
                {
                    debut = 0;
                    fin = line.find(';',debut);
                    idAttribute = line.substr(debut,fin-debut);
                    debut = fin+1;
                    fin = line.find(';',debut);
                    unit = line.substr(debut,fin-debut);
                    debut = fin+1;
                    fin = line.find(';',debut);
                    descAttribute = line.substr(debut,fin-debut);
                    //Ajout du nouvel Attribute:
                    resAttributes.insert(make_pair(idAttribute,Attribute(idAttribute,unit,descAttribute)));
                }
            }
        }
        //fermeture du fichier
        file.close();
    }
}

set<Measure> Parser::getMeasures(const set<string> & sensorIds,Date debut, Date fin)
{
    /*boolean next = true;
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
    return measures;*/
    return set<Measure>();
}

RequestView Parser::getRequestView(const unordered_set<string> & sensorIds,Date debut, Date fin)
{
    return RequestView(files,sensorIds,debut,fin);
}



//-------------------------------------------- Constructeurs - destructeur

Parser::Parser(const vector<string> & filesInit) {
    files = filesInit;
    #ifdef MAP
    cout << "Appel au constructeur de <Parser>" << "\r\n";
    #endif

}

Parser::Parser() {
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


