/*************************************************************************
Output
-------------------
Date                 : 05/05/2019
Copyright            :
*************************************************************************/

//---------- Réalisation de la classe <Output> (fichier Output.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système


//------------------------------------------------------ Include personnel
#include <iostream>

#include "Output.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Output::afficherMessageAccueil(const Services & services) {
    cout << endl;
    cout << "### Initialisation terminee ###" << endl;
    cout << "Nombre de capteurs : " << services.getSensors().size() << endl;
    cout << "Nombre d'attributs : " << services.getAttributes().size() << endl;
    cout << endl;
    cout << "<<< Bienvenue sur l'application Capt'IF >>>" << endl;
    cout << endl;
    cout << "Un projet realise par:"<<endl;
    cout << "Jacques Charnay, Pierre Scheer, Sofiane Benslimane & Luoxiaofan Xiong"<< endl;
    cout << endl;
}

void Output::afficherMessageFinProg() {
    cout << endl;
    cout << "A bientot :) !" << endl;
    cout << endl;
}

void Output::afficherMenu() {
    cout << "### MENU ###" << endl;
    cout << " Methode 1--- qualiteAirTerritoirePeriode" << endl;
    cout << " Methode 2--- qualiteAirTerritoireMoment" << endl;
    cout << " Methode 3--- qualiteAirPointPeriode" << endl;
    cout << " Methode 4--- qualiteAirPointMoment" << endl;
    cout << " Methode 5--- evolutionGlobale" << endl;
    cout << " Methode 6--- detecterCapteursDysfonctionnels" << endl;
    cout << " Methode 7--- listerCapteurs" << endl;
    cout << " Methode 8--- verifierCapteurs" << endl;
    cout << " Methode 9--- detecterComportementSimilaires" << endl;
}

void Output::afficherCapteurs(const unordered_map<string,Sensor> & sensors) {
    for (unordered_map<string,Sensor>::const_iterator i = sensors.cbegin(); i != sensors.cend(); i++) {
        cout << i->second << endl;
    }
}

void Output::afficherResultatATMO(int methode, const map<string,tuple<int, double, int>> & resultat) {
    ios init(NULL);
    init.copyfmt(cout);

    cout.width(20);
    cout.fill(' ');
    cout << left;
    ios param(NULL);
    param.copyfmt(cout);

    cout << "--- ATMO ---" << endl;
    for (map<string,tuple<int, double, int>>::const_iterator i = resultat.cbegin(); i != resultat.cend(); i++)
    {
        cout << "Type de gaz : ";
        cout.copyfmt(param);
        cout.width(5);
        cout << i->first;
        cout << ", ATMO : ";
        cout.copyfmt(param);
        cout.width(3);
        cout << get<0>(i->second);
        cout << ", Concentration : ";
        cout.copyfmt(param);
        cout.width(9);
        cout << get<1>(i->second);
        cout.copyfmt(param);
        cout.width(5);
        cout << attributes[i->first].getUnit();
        cout <<", Nombre de valeurs utiles: ";
        cout << get<2>(i->second) << endl;
    }

    cout.copyfmt(init);
}

void Output::afficherEvolution(int methode, const map<string,tuple<double, double, double, Date>> & resultat) {
    cout << "--- Resultat d'evolution ---" << endl;
    for (map<string,tuple<double, double, double, Date>>::const_iterator i = resultat.cbegin(); i != resultat.cend(); i++)
    {
        cout << "Type de gaz : " << i->first << ", Concentration initiale : " << get<0>(i->second) << ", Concentration finale: " << get<1>(i->second)  <<", Taux d'augmentation : " << get<2>(i->second) <<"%, Date de mesure : " << get<3>(i->second)<< endl;
    }
}

void Output::afficherCapteursEtBugs(const unordered_map<string,bool> & fonctionnel)
{
    cout << "Les capteurs d'id suivants presentent un dysfonctionnement:"<<endl;
    for(unordered_map<string,bool>::const_iterator sensor1 = fonctionnel.cbegin();sensor1 != fonctionnel.cend();++sensor1)
    {
        if(!sensor1->second)
        {
            cout << sensor1->first << endl;
        }
    }
}

void Output::afficherSimilarites(const unordered_map<string,unordered_map<string,bool>> & resultat)
{
    bool firstSimilarity;
    for(unordered_map<string,unordered_map<string,bool>>::const_iterator sensor1 = resultat.cbegin();sensor1 != resultat.cend();++sensor1)
    {
        firstSimilarity = true;
        for(unordered_map<string,bool>::const_iterator sensor2 = sensor1->second.cbegin();sensor2 != sensor1->second.cend();++sensor2)
        {
            if(sensor2->second)
            {
                if(firstSimilarity)
                {
                    firstSimilarity = false;
                    cout << "Capteurs similaires au capteur " << sensor1->first << ": " << sensor2->first;
                }
                else
                {
                    cout << ", " << sensor2->first;
                }
            }
        }
        if(!firstSimilarity)
        {
            cout << endl;
        }
    }
}

void Output::afficherResultatCapteur(bool resultat)
{
    if(resultat)
    {
        cout << "Le capteur fonctionne correctemment" << endl;
    }
    else
    {
        cout << "Des anomalies ont ete detectes sur les mesures du capteur" << endl;
    }
}

//-------------------------------------------- Constructeurs - destructeur

Output::Output() {
#ifdef MAP
    cout << "Appel au constructeur de <Point>" << "\r\n";
#endif

}

Output::Output(const unordered_map<string, Sensor> &sensors, const unordered_map<string, Attribute> &attributes)
        : sensors(sensors), attributes(attributes) {}

/*Output::~Output() {
#ifdef MAP
    cout << "Appel au destructeur de <Top10>" << "\r\n";
#endif
}*/


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
