//
// Created by jacqu on 30-May-19.
//
#include "../../src/Modele/Date.h"
#include "gtest/gtest.h"

class Date_test : public ::testing::Test
{
protected:
    // You can remove any or all of the following functions if its body
    // is empty.
    Date_test()
    {
        // You can do set-up work for each test here.
    }
    virtual ~Date_test()
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

TEST_F(Date_test,testComparaison)
{
    Date d1(2020,1,1,1,1,1,300);
    Date d2(2020,1,1,1,1,1,700);
    ASSERT_TRUE(d1 < d2);
    ASSERT_TRUE(d1 <= d1);
    Date d3(2015,1,1,1,1,1,300);
    Date d4(2020,1,1,1,1,1,700);
    ASSERT_TRUE(d3 < d4);
    ASSERT_TRUE(d4 > d3);
}

TEST_F(Date_test,testBidon)
{
    ASSERT_TRUE(true);
}

TEST_F(Date_test,testAffichage){
    Date d1(2020,1,1,1,1,1,300);
    testing::internal::CaptureStdout();
    cout<<d1;
    string output = testing::internal::GetCapturedStdout();
    tm * date = gmtime(d1.getTemps());
    string objectif;
    objectif.append(to_string((1900+date->tm_year)));
    objectif.append("-");
    ((date->tm_mon+1) > 9) ? objectif.append(to_string(date->tm_mon+1)) : objectif.append("0"+to_string (date->tm_mon+1));
    objectif.append("-");
    (date->tm_mday > 9) ? objectif.append(to_string(date->tm_mday)) : objectif.append("0"+to_string (date->tm_mday));
    objectif.append("T");
    (date->tm_hour > 9) ? objectif.append(to_string(date->tm_hour)) : objectif.append("0"+to_string (date->tm_hour));
    objectif.append(":");
    (date->tm_min > 9) ? objectif.append(to_string(date->tm_min)) : objectif.append("0"+to_string (date->tm_min));
    objectif.append(":");
    (date->tm_sec > 9) ? objectif.append(to_string(date->tm_sec)) : objectif.append("0"+to_string (date->tm_sec));
    objectif.append(".");
    if(d1.getMsec() <= 9){
        objectif.append("00"+to_string (d1.getMsec()));
    }
    else if(d1.getMsec() <= 99){
        objectif.append("0"+to_string (d1.getMsec()));
    }
    else {
        objectif.append(to_string(d1.getMsec()));
    }
    ASSERT_EQ(output,objectif);
}
