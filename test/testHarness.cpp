#include "testHarness.hpp"


TestHarness::TestHarness(int numParams, int numInputs, int numOutputs, int numLights)
{
    initMembers(numParams, numInputs, numOutputs, numLights);
}

TestHarness::~TestHarness()
{
    destroyMembers();
}

void TestHarness::setParam(int param, float val)
{
    params[param].setValue(val);
}
void TestHarness::setInput(int input, float val)
{
    inputs[input].setVoltage(val);
}
float TestHarness::getLight(int light)
{
    return lights[light].getBrightness();
}
float TestHarness::getOutput(float output)
{
    return outputs[output].getVoltage();
}

void TestHarness::initMembers(int numParams, int numInputs, int numOutputs, int numLights)
{
    for (int i = 0; i < numParams; i++)
    {
        Param* p = new Param;
        params.push_back(*p);
    }
    for (int i = 0; i < numInputs; i++)
    {
        Input* p = new Input;
        inputs.push_back(*p);
    }
    for (int i = 0; i < numOutputs; i++)
    {
        Output* p = new Output;
        outputs.push_back(*p);
    }            
    for (int i = 0; i < numLights; i++)
    {
        Light* p = new Light;
        lights.push_back(*p);
    }
    for (int i = 0; i < numParams; i++)
    {
        ParamQuantity* p = new ParamQuantity;
        paramQuantities.push_back(p);
    }
}

void TestHarness::destroyMembers()
{
    params.clear();
    inputs.clear();
    outputs.clear();
    lights.clear();
    while (!paramQuantities.empty())
    {
        delete (paramQuantities.back());
        paramQuantities.pop_back();
    }
}
