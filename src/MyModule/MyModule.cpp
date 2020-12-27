#include "MyModule.hpp"
#include "RackInterface.hpp"
#include "MyModuleControls.hpp"

using namespace mymodule;

MyModule::MyModule()
{
	config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
	configParam(PITCH_PARAM, 0.f, 1.f, 0.f, "");
	ControlInterface *interface = new RackInterface(params, outputs, inputs, lights, paramQuantities);
	MyModuleControls *controls = new MyModuleControls(*interface);
	engine = new MyModuleEngine(*controls);
};

void MyModule::process(const ProcessArgs& args) 
{
	engine->process(args.sampleRate, args.sampleTime);
};

//Model* modelMyModule = createModel<MyModule, MyModuleWidget>("MyModule");