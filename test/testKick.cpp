#pragma once
#include "NewMacros.h"
#include "CppUTest/TestHarness.h"
#include "../src/Kick/KickControls.hpp"
#include "../src/Kick/KickEngine.hpp"
#include "../src/Kick/Kick.hpp"
#include "testHarness.hpp"

using namespace kick;


TEST_GROUP(FirstTestGroup)
{
    KickEngine *_engine;
    TestHarness *_harness;
    KickControls *_controls;
    void setup()
    {
    }
    void teardown()
    {
    }
};

TEST(FirstTestGroup, SecondTest)
{   

}
