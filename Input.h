//---------- Interface de la classe <Input> (fichier Input.h) ----------------
#ifndef PROJET_CAPTIF_INPUT_H
#define PROJET_CAPTIF_INPUT_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <iostream>
#include <string>

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

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées
    istream inputStream;
    //----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Input>

#endif // INPUT_H