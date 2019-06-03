#include "../../src/Modele/RequestView.h"
#include "../../src/Controleur/Services.h"
#include "../../src/Modele/Parser.h"
#include "gtest/gtest.h"

class RequestView_test : public ::testing::Test
{
protected:
    // You can remove any or all of the following functions if its body
    // is empty.
    RequestView_test()
    {
        // You can do set-up work for each test here.
        vector<string> fichiers;
        fichiers.push_back("dataTest.csv");
        fichiers.push_back("AttributeType.csv");
        services = Services(fichiers);

    }

    virtual ~RequestView_test()
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
    Parser parser;
};

TEST_F(RequestView_test, testParcoursFichier)
{
    vector<string> fichiers;
    fichiers.push_back("dataTest.csv");
    unordered_set<string> sensorsId = services.getSensorsTerritoryIds(Point(0.0,0.0), 10000);
    RequestView request(fichiers,sensorsId,Date::getMoinsInfini(),Date::getPlusInfini());
    int nbLines = 0;
    while (request.goToNext()) {
        nbLines++;
    }
    ASSERT_EQ(nbLines, 100);
}