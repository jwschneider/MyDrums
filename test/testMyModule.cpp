#pragma once
#include "NewMacros.h"
#include "CppUTest/TestHarness.h"
#include "../src/MyModule/MyModuleEngine.hpp"
#include "../src/MyModule/MyModuleControls.hpp"
#include "testHarness.hpp"
#include "../src/MyModule/MyModule.hpp"

using namespace mymodule;

MyModuleEngine _engine;
TestHarness _harness;


TEST_GROUP(MyModuleTest)
{
    void setup()
    {
        _harness = TestHarness(MyModule::NUM_PARAMS, MyModule::NUM_OUTPUTS, MyModule::NUM_INPUTS, MyModule::NUM_LIGHTS);
        _engine = MyModuleEngine(*_harness.getControls());
    }
    void teardown()
    {
    }
};

TEST(MyModuleTest, FirstTest)
{   

}