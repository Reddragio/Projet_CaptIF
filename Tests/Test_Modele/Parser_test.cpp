#include "../../src/Modele/Parser.h"
#include "gtest/gtest.h"

class Parser_test : public ::testing::Test
{
protected:
    // You can remove any or all of the following functions if its body
    // is empty.
    Parser_test()
    {
        // You can do set-up work for each test here.
    }
    virtual ~Parser_test()
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
};

TEST_F(Parser_test,testConstructeurEtMethode)
{
    vector<string> fichiers;
    fichiers.push_back("dataTest.csv");
    fichiers.push_back("AttributeType.csv");
    Parser p(fichiers);

    unordered_map<string,Sensor> sensors;
    unordered_map<string,Attribute> attributes;
    p.getSensorsAndAttributes(sensors,attributes);
    ASSERT_EQ(sensors.size(),10);
    ASSERT_EQ(attributes.size(),4);
}