#include "NewMacros.h"
#include "CppUTest/TestHarness.h"

Module *kick;

TEST_GROUP(FirstTestGroup)
{
    void setup()
    {
        kick = modelKick->createModule();
    }
    void teardown()
    {
    }
};

TEST(FirstTestGroup, SecondTest)
{   
    kick->toJson();
    // bool b = modelKick == 0;
    // CHECK(b);
}
