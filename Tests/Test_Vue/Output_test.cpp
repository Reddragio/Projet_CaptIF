#include "../../src/Vue/Output.h"
#include "gtest/gtest.h"
#include <iostream>

class Output_test : public ::testing::Test
{
protected:
    // You can remove any or all of the following functions if its body
    // is empty.
    Output_test()
    {

        // You can do set-up work for each test here.
        vector<string> fichiers;
        fichiers.push_back("dataTest.csv");
        fichiers.push_back("AttributeType.csv");
        services = Services(fichiers);
        output = Output(services.getSensors(),services.getAttributes());
    }
    virtual ~Output_test()
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
    Output output;
    Services services;
};

TEST_F(Output_test,testBidon)
{
    ASSERT_TRUE(true);
}

TEST_F(Output_test,testMessage)
{
    testing::internal::CaptureStdout();
    output.afficherMessageAccueil(services);
    string output = testing::internal::GetCapturedStdout();

    string objectif;
    objectif.append("\n");
    objectif.append("Bienvenue sur l'application Capt'IF\n");
    objectif.append("\n");
    objectif.append("Un projet realise par:\n");
    objectif.append("Jacques Charnay, Pierre Scheer, Sofiane Benslimane & Luoxiaofan Xiong\n");
    objectif.append("\n");
    objectif.append("Initialisation terminee\n");
    objectif.append("Nombre de capteurs : 10\n");
    objectif.append("Nombre d'attributs : 4\n");
    objectif.append("\n");

    ASSERT_EQ(output,objectif);
}
