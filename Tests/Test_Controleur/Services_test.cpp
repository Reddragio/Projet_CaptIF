#include "../../src/Controleur/Services.h"
#include <iostream>
#include "gtest/gtest.h"

class Services_test : public ::testing::Test
{
protected:
    // You can remove any or all of the following functions if its body
    // is empty.
    Services_test()
    {
        // You can do set-up work for each test here.
        vector<string> fichiers;
        fichiers.push_back("dataTest.csv");
        fichiers.push_back("AttributeType.csv");
        services = Services(fichiers);

        //Initialisation service empty
        fichiers.clear();
        fichiers.push_back("datast.csv");
        fichiers.push_back("AttribuType.csv");
        servicesEmpty = Services(fichiers);

    }
    virtual ~Services_test()
    {
        // You can do clean-up work that doesn't throw exceptions here.
    }

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    virtual void SetUp()
    {
        // Code here will be called immediately after the constructor (right
        // before each test).

    }

    virtual void TearDown()
    {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }
    // Objects declared here can be used by all tests in the test case for Foo.

    Services services;
    Services servicesEmpty;
};

/*SensorID;Latitude;Longitude;Description;
Sensor0;0.0;0.0;Le centre du monde;
Sensor1;1.0;1.0;;
Sensor2;-1.0;-1.0;;
Sensor3;5.0;5.0;;
Sensor4;-6.0;-6.0;;
Sensor5;60.0;60.0;Un capteur isole;
Sensor6;64.0;64.0;Un capteur isole;
Sensor7;-20.0;20.0;;
Sensor8;-50.0;0.0;Loin, tres loin;
Sensor9;-60.0;0.0;Encore un peu plus loin;*/
//2017-01-01T00:01:20.6090000

TEST_F(Services_test,verifierInitialisationCapteurs)
{
    ASSERT_EQ(services.getSensors().size(),10);
}

TEST_F(Services_test,verifierInitialisationAttributs)
{
    ASSERT_EQ(services.getAttributes().size(),4);
}

TEST_F(Services_test,testQualiteAirTerritoirePeriode)
{
    /*2017-01-01T00:01:20.6090000;Sensor0;O3;17.8902017543936;
    2017-01-01T00:01:20.6090000;Sensor0;NO2;42.4807462361763;
    2017-01-01T00:01:20.6090000;Sensor0;SO2;13.6449094925285;
    2017-01-01T00:01:20.6090000;Sensor0;PM10;1.55796479844986;
    2017-01-01T00:30:39.0040000;Sensor0;O3;36.7797600526823;
    2017-01-01T00:30:39.0040000;Sensor0;NO2;80.2280346451481;
    2017-01-01T00:30:39.0040000;Sensor0;SO2;38.151540049253;
    2017-01-01T00:30:39.0040000;Sensor0;PM10;1.99603267330184;*/

    Point p1(0.0,0.0);
    //Date(int year, int month,int day,int hour, int min, int sec,int msecInit);
    Date debut(2017,1,8,0,1,20,0);
    Date fin(2017,1,8,0,32,0,0);
    map<string,tuple<int, double, int>> res = services.qualiteAirTerritoirePeriode(p1,5,debut,fin);
    ASSERT_EQ(get<1>(res["O3"]),(17.8902017543936+36.7797600526823)/2.0);
    ASSERT_EQ(get<1>(res["PM10"]),(1.55796479844986+1.99603267330184)/2.0);
}

TEST_F(Services_test,testQualiteAirTerritoireMomentSansMesures)
{
    /*2017-01-01T00:01:20.6090000;Sensor0;O3;17.8902017543936;
    2017-01-01T00:01:20.6090000;Sensor0;NO2;42.4807462361763;
    2017-01-01T00:01:20.6090000;Sensor0;SO2;13.6449094925285;
    2017-01-01T00:01:20.6090000;Sensor0;PM10;1.55796479844986;
    2017-01-01T00:30:39.0040000;Sensor0;O3;36.7797600526823;
    2017-01-01T00:30:39.0040000;Sensor0;NO2;80.2280346451481;
    2017-01-01T00:30:39.0040000;Sensor0;SO2;38.151540049253;
    2017-01-01T00:30:39.0040000;Sensor0;PM10;1.99603267330184;*/

    Point p1(0.0,0.0);
    //Date(int year, int month,int day,int hour, int min, int sec,int msecInit);
    Date moment(2029,1,8,0,1,20,0);
    map<string,tuple<int, double, int>> res = services.qualiteAirTerritoireMoment(p1,5,moment);
    ASSERT_EQ(get<1>(res["O3"]),-1); /* changez les valeurs qu'on doit trouver */
    ASSERT_EQ(get<1>(res["PM10"]),-1);
}

TEST_F(Services_test,testQualiteAirTerritoireMomentSansSensors)
{
    /*2017-01-01T00:01:20.6090000;Sensor0;O3;17.8902017543936;
    2017-01-01T00:01:20.6090000;Sensor0;NO2;42.4807462361763;
    2017-01-01T00:01:20.6090000;Sensor0;SO2;13.6449094925285;
    2017-01-01T00:01:20.6090000;Sensor0;PM10;1.55796479844986;
    2017-01-01T00:30:39.0040000;Sensor0;O3;36.7797600526823;
    2017-01-01T00:30:39.0040000;Sensor0;NO2;80.2280346451481;
    2017-01-01T00:30:39.0040000;Sensor0;SO2;38.151540049253;
    2017-01-01T00:30:39.0040000;Sensor0;PM10;1.99603267330184;*/

    Point p1(45.837780,4.832710);
    //Date(int year, int month,int day,int hour, int min, int sec,int msecInit);
    Date moment(2017,1,8,0,1,20,0);
    map<string,tuple<int, double, int>> res = services.qualiteAirTerritoireMoment(p1,5,moment);
    ASSERT_EQ(get<1>(res["O3"]),-1);
    ASSERT_EQ(get<1>(res["PM10"]),-1);
}

TEST_F(Services_test,verifierInitialisationCapteursServiceEmpty)
{
    ASSERT_EQ(servicesEmpty.getSensors().size(),0);
}