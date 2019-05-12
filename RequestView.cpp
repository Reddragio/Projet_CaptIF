/*************************************************************************
RequestView
-------------------
Date                 : 05/05/2019
Copyright            :
*************************************************************************/

//---------- Réalisation de la classe <RequestView> (fichier RequestView.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système


//------------------------------------------------------ Include personnel
#include "RequestView.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool RequestView::goToNext()
{
    /*methode pour aller a la ligne prochaine et obtenir les prochaines attributs
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

Measure RequestView::getMeasure()
{
    return actualMeasure;
}



//-------------------------------------------- Constructeurs - destructeur

RequestView::RequestView(vector<string> files, Date debut, Date fin) {
    this->files = files;
    this->debut = debut;
    this->fin = fin;
    /*methode pour obtenir les attributs dans la ligne
        a remplir
    */
    while (std::getline(actualFile,str) && Measure.dateMeasure < debut)
    {
        indexFile ++;
    }
#ifdef MAP
    cout << "Appel au constructeur de <RequestView>" << "\r\n";
#endif

}

RequestView::RequestView() {

#ifdef MAP
    cout << "Appel au constructeur de <RequestView>" << "\r\n";
#endif

}

RequestView::~RequestView() {
    actualFile.close();

#ifdef MAP
    cout << "Appel au destructeur de <Top10>" << "\r\n";
#endif
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
