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

TEST_F(Services_test, verifierRecuperationCapteursProches){
    unordered_set<string> sensorsId = services.getSensorsTerritoryIds(Point(0,0), 100);
    ASSERT_EQ(sensorsId.size(), 1);
}

TEST_F(Services_test, verifierRecuperationCapteursLoins){
    unordered_set<string> sensorsId = services.getSensorsTerritoryIds(Point(0,0), 1000);
    ASSERT_EQ(sensorsId.size(), 5);
}

TEST_F(Services_test, verifierRecuperationCapteursTresLoins){
    unordered_set<string> sensorsId = services.getSensorsTerritoryIds(Point(0,0), 10000);
    ASSERT_EQ(sensorsId.size(), 10);
}

TEST_F(Services_test, verifierListageCapteurs) {
    unordered_map<string,Sensor> sensors = services.listerCapteurs(Point(0,0), 500);
    ASSERT_EQ(sensors.at("Sensor0").getLocation().getLat(), 0);
    ASSERT_EQ(sensors.at("Sensor0").getLocation().getLng(), 0);
    ASSERT_EQ(sensors.at("Sensor0").getDescription(), "Le centre du monde");
    ASSERT_EQ(sensors.at("Sensor1").getLocation().getLat(), 1);
    ASSERT_EQ(sensors.at("Sensor1").getLocation().getLng(), 1);
    ASSERT_EQ(sensors.at("Sensor1").getDescription(), "");
    ASSERT_EQ(sensors.at("Sensor2").getLocation().getLat(), -1);
    ASSERT_EQ(sensors.at("Sensor2").getLocation().getLng(), -1);
    ASSERT_EQ(sensors.at("Sensor2").getDescription(), "");
    ASSERT_EQ(sensors.size(), 3);
}

TEST_F(Services_test,verifierInitialisationCapteurs)
{
    ASSERT_EQ(services.getSensors().size(),10);
}

TEST_F(Services_test,verifierInitialisationAttributs)
{
    ASSERT_EQ(services.getAttributes().size(),4);
}

//Territoire et Période

TEST_F(Services_test,testQualiteAirTerritoirePeriodeBasique)
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

TEST_F(Services_test,testQualiteAirTerritoirePeriodeAucunCapteurFichier)
{
    Point p1(0.0,0.0);
    //Date(int year, int month,int day,int hour, int min, int sec,int msecInit);
    Date debut(2017,1,8,0,1,20,0);
    Date fin(2017,1,8,0,32,0,0);
    map<string,tuple<int, double, int>> res = servicesEmpty.qualiteAirTerritoirePeriode(p1,5,debut,fin);
    ASSERT_EQ(res.size(),0);
}

TEST_F(Services_test,testQualiteAirTerritoirePeriodeAucunCapteurPeriode)
{
    Point p1(0.0,0.0);
    //Date(int year, int month,int day,int hour, int min, int sec,int msecInit);
    Date debut(2018,1,8,0,1,20,0);
    Date fin(2018,1,8,0,32,0,0);
    map<string,tuple<int, double, int>> res = services.qualiteAirTerritoirePeriode(p1,5,debut,fin);
    ASSERT_EQ(get<1>(res["O3"]),-1.0);
    ASSERT_EQ(get<1>(res["NO2"]),-1.0);
    ASSERT_EQ(get<1>(res["SO2"]),-1.0);
    ASSERT_EQ(get<1>(res["PM10"]),-1.0);
}

TEST_F(Services_test,testQualiteAirTerritoirePeriodeAucunCapteurZone)
{
    Point p1(100.0,100.0);
    //Date(int year, int month,int day,int hour, int min, int sec,int msecInit);
    Date debut(2017,1,8,0,1,20,0);
    Date fin(2017,1,8,0,32,0,0);
    map<string,tuple<int, double, int>> res = services.qualiteAirTerritoirePeriode(p1,2,debut,fin);
    ASSERT_EQ(get<1>(res["O3"]),-1.0);
    ASSERT_EQ(get<1>(res["NO2"]),-1.0);
    ASSERT_EQ(get<1>(res["SO2"]),-1.0);
    ASSERT_EQ(get<1>(res["PM10"]),-1.0);
}

// Point et Moment

TEST_F(Services_test,testQualiteAirPointMoment){
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
    Date moment(2017,1,8,1,20,0,0);
    map<string,tuple<int, double, int>> res = services.qualiteAirPointMoment(p1,moment);
    ASSERT_EQ(get<1>(res["O3"]),17.8902017543936);
    ASSERT_EQ(get<1>(res["PM10"]),1.55796479844986);
}

TEST_F(Services_test,testQualiteAirPointMomentSansSensors){

    Point p1(45.837780,4.832710);
    //Date(int year, int month,int day,int hour, int min, int sec,int msecInit);
    Date moment(2017,1,8,1,20,0,0);
    map<string,tuple<int, double, int>> res = services.qualiteAirPointMoment(p1,moment);
    ASSERT_EQ(get<1>(res["O3"]),-1);
    ASSERT_EQ(get<1>(res["PM10"]),-1);
}

TEST_F(Services_test,testQualiteAirPointMomentSansMesures){

    Point p1(0.0,0.0);
    //Date(int year, int month,int day,int hour, int min, int sec,int msecInit);
    Date moment(2029,1,8,1,20,0,0);
    map<string,tuple<int, double, int>> res = services.qualiteAirPointMoment(p1,moment);
    ASSERT_EQ(get<1>(res["O3"]),-1);
    ASSERT_EQ(get<1>(res["PM10"]),-1);
}

// Territoire et Moment

TEST_F(Services_test,testQualiteAirTerritoireMoment)
{
    Point p1(0.0,0.0);
    //Date(int year, int month,int day,int hour, int min, int sec,int msecInit);
    Date moment(2017,1,8,1,20,0,0);
    map<string,tuple<int, double, int>> res = services.qualiteAirTerritoireMoment(p1,5,moment);
    ASSERT_EQ(get<1>(res["O3"]),64.14836534965675);
    ASSERT_EQ(get<1>(res["PM10"]),8.658728917317945);
}

TEST_F(Services_test,testQualiteAirTerritoireMomentSansMesures)
{
    Point p1(0.0,0.0);
    //Date(int year, int month,int day,int hour, int min, int sec,int msecInit);
    Date moment(2029,1,8,0,1,20,0);
    map<string,tuple<int, double, int>> res = services.qualiteAirTerritoireMoment(p1,5,moment);
    ASSERT_EQ(get<1>(res["O3"]),-1);
    ASSERT_EQ(get<1>(res["PM10"]),-1);
}

TEST_F(Services_test,testQualiteAirTerritoireMomentSansSensors)
{
    Point p1(45.837780,4.832710);
    //Date(int year, int month,int day,int hour, int min, int sec,int msecInit);
    Date moment(2017,1,8,0,1,20,0);
    map<string,tuple<int, double, int>> res = services.qualiteAirTerritoireMoment(p1,5,moment);
    ASSERT_EQ(get<1>(res["O3"]),-1);
    ASSERT_EQ(get<1>(res["PM10"]),-1);
}


//Point et Période

TEST_F(Services_test,testQualiteAirPointPeriode){
    Point p1(0.0,0.0);
    //Date(int year, int month,int day,int hour, int min, int sec,int msecInit);
    Date debut(2017,1,8,0,7,20,0);
    Date fin(2017,1,8,0,32,0,0);
    map<string,tuple<int, double, int>> res = services.qualiteAirPointPeriode(p1,debut,fin);
    ASSERT_EQ(get<1>(res["O3"]),36.7797600526823);
    ASSERT_EQ(get<1>(res["PM10"]),1.99603267330184);
}

TEST_F(Services_test,testQualiteAirPointPeriodeSansSensor){
    Point p1(45.837780,4.832710);
    //Date(int year, int month,int day,int hour, int min, int sec,int msecInit);
    Date debut(2017,1,8,0,7,20,0);
    Date fin(2017,1,8,0,32,0,0);
    map<string,tuple<int, double, int>> res = services.qualiteAirPointPeriode(p1,debut,fin);
    ASSERT_EQ(get<1>(res["O3"]),-1);
    ASSERT_EQ(get<1>(res["PM10"]),-1);
}

TEST_F(Services_test,testQualiteAirPointPeriodeSansMesures){
    Point p1(0.0,0.0);
    //Date(int year, int month,int day,int hour, int min, int sec,int msecInit);
    Date debut(2029,1,8,0,7,20,0);
    Date fin(2029,1,8,0,32,0,0);
    map<string,tuple<int, double, int>> res = services.qualiteAirPointPeriode(p1,debut,fin);
    ASSERT_EQ(get<1>(res["O3"]),-1);
    ASSERT_EQ(get<1>(res["PM10"]),-1);
}

TEST_F(Services_test,verifierInitialisationCapteursServiceEmpty)
{
    ASSERT_EQ(servicesEmpty.getSensors().size(),0);
}

TEST_F(Services_test, testEvolutionGlobale) {
    Point p(0.0, 0.0);
    double rayon = 100;
    Date debut(2017,1,8,1,20,0,0);
    Date fin(2017,12,1,23,20,0,0);
    map<string,tuple<double, double, double, Date>> res = services.evolutionGlobale(p, rayon, debut, fin);
    double obj = (48.0876642664453-10.9832137846515)/10.9832137846515*100.0;
    ASSERT_EQ(get<2>(res["PM10"]), obj);
}

TEST_F(Services_test, testEvolutionGlobaleAucunCapteurZone) {
    Point p(100.0, 100.0);
    double rayon = 5;
    Date debut(2017,1,8,1,20,0,0);
    Date fin(2017,12,1,23,20,0,0);
    map<string,tuple<double, double, double, Date>> res = services.evolutionGlobale(p, rayon, debut, fin);
    ASSERT_EQ(get<1>(res["O3"]),-1.0);
    ASSERT_EQ(get<1>(res["NO2"]),-1.0);
    ASSERT_EQ(get<1>(res["SO2"]),-1.0);
    ASSERT_EQ(get<1>(res["PM10"]),-1.0);
    ASSERT_EQ(get<0>(res["PM10"]),-1.0);
    ASSERT_EQ(get<2>(res["PM10"]),0.0);
    ASSERT_TRUE(get<3>(res["PM10"])==Date());
}

TEST_F(Services_test, testEvolutionGlobaleAucunCapteurPeriode) {
    Point p(0.0, 0.0);
    double rayon = 5;
    Date debut(2018,1,8,1,20,0,0);
    Date fin(2018,12,1,23,20,0,0);
    map<string,tuple<double, double, double, Date>> res = services.evolutionGlobale(p, rayon, debut, fin);
    ASSERT_EQ(get<1>(res["O3"]),-1.0);
    ASSERT_EQ(get<1>(res["NO2"]),-1.0);
    ASSERT_EQ(get<1>(res["SO2"]),-1.0);
    ASSERT_EQ(get<1>(res["PM10"]),-1.0);
    ASSERT_EQ(get<0>(res["PM10"]),-1.0);
    ASSERT_EQ(get<2>(res["PM10"]),0.0);
    ASSERT_TRUE(get<3>(res["PM10"])==Date());
}

TEST_F(Services_test, testEvolutionGlobaleAucunFichier) {
    Point p(0.0, 0.0);
    double rayon = 5;
    Date debut(2017,1,8,1,20,0,0);
    Date fin(2017,12,1,23,20,0,0);
    map<string,tuple<double, double, double, Date>> res = servicesEmpty.evolutionGlobale(p, rayon, debut, fin);
    ASSERT_EQ(res.size(), 0);
}

TEST_F(Services_test, testDetecterCapteursDysfonctionnels){
    Point p(0.0,0.0);
    double rayon = 100;
    unordered_map<string,bool> fonct;
    services.detecterCapteursDysfonctionnels(p, rayon, fonct);
    ASSERT_EQ(fonct["Sensor0"], true);
    ASSERT_EQ(fonct["Sensor2"], false);
}

TEST_F(Services_test, testDetecterCapteursDysfonctionnelsAucunFichier){
    Point p(0.0,0.0);
    double rayon = 100;
    unordered_map<string,bool> fonct;
    servicesEmpty.detecterCapteursDysfonctionnels(p, rayon, fonct);
    ASSERT_EQ(fonct.size(), 0);
}

TEST_F(Services_test, testDetecterCapteursDysfonctionnelsAucunCapteurZone){
    Point p(100.0,0.0);
    double rayon = 100;
    unordered_map<string,bool> fonct;
    services.detecterCapteursDysfonctionnels(p, rayon, fonct);
    ASSERT_EQ(fonct.size(), 0);
}

TEST_F(Services_test, testVerifierCapteurs){
    bool status0 = services.verifierCapteurs("Sensor0");
    ASSERT_EQ(status0, true);
    bool status4 = services.verifierCapteurs("Sensor4");
    ASSERT_EQ(status4, false);
    bool status5 = services.verifierCapteurs("abcd");
    ASSERT_EQ(status5, false);
}

TEST_F(Services_test, testComportementsSimilaires){
    Point p(0.0,0.0);
    double rayon = 1000;
    unordered_map<string,unordered_map<string,bool>> sim;
    services.detecterComportementSimilaires(p, rayon, sim);

    unordered_map<string, bool> obj;
    obj.insert(make_pair<std::string,double>("Sensor1", false));
    obj.insert(make_pair<std::string,double>("Sensor2", false));
    obj.insert(make_pair<std::string,double>("Sensor3", false));
    obj.insert(make_pair<std::string,double>("Sensor4", false));

    ASSERT_EQ(sim["Sensor0"], obj);
}

TEST_F(Services_test, testComportementsSimilairesAucunFichier){
    Point p(0.0,0.0);
    double rayon = 1000;
    unordered_map<string,unordered_map<string,bool>> sim;
    servicesEmpty.detecterComportementSimilaires(p, rayon, sim);

    ASSERT_EQ(sim.size(),0);
}

TEST_F(Services_test, testComportementsSimilairesAucunCapteurZone){
    Point p(100.0,0.0);
    double rayon = 1;
    unordered_map<string,unordered_map<string,bool>> sim;
    services.detecterComportementSimilaires(p, rayon, sim);

    ASSERT_EQ(sim.size(),0);
}