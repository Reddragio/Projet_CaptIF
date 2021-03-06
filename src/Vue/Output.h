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

#include "../Modele/Date.h"
#include "../Modele/Point.h"
#include "../Modele/Sensor.h"
#include "../Controleur/Services.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types



class Output {
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    void afficherMessageAccueil(const Services & services);
    void afficherMessageFinProg();
    void afficherMenu();
    void afficherCapteurs(const unordered_map<string,Sensor> & sensors);

    void afficherResultatATMO(int methode, const map<string,tuple<int, double, int>> & resultat);
    void afficherEvolution(int methode, const map<string,tuple<double, double, double, Date>> & resultat);

    void afficherCapteursEtBugs(const unordered_map<string,bool> & fonctionnel);
    void afficherSimilarites(const unordered_map<string,unordered_map<string,bool>> & resultat);
    void afficherResultatCapteur(bool resultat,string & idCapteur);

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


