#include "NewMacros.h"
#include "CppUTest/TestHarness.h"


Module *kick;

TEST_GROUP(Init)
{
    void setup()
    {
        // when this line is run, something happens so that none of the tests get run, and Fail(0) does nothing
        //kick = modelKick->createModule();
    }
    void teardown()
    {

    }
};
TEST(Init, Quantities)
{
    FAIL(0);
    CHECK_EQUAL(18, sizeof(kick->params));
    CHECK_EQUAL(18, sizeof(kick->paramQuantities));
    CHECK_EQUAL(19, sizeof(kick->inputs));
    CHECK_EQUAL(1, sizeof(kick->outputs));
    CHECK_EQUAL(0, sizeof(kick->lights));
}

// TEST(Init, ParamsQuantities)
// {
//     CHECK_EQUAL(kick->paramQuantities[0]->minValue, 10.f);
//     CHECK_EQUAL(kick->paramQuantities[0]->maxValue, 90.f);
//     CHECK_EQUAL(kick->paramQuantities[0]->defaultValue, 50.f);
// }