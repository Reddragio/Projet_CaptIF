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
    return tuple<Date, Date>();
}

Date Input::rentrerMoment()
{
    return Date();
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

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
