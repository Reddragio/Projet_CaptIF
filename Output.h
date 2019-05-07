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

    void afficherResultatATMO(int methode, const vector<tuple<Attribute, int, double, int>> & resultat);
    void afficherEvolution(const tuple<double, double, double, Date> & resultat);

    void afficherCapteursEtBugs(const vector<tuple<Sensor, int>> & resultat);
    void afficherSimilarites(const vector<vector<Sensor>> & resultat);

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - Destructeur

    Output();

    virtual ~Output();


    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    ostream outputStream;


};

//-------------------------------- Autres définitions dépendantes de <Reader>

#endif


