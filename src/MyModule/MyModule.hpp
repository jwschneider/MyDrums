#include <engine/Module.hpp>
#include <app/ModuleWidget.hpp>
#include <rack.hpp>

namespace mymodule {

class MyModule : public rack::engine::Module {
	enum ParamIds {
		PITCH_PARAM,
		NUM_PARAMS
	};
	enum InputIds {
		PITCH_INPUT,
		NUM_INPUTS
	};
	enum OutputIds {
		SINE_OUTPUT,
		NUM_OUTPUTS
	};
	enum LightIds {
		BLINK_LIGHT,
		NUM_LIGHTS
	};

	void process(const ProcessArgs& args) override {
	};
};


class MyModulePanel : public rack::app::ModuleWidget {
    MyModulePanel(MyModule *module)
    {

    }
};
} //namespace MyModule