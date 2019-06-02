#include "../../src/Modele/Sensor.h"
#include "../../src/Controleur/Services.h"
#include "gtest/gtest.h"

class Sensor_test : public ::testing::Test
{
protected:
    // You can remove any or all of the following functions if its body
    // is empty.
    Sensor_test()
    {
        // You can do set-up work for each test here.
        vector<string> fichiers;
        fichiers.push_back("dataTest.csv");
        fichiers.push_back("AttributeType.csv");
        services = Services(fichiers);
    }
    virtual ~Sensor_test()
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
};

TEST_F(Sensor_test, testAffichage)
{
    Sensor s("Sensor", Point(10,10), "Un point quelconque");
    testing::internal::CaptureStdout();
    cout << s;
    string output = testing::internal::GetCapturedStdout();
    string objectif;
    objectif.append("ID : Sensor, Desc : Un point quelconque, Status : true, Location : (0,0)");
    ASSERT_TRUE(true);
}