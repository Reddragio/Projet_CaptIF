//---------- Interface de la classe <CaptIF> (fichier CaptIF.h) ----------------
#ifndef PROJET_CAPTIF_CAPTIF_H
#define PROJET_CAPTIF_CAPTIF_H

//--------------------------------------------------- Interfaces utilisées
#include "Services.h"
#include "Input.h"
#include "Output.h"
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CaptIF>
//
//
//------------------------------------------------------------------------

class CaptIF
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void run();

    //-------------------------------------------- Constructeurs - Destructeur

    CaptIF();

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées
    Services services;
    Input input;
    Output output;
    //----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <CaptIF>

#endif // CAPTIF_H