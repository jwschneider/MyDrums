#pragma once
#include "NewMacros.h"
#include "CppUTest/TestHarness.h"
#include "../src/Kick/KickControls.hpp"
#include "../src/Kick/KickEngine.hpp"
#include "../src/Kick/Kick.hpp"
#include "testHarness.hpp"

using namespace kick;


TEST_GROUP(KickTest)
{
    KickEngine *_engine;
    TestHarness *_harness;
    KickControls *_controls;
    void setup()
    {
        _harness = new TestHarness{Kick::NUM_PARAMS, Kick::NUM_OUTPUTS, Kick::NUM_INPUTS, Kick::NUM_LIGHTS};
    }
    void teardown()
    {
        delete _harness;
    }
};

TEST(KickTest, FirstTest)
{
    0;
}

// TEST_GROUP(FirstTestGroup)
// {
//     void setup()
//     {
//         _harness = new TestHarness(Kick::NUM_PARAMS, Kick::NUM_OUTPUTS, Kick::NUM_INPUTS, Kick::NUM_LIGHTS);
//         KickControls *controls = new KickControls(&_harness->params, &_harness->outputs, &_harness->inputs, &_harness->lights, &_harness->paramQuantities);
//         _harness->setControls(controls);
//         _engine = new KickEngine(controls);
//     }
//     void teardown()
//     {
//         delete _engine;
//         delete _harness->getControls();
//         delete _harness;
//     }
// };

// TEST(FirstTestGroup, SecondTest)
// {   

// }
// } // namespace testkick