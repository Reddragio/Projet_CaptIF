/*************************************************************************
Parser
-------------------
Date                 : 05/05/2019
Copyright            :
*************************************************************************/

//---------- Réalisation de la classe <Parser> (fichier Parser.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système


//------------------------------------------------------ Include personnel
#include "Parser.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

boolean RequestView :: goToNext()
{
    /*methode pour aller a la ligne prochaine et obtenir les attributs prochaines
        a remplir
    */
    if(Measure.dateMeasure<=fin)
    {
        indexFile++;
        return true;
    }else
    {
        return false;
    }

}

Measure RequestView :: getMeasure()
{
    return actualMeasure;
}



//-------------------------------------------- Constructeurs - destructeur

Parser::Parser(vector<String> files, Date debut, Date fin) {
    this.files = files;
    actualFile.open(files);
    indexFile = 0;
    String str;
    /*methode pour obtenir les attributs dans la ligne
        a remplir
    */
    while (std::getline(actualFile,str) && Measure.dateMeasure < debut)
    {
        indexFile ++;
    }
#ifdef MAP
    cout << "Appel au constructeur de <Parser>" << "\r\n";
#endif

}

Parser::~Parser() {
    actualFile.close();

#ifdef MAP
    cout << "Appel au destructeur de <Top10>" << "\r\n";
#endif
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


--
