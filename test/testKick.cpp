#include "NewMacros.h"
#include "CppUTest/TestHarness.h"


TEST_GROUP(FirstTestGroup)
{
    void setup()
    {
        Plugin *p = new Plugin();
        init(p);
    }
    void teardown()
    {
    }
};

TEST(FirstTestGroup, SecondTest)
{
    
    Model *modelKick = pluginInstance->getModel("Kick");
    // bool b = modelKick == 0;
    // CHECK(b);
}