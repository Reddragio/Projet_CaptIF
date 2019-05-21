/*************************************************************************
RequestView
-------------------
Date                 : 05/05/2019
Copyright            :
*************************************************************************/

//---------- Réalisation de la classe <RequestView> (fichier RequestView.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <regex>

//------------------------------------------------------ Include personnel
#include "RequestView.h"
#include "Measure.h"

//------------------------------------------------------------- Constantes
static const regex patternMeasure(R"(\d{4}-\d{2}-\d{2}T\d{2}:\d{2}:\d{2}\.\d+;\w+;\w+;(-?\d+\.\d+);)");

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool RequestView::goToNext()
{
    string line;
    int begin=0;
    int end=0;
    //Date
    Date dateMeasure;
    int annee;
    int mois;
    int jour;
    int heure;
    int minute;
    int seconde;
    int msec;
    //Le reste:
    string sensorId;
    string attributeId;
    double valeur;

    while(indexFile < files.size()){
        /*if(first){
            actualFile = ifstream(files[indexFile]);
            first=false;
        }*/
        while(actualFile){
            getline(actualFile,line);
            if(line.length() >= 17 && line[16] == ':'){
                //regex_match(line,patternMeasure)
                //Les regex sont plus elegants mais bien plus couteux malheuresement :/
                //On parse la mesure:
                begin = 0;
                end = line.find('-',begin);
                annee = stoi(line.substr(begin,end-begin));
                begin = end+1;
                end = line.find('-',begin);
                mois = stoi(line.substr(begin,end-begin));
                begin = end+1;
                end = line.find('T',begin);
                jour = stoi(line.substr(begin,end-begin));
                begin = end+1;
                end = line.find(':',begin);
                heure = stoi(line.substr(begin,end-begin));
                begin = end+1;
                end = line.find(':',begin);
                minute = stoi(line.substr(begin,end-begin));
                begin = end+1;
                end = line.find('.',begin);
                seconde = stoi(line.substr(begin,end-begin));
                begin = end+1;
                end = line.find(';',begin);
                msec = stoi(line.substr(begin,3));
                begin = end+1;
                end = line.find(';',begin);
                sensorId = line.substr(begin,end-begin);
                begin = end+1;
                end = line.find(';',begin);
                attributeId = line.substr(begin,end-begin);
                begin = end+1;
                end = line.find(';',begin);
                valeur = stod(line.substr(begin,end-begin));

                dateMeasure = Date(annee,mois,jour,heure,minute,seconde,msec);
                if(sensorsIds.find(sensorId) != sensorsIds.end() && debut <= dateMeasure && fin < dateMeasure){
                    //Si la mesure est dans la zone et la période qui nous interesse

                    //Construction de la measure:
                    actualMeasure = Measure(sensorId,attributeId,dateMeasure,valeur);
                    //on indique qu'une mesure a été trouvée
                    return true;
                }
            }
        }
        actualFile.close();
        ++indexFile;
        if(indexFile < files.size()){
            actualFile = ifstream(files[indexFile]);
        }
    }
    return false;
}

Measure RequestView::getMeasure()
{
    return actualMeasure;
}


//-------------------------------------------- Constructeurs - destructeur

RequestView::RequestView(vector<string> filesInit, unordered_set<string> sensorsIdsInit, Date debutInit, Date finInit) {
    files = filesInit;
    sensorsIds = sensorsIdsInit;
    debut = debutInit;
    fin = finInit;
    first = true;

    indexFile = 0;
    if(filesInit.size() > 0){
        actualFile = ifstream(filesInit[indexFile]);
    }

#ifdef MAP
    cout << "Appel au constructeur de <RequestView>" << "\r\n";
#endif
}

RequestView::RequestView() {

#ifdef MAP
    cout << "Appel au constructeur de <RequestView>" << "\r\n";
#endif

}

RequestView::~RequestView() {
    //actualFile.close();

#ifdef MAP
    cout << "Appel au destructeur de <Top10>" << "\r\n";
#endif
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
