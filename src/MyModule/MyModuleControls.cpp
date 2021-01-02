#include "MyModuleControls.hpp"
#include "MyModule.hpp"

using namespace mymodule;


mymodule::MyModuleControls::MyModuleControls(vector<Param>& p, vector<Output>& o, vector<Input>& i, vector<Light>& l, vector<ParamQuantity*>& pq)
{
    params = p;
    outputs = o;
    inputs = i;
    lights = l;
    paramQuantities = pq;
}

float mymodule::MyModuleControls::getPitch() { return getParam(MyModule::PITCH_PARAM);}
float mymodule::MyModuleControls::getInputVoltage() { return getInput(MyModule::PITCH_INPUT);}
void mymodule::MyModuleControls::setOutputVoltage(float v) { setOutput(MyModule::SINE_OUTPUT, v);}
void mymodule::MyModuleControls::setLightBrightness(float b) { setLight(MyModule::BLINK_LIGHT, b);}

float mymodule::MyModuleControls::getParam(int param)
{
    return params[param].getValue();
}
float mymodule::MyModuleControls::getInput(int input)
{
    return inputs[input].getVoltage();
}
void mymodule::MyModuleControls::setOutput(int output, float val)
{
    outputs[output].setVoltage(val);
}
void mymodule::MyModuleControls::setLight(int light, float val)
{
    lights[light].setBrightness(val);
}