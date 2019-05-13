/*************************************************************************
Attribute
-------------------
Date                 : 05/05/2019
Copyright            :
*************************************************************************/

//---------- Réalisation de la classe <Attribute> (fichier Attribute.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système


//------------------------------------------------------ Include personnel
#include "Attribute.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string Attribute::getUnit() const{
    return unit;
}

//------------------------------- Surcharge des opérateurs d'Entrée/Sortie

ostream & operator << (ostream & out,const Attribute & att){
    out << att.id;
    return out;
}

//-------------------------------------------- Constructeurs - destructeur

Attribute::Attribute(const string &id, const string &unit, const string &description) : id(id), unit(unit),description(description)
{

}

Attribute::Attribute()
{

}

Attribute::~Attribute() {
#ifdef MAP
    cout << "Appel au destructeur de <Top10>" << "\r\n";
#endif
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

