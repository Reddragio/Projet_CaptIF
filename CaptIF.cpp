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
    output.afficherMessageAccueil();
    output.afficherMenu();
    int choix = input.choisirMethode();

    switch (choix)
    {
        case 1:{
            Point p=input.rentrerPoint();
            double rayon=input.rentrerRayon();
            tuple<Date,Date> periode=input.rentrerDebutFin();
            Date debut= get<0>(periode);
            Date fin= get<1>(periode);
            map<string,tuple<int, double, int>> res = services.qualiteAirTerritoirePeriode(p,rayon,debut,fin);
            output.afficherResultatATMO(choix,res);
            break;
        }

        case 2:{
            Point p2=input.rentrerPoint();
            double rayon2=input.rentrerRayon();
            Date moment2= input.rentrerMoment();
            map<string,tuple<int, double, int>> res2 = services.qualiteAirTerritoireMoment(p2,rayon2,moment2);
            output.afficherResultatATMO(choix,res2);
            break;
        }

        case 3:{
            Point p3=input.rentrerPoint();
            tuple<Date,Date> periode3=input.rentrerDebutFin();
            Date debut3= get<0>(periode3);
            Date fin3= get<1>(periode3);
            map<string,tuple<int, double, int>> res3 = services.qualiteAirPointPeriode(p3,debut3,fin3);
            output.afficherResultatATMO(choix,res3);
            break;
        }
        case 4:{
            Point p4=input.rentrerPoint();
            Date moment4= input.rentrerMoment();
            map<string,tuple<int, double, int>> res4 = services.qualiteAirPointMoment(p4,moment4);
            output.afficherResultatATMO(choix,res4);
            break;
        }
        case 5:{
            Point p5=input.rentrerPoint();
            double rayon5=input.rentrerRayon();
            tuple<Date,Date> periode5=input.rentrerDebutFin();
            Date debut5= get<0>(periode5);
            Date fin5= get<1>(periode5);
            map<string,tuple<double, double, double, Date>> res5 = services.evolutionGlobale(p5,rayon5,debut5,fin5);
            output.afficherEvolution(choix, res5);
            break;
        }
        case 6:{
            Point p6=input.rentrerPoint();
            double rayon6=input.rentrerRayon();
            vector<tuple<Sensor, int>> res6;
            services.detecterCapteursDysfonctionnels(p6,rayon6,res6);
            output.afficherCapteursEtBugs(res6);
            break;
        }
        case 7:{
            Point p7=input.rentrerPoint();
            double rayon7=input.rentrerRayon();
            vector<Sensor> sensors = services.listerCapteurs(p7,rayon7);
            output.afficherCapteurs(sensors);
            break;
        }
        case 8:{
            string idCapteur=input.rentrerIdCapteur();
            bool res=services.verifierCapteurs(idCapteur);
            output.afficherResultatCapteur(res);
            break;
        }
        case 9:{
            Point p9=input.rentrerPoint();
            double rayon9=input.rentrerRayon();
            unordered_map<Sensor,unordered_map<Sensor,bool>> res;
            services.detecterComportementSimilaires(p9,rayon9,res);
            output.afficherSimilarites(res);
            break;

        }
    }
/*
    //Date testDate = input.rentrerMoment();
    //cout << testDate << endl;
    //Debut chrono
    clock_t start = clock();
    map<string,tuple<int, double, int>> res = services.qualiteAirTerritoirePeriode(Point(-30.0647387677174,-76.3439147576429),10.0,Date(1980,0,0,0,0,0,0),Date(2050,0,0,0,0,0,0));
    double duree = (clock() - start) / (double)CLOCKS_PER_SEC;
    cout << "Temps de calcul: "<<duree << "s"<<endl;
    cout << endl;
    output.afficherResultatATMO(1,res);*/
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
