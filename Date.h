//---------- Interface de la classe <Date> (fichier Date.h) ----------------
#ifndef PROJET_CAPTIF_DATE_H
#define PROJET_CAPTIF_DATE_H

//--------------------------------------------------- Interfaces utilisées
#include <ctime>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Date>
//
//
//------------------------------------------------------------------------

class Date
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    Date();

    Date(time_t tempsInit);

    bool operator<=(const Date & d2);

    bool operator<(const Date & d2);

    bool operator>=(const Date & d2);

    bool operator>(const Date & d2);

    bool operator==(const Date & d2);

    int toMinutes();

    int toSeconds();


    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées
    time_t temps;
    //----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Date>

#endif // DATE_H