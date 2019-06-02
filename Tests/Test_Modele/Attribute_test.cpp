#include "../../src/Modele/Attribute.h"
#include "gtest/gtest.h"

class Attribute_test : public ::testing::Test
{
protected:
    // You can remove any or all of the following functions if its body
    // is empty.
    Attribute_test()
    {
        // You can do set-up work for each test here.
    }
    virtual ~Attribute_test()
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

TEST_F(Attribute_test,testGetUnit)
{
    Attribute a1;
    ASSERT_EQ(a1.getUnit(),"");
    Attribute a2("a2","km","Un attribut parmi tant d'autres");
    ASSERT_EQ(a2.getUnit(),"km");
}

TEST_F(Attribute_test,testSurchargeCout)
{
    Attribute a2("a2","km","Un attribut parmi tant d'autres");

    testing::internal::CaptureStdout();
    cout << a2;
    string output = testing::internal::GetCapturedStdout();
    string objectif("a2");

    ASSERT_EQ(output,objectif);
}