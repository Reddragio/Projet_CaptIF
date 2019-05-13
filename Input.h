//---------- Interface de la classe <Input> (fichier Input.h) ----------------
#ifndef PROJET_CAPTIF_INPUT_H
#define PROJET_CAPTIF_INPUT_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <iostream>
#include <string>
#include <tuple>

#include "Date.h"
#include "Point.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Input>
//
//
//------------------------------------------------------------------------

class Input
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    Point rentrerPoint();

    double rentrerRayon();

    tuple<Date, Date> rentrerDebutFin();

    Date rentrerMoment();

    int rentrerIdCapteur();

    int choisirMethode();

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - Destructeur

    Input();

    virtual ~Input();

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    void parseDate(const string & texte,int & annee,int & mois,int & jour,int & heure,int & minute,int & seconde);

    //----------------------------------------------------- Attributs protégés

    //istream inputStream;

};

//-------------------------------- Autres définitions dépendantes de <Input>

#endif // INPUT_H