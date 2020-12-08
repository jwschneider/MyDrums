#include "CppUTest/TestHarness.h"

TEST_GROUP(FirstTestGroup)
{

};

TEST(FirstTestGroup, SecondTest)
{
    FAIL("Fail me!");
}