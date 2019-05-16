/*************************************************************************
CaptIF
-------------------
Date                 : 05/05/2019
Copyright            :
*************************************************************************/

//---------- Réalisation de la classe <CaptIF> (fichier CaptIF.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système


//------------------------------------------------------ Include personnel
#include "CaptIF.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void CaptIF::run()
{
    //Date testDate = input.rentrerMoment();
    //cout << testDate << endl;
    //Debut chrono
    clock_t start = clock();
    map<string,tuple<int, double, int>> res = services.qualiteAirTerritoirePeriode(Point(-30.0647387677174,-76.3439147576429),10.0,Date(1980,0,0,0,0,0,0),Date(2050,0,0,0,0,0,0));
    double duree = (clock() - start) / (double)CLOCKS_PER_SEC;
    cout << "Temps de calcul: "<<duree << "s"<<endl;
    cout << endl;
    output.afficherResultatATMO(1,res);
}

//-------------------------------------------- Constructeurs - destructeur

CaptIF::CaptIF() {
}

CaptIF::CaptIF(vector<string> fichiers):services(fichiers)
{
    output = Output(services.getSensors(),services.getAttributes());
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
