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
    output.afficherMessageAccueil(services);
    int choix = -1;

    while (choix!=0)
    {
        output.afficherMenu();
        choix = input.choisirMethode();
        switch (choix)
        {
            case 1:{
                Point p=input.rentrerPoint();
                double rayon=input.rentrerRayon();
                tuple<Date,Date> periode=input.rentrerDebutFin();
                Date debut= get<0>(periode);
                Date fin= get<1>(periode);
                //cout << "debut <= fin =" << boolalpha << (debut <= fin) << endl;
                //cout << debut << endl;
                //cout << fin << endl;
                map<string,tuple<int, double, int>> res = services.qualiteAirTerritoirePeriode(p,rayon,debut,fin);
                cout << endl;
                output.afficherResultatATMO(choix,res);
                cout << endl;
                break;
            }

        case 2:{
            Point p2=input.rentrerPoint();
            double rayon2=input.rentrerRayon();
            Date moment2= input.rentrerMoment();
            map<string,tuple<int, double, int>> res2 = services.qualiteAirTerritoireMoment(p2,rayon2,moment2);
            cout << endl;
            output.afficherResultatATMO(choix,res2);
            cout << endl;
            break;
        }

            case 3:{
                Point p3=input.rentrerPoint();
                tuple<Date,Date> periode3=input.rentrerDebutFin();
                Date debut3= get<0>(periode3);
                Date fin3= get<1>(periode3);
                map<string,tuple<int, double, int>> res3 = services.qualiteAirPointPeriode(p3,debut3,fin3);
                cout << endl;
                output.afficherResultatATMO(choix,res3);
                cout << endl;
                break;
            }
            case 4:{
                Point p4=input.rentrerPoint();
                Date moment4= input.rentrerMoment();
                map<string,tuple<int, double, int>> res4 = services.qualiteAirPointMoment(p4,moment4);
                cout << endl;
                output.afficherResultatATMO(choix,res4);
                cout << endl;
                break;
            }
            case 5:{
                Point p5=input.rentrerPoint();
                double rayon5=input.rentrerRayon();
                tuple<Date,Date> periode5=input.rentrerDebutFin();
                Date debut5= get<0>(periode5);
                Date fin5= get<1>(periode5);
                map<string,tuple<double, double, double, Date>> res5 = services.evolutionGlobale(p5,rayon5,debut5,fin5);
                cout << endl;
                output.afficherEvolution(choix, res5);
                cout << endl;
                break;
            }
            case 6:{
                Point p6=input.rentrerPoint();
                double rayon6=input.rentrerRayon();
                unordered_map<string,bool> res6;
                services.detecterCapteursDysfonctionnels(p6,rayon6,res6);
                cout << endl;
                output.afficherCapteursEtBugs(res6);
                cout << endl;
                break;
            }
            case 7:{
                Point p7=input.rentrerPoint();
                double rayon7=input.rentrerRayon();
                unordered_map<string,Sensor> sensors = services.listerCapteurs(p7,rayon7);
                cout << endl;
                output.afficherCapteurs(sensors);
                cout << endl;
                break;
            }
            case 8:{
                string idCapteur=input.rentrerIdCapteur();
                bool res=services.verifierCapteurs(idCapteur);
                cout << endl;
                output.afficherResultatCapteur(res,idCapteur);
                cout << endl;
                break;
            }
            case 9:{
                Point p9=input.rentrerPoint();
                double rayon9=input.rentrerRayon();
                unordered_map<string,unordered_map<string,bool>> res;
                services.detecterComportementSimilaires(p9,rayon9,res);
                cout << endl;
                output.afficherSimilarites(res);
                cout << endl;
                break;

            }
        }
    }

    output.afficherMessageFinProg();

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
