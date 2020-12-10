#include "CppUTest/TestHarness.h"

TEST_GROUP(FirstTestGroup)
{

};

TEST(FirstTestGroup, SecondTest)
{
    FAIL("Intentional Fail");
    // bool b = modelKick == 0;
    // CHECK(b);
}