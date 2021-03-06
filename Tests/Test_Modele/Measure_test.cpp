#include "../../src/Modele/Measure.h"
#include "gtest/gtest.h"

class Measure_test : public ::testing::Test
{
protected:
    // You can remove any or all of the following functions if its body
    // is empty.
    Measure_test()
    {
        // You can do set-up work for each test here.
    }
    virtual ~Measure_test()
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

TEST_F(Measure_test,testGetters)
{
    Measure m1("m1","CO2",Date(50,3),42);
    //(const string &sensorId, const string &attributeId, const Date &dateMeasure, double value);
    ASSERT_EQ(m1.getSensorId(),"m1");
    ASSERT_EQ(m1.getAttributeId(),"CO2");
    ASSERT_TRUE(m1.getDate() == Date(50,3));
    ASSERT_EQ(m1.getValue(),42);
}