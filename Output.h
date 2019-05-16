/*************************************************************************
Output
-------------------
Date                 : 05/05/2019
Copyright            :
*************************************************************************/

//---------- Interface de la classe <Output> (fichier Output.h) ----------------
#ifndef PROJET_CAPTIF_OUTPUT_H
#define PROJET_CAPTIF_OUTPUT_H

//--------------------------------------------------- Interfaces utilisées
#include <tuple>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

#include "Date.h"
#include "Point.h"
#include "Sensor.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types



class Output {
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    void afficherMessageAccueil();
    void afficherMenu();
    void afficherCapteurs(const vector<Sensor> & sensors);

    void afficherResultatATMO(int methode, const map<string,tuple<int, double, int>> & resultat);
    void afficherEvolution(const tuple<double, double, double, Date> & resultat);

    void afficherCapteursEtBugs(const vector<tuple<Sensor, int>> & resultat);
    void afficherSimilarites(const vector<vector<Sensor>> & resultat);

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - Destructeur

    Output(const unordered_map<string, Sensor> &sensors, const unordered_map<string, Attribute> &attributes);

    Output();

    //virtual ~Output();


    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    unordered_map<string,Sensor> sensors;
    unordered_map<string,Attribute> attributes;


};

//-------------------------------- Autres définitions dépendantes de <Reader>

#endif


