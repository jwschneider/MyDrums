#include "MyModule.hpp"

using namespace mymodule;

MyModule::MyModule()
{
	config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
	configParam(PITCH_PARAM, 0.f, 1.f, 0.f, "");
};

void MyModule::process(const ProcessArgs& args) 
{

};

//Model* modelMyModule = createModel<MyModule, MyModuleWidget>("MyModule");