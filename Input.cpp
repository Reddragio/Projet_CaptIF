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

//------------------------------------------------------------- Constantes

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
            cout << "Latitude incorrecte. Réessayez." << endl;
        }
    } while (!conversionReussie);


    cout << "Longitude du point:" << endl;
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
            cout << "Longitude incorrecte. Réessayez." << endl;
        }
    } while (!conversionReussie);



    return Point(latitude,longitude);
}

double Input::rentrerRayon()
{
    string texte;
    double res;
    bool conversionReussie = true;
    cout << "Rayon souhaitée:" << endl;
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
            cout << "Rayon incorrecte. Réessayez." << endl;
        }
    } while (!conversionReussie);
    return res;
}

tuple<Date, Date> Input::rentrerDebutFin()
{
    Date debut;
    Date fin;
    int annee1;
    int mois1;
    int jour1;
    int heure1;
    int minute1;
    int seconde1;
    int annee2;
    int mois2;
    int jour2;
    int heure2;
    int minute2;
    int seconde2;
    int milliseconde = 0;
    bool conversionReussie = true;

    do {
        cout << "Veuillez rentrez la date début de la recherche: (exemple: 2000 01 01 00 00 00)" << endl;
        cin >> annee1 >> mois1 >> jour1 >> heure1 >> minute1 >> seconde1;
        cout << "Veuillez rentrez la date fin de la recherche: (exemple: 2000 01 01 00 00 00)" << endl;
        cin >> annee2>> mois2 >> jour2 >> heure2 >> minute2 >> seconde2;
        try {
            debut = Date(annee1,mois1,jour1,heure1,minute1,seconde1,milliseconde);
            fin = Date(annee2,mois2,jour2,heure2,minute2,seconde2,milliseconde);
        }
        catch (const std::invalid_argument&) {
            conversionReussie = false;
        }
        catch (const std::out_of_range&) {
            conversionReussie = false;
        }
        if(debut>fin){
            cout << "Date début et date fin incohérente" << endl;
            conversionReussie = false;
        }else if (!conversionReussie) {
            cout << "Date incorrecte. Réessayez." << endl;
        }
    } while (!conversionReussie);

    return tuple<Date, Date>();
}

Date Input::rentrerMoment()
{
    Date moment;
    int annee;
    int mois;
    int jour;
    int heure;
    int minute;
    int seconde;
    int milliseconde = 0;
    bool conversionReussie = true;
    do {
        cout << "Veuillez rentrez le moment rechercher: (exemple: 2000 01 01 00 00 00)" << endl;
        cin >> annee >> mois >> jour >> heure >> minute >> seconde;
        try {
            moment = Date(annee,mois,jour,heure,minute,seconde,milliseconde);
        }
        catch (const std::invalid_argument&) {
            conversionReussie = false;
        }
        catch (const std::out_of_range&) {
            conversionReussie = false;
        }
        if (!conversionReussie) {
            cout << "Moment incorrecte. Réessayez." << endl;
        }
    } while (!conversionReussie);
    return moment;
}

int Input::rentrerIdCapteur()
{
    string texte;
    int res;
    bool conversionReussie = true;
    cout << "Id du capteur:" << endl;
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
        if (!conversionReussie) {
            cout << "Id incorrecte. Réessayez." << endl;
        }
    } while (!conversionReussie);
    return res;
}

int Input::choisirMethode()
{
    string texte;
    int res;
    bool conversionReussie = true;
    cout << "Quel méthode souhaitez vous executer ?" << endl;
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
        if (!conversionReussie || !(1<=res && res<=8)) {
            cout << "Numero incorrecte. Réessayez." << endl;
        }
    } while (!conversionReussie);
    return res;
}

//-------------------------------------------- Constructeurs - destructeur

Input::Input() {

}

Input::~Input() {

}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
