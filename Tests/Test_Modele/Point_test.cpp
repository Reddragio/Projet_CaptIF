//
// Created by jacqu on 30-May-19.
//
#include "../../src/Modele/Point.h"
#include "gtest/gtest.h"

class Point_test : public ::testing::Test
{
protected:
    // You can remove any or all of the following functions if its body
    // is empty.
    Point_test()
    {
        // You can do set-up work for each test here.
    }
    virtual ~Point_test()
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

TEST_F(Point_test,testConstructeur)
{
    Point p(5.0,7.0);
    ASSERT_TRUE(p.getLat()==5.0);
    ASSERT_TRUE(p.getLng()==7.0);
}

TEST_F(Point_test,testBidon)
{
    ASSERT_TRUE(true);
}