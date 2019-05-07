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
    Date() {
        temps = time(nullptr);
    }

    Date(time_t tempsInit) {
        temps = tempsInit;
    }

    bool operator<=(const Date & d2)
    {
        double diff = difftime(temps, d2.temps);
        return diff <= 0;
    }

    bool operator<(const Date & d2)
    {
        double diff = difftime(temps, d2.temps);
        return diff < 0;
    }

    bool operator>=(const Date & d2)
    {
        double diff = difftime(temps, d2.temps);
        return diff >= 0;
    }

    bool operator>(const Date & d2)
    {
        double diff = difftime(temps, d2.temps);
        return diff > 0;
    }

    bool operator==(const Date & d2)
    {
        return temps == d2.temps;
    }

    Date operator-(const Date & d2)
    {
        return Date(difftime(temps, d2.temps));
    }

    /*struct tm {
        int tm_sec;         seconds,  range 0 to 59
        int tm_min;          minutes, range 0 to 59
        int tm_hour;         hours, range 0 to 23
        int tm_mday;         day of the month, range 1 to 31
        int tm_mon;          month, range 0 to 11
        int tm_year;         The number of years since 1900
        int tm_wday;        day of the week, range 0 to 6
        int tm_yday;         day in the year, range 0 to 365
        int tm_isdst;        daylight saving time
    };*/

    int getMinuteElapsed()
    {

    }


    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées
    time_t temps;
    //----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Date>

#endif // DATE_H