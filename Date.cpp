/*************************************************************************
Date
-------------------
Date                 : 05/05/2019
Copyright            :
*************************************************************************/

//---------- Réalisation de la classe <Date> (fichier Date.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système


//------------------------------------------------------ Include personnel
#include "Date.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

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

int Date::toMinutes()
{
    //Nombre de minutes écoulées depuis 1970
    return ((int)temps)/60;
}

int Date::toSeconds()
{
    //Nombre de secondes écoulées depuis 1970
    return (int)temps;
}

//------------------------------------------------- Surcharge d'opérateurs

bool Date::operator<=(const Date & d2)
{
    double diff = difftime(temps, d2.temps);
    if(diff==0.0){
        return msec <= d2.msec;
    }
    return diff <= 0;
}

bool Date::operator<(const Date & d2)
{
    double diff = difftime(temps, d2.temps);
    if(diff==0.0){
        return msec < d2.msec;
    }
    return diff < 0;
}

bool Date::operator>=(const Date & d2)
{
    double diff = difftime(temps, d2.temps);
    if(diff==0.0){
        return msec >= d2.msec;
    }
    return diff >= 0;
}

bool Date::operator>(const Date & d2)
{
    double diff = difftime(temps, d2.temps);
    if(diff==0.0){
        return msec > d2.msec;
    }
    return diff > 0;
}

bool Date::operator==(const Date & d2)
{
    return temps == d2.temps && msec == d2.msec;
}

time_t Date::operator-(const Date & d2){
    //Calcul la différence entre 2 dates et le ramène arbitrairement à 0 si le résultat est négatif
    double diff = difftime(temps, d2.temps);
    if(diff >= 0){
        return (time_t)diff;
    }
    else{
        return (time_t)0;
    }
}

//-------------------------------------------- Constructeurs - destructeur

Date::Date() {
    temps = time(nullptr);
}

Date::Date(time_t tempsInit) {
    temps = tempsInit;
}

Date::Date(int year, int month,int day,int hour, int min, int sec,int msecInit){
    tm date;
    date.tm_year = year-1900;
    date.tm_mon = month-1;
    date.tm_mday = day;
    date.tm_hour = hour;
    date.tm_min = min;
    date.tm_sec = sec;
    temps = mktime(&date);
    msec = msecInit;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

