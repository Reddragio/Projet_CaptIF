/*************************************************************************
Input
-------------------
Date                 : 05/05/2019
Copyright            :
*************************************************************************/

//---------- Réalisation de la classe <Input> (fichier Input.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système


//------------------------------------------------------ Include personnel
#include "Input.h"
#include <regex>

//------------------------------------------------------------- Constantes
static const regex patternDate(R"(\d{4}/\d{2}/\d{2}-\d{2}:\d{2}:\d{2})");

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

Point Input::rentrerPoint()
{
    string texte;
    double latitude,longitude;
    bool conversionReussie = true;

    cout << "Latitude du point:" << endl;
    do {
        conversionReussie = true;
        cin >> texte;
        try {
            latitude = stod(texte);
        }
        catch (const std::invalid_argument&) {
            conversionReussie = false;
        }
        catch (const std::out_of_range&) {
            conversionReussie = false;
        }
        if (!conversionReussie) {
            cout << "Latitude incorrecte." << endl;
        }
    } while (!conversionReussie);


    cout << "Longitude du point : " << endl;
    do {
        conversionReussie = true;
        cin >> texte;
        try {
            longitude = stod(texte);
        }
        catch (const std::invalid_argument&) {
            conversionReussie = false;
        }
        catch (const std::out_of_range&) {
            conversionReussie = false;
        }
        if (!conversionReussie) {
            cout << "Longitude incorrecte." << endl;
        }
    } while (!conversionReussie);



    return Point(latitude,longitude);
}

double Input::rentrerRayon()
{
    string texte;
    double res;
    bool conversionReussie = true;
    cout << "Rayon : " << endl;
    do {
        conversionReussie = true;
        cin >> texte;
        try {
            res = stod(texte);
        }
        catch (const std::invalid_argument&) {
            conversionReussie = false;
        }
        catch (const std::out_of_range&) {
            conversionReussie = false;
        }
        if (!conversionReussie) {
            cout << "Rayon incorrect." << endl;
        }
    } while (!conversionReussie);
    return res;
}

void Input::parseDate(const string & texte,int & annee,int & mois,int & jour,int & heure,int & minute,int & seconde){
    int begin=0;
    int end=0;
    begin = 0;
    end = texte.find('/',begin);
    annee = stoi(texte.substr(begin,end-begin));
    begin = end+1;
    end = texte.find('/',begin);
    mois = stoi(texte.substr(begin,end-begin));
    begin = end+1;
    end = texte.find('-',begin);
    jour = stoi(texte.substr(begin,end-begin));
    begin = end+1;
    end = texte.find(':',begin);
    heure = stoi(texte.substr(begin,end-begin));
    begin = end+1;
    end = texte.find(':',begin);
    minute = stoi(texte.substr(begin,end-begin));
    begin = end+1;
    end = 19;
    seconde = stoi(texte.substr(begin,end-begin));
}

tuple<Date, Date> Input::rentrerDebutFin()
{
    string texte;
    Date debut;
    Date fin;
    int annee1;
    int mois1;
    int jour1;
    int heure1;
    int minute1;
    int seconde1;
    int milliseconde = 0;

    bool conversionReussie = false;
    do {
        cout << "Veuillez entrer la date de debut de la recherche: (Format: YYYY/MM/DD-HH:MM:SS)" << endl;
        cin >> texte;
        if(regex_match(texte,patternDate)){
            parseDate(texte,annee1,mois1,jour1,heure1,minute1,seconde1);
            debut = Date(annee1,mois1,jour1,heure1,minute1,seconde1,milliseconde);
            conversionReussie = true;
        }
        else{
            cout << "Date incorrecte." << endl;
        }
    } while (!conversionReussie);
    conversionReussie = false;
    do {
        cout << "Veuillez entrer la date de fin de la recherche: (Format: YYYY/MM/DD-HH:MM:SS)" << endl;
        cin >> texte;
        if(regex_match(texte,patternDate)){
            parseDate(texte,annee1,mois1,jour1,heure1,minute1,seconde1);
            fin = Date(annee1,mois1,jour1,heure1,minute1,seconde1,milliseconde);
            if(debut<=fin){
                conversionReussie = true;
            }else{
                cout << "Date incorrecte. La date fin doit etre plus grande que la date debut" << endl;
            }
        }
        else{
            cout << "Date incorrecte." << endl;
        }
    } while (!conversionReussie);

    return make_tuple(debut,fin);
}

Date Input::rentrerMoment()
{
    string texte;
    Date moment;
    int annee;
    int mois;
    int jour;
    int heure;
    int minute;
    int seconde;
    int milliseconde = 0;
    bool conversionReussie = false;
    do {
        cout << "Veuillez entrer le moment de la recherche : (Format: YYYY/MM/DD-HH:MM:SS)" << endl;
        cin >> texte;
        if(regex_match(texte,patternDate)){
            parseDate(texte,annee,mois,jour,heure,minute,seconde);
            moment = Date(annee,mois,jour,heure,minute,seconde,milliseconde);
            conversionReussie = true;
        }
        else{
            cout << "Moment incorrect." << endl;
        }
    } while (!conversionReussie);
    return moment;
}

string Input::rentrerIdCapteur()
{
    string res;
    cout << "Id du capteur : " << endl;
    do {
        cin >> res;

    } while (res=="");
    return res;
}

int Input::choisirMethode()
{
    string texte;
    int res;
    bool conversionReussie = true;
    cout << "Quelle methode souhaitez vous executer ?" << endl;
    cout << "(Tapez 0 pour quitter)" << endl;
    do {
        conversionReussie = true;
        cin >> texte;
        try {
            res = stoi(texte);
        }
        catch (const std::invalid_argument&) {
            conversionReussie = false;
        }
        catch (const std::out_of_range&) {
            conversionReussie = false;
        }
        if (!conversionReussie || !(0<=res && res<=9)) {
            cout << "Numero incorrect." << endl;
        }
    } while (!conversionReussie && res>=0 && res<=9);
    return res;
}

//-------------------------------------------- Constructeurs - destructeur

Input::Input() {

}

Input::~Input() {

}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
