#include "MyModule.hpp"

using namespace rack;
using namespace mymodule;

mymodule::MyModulePanel::MyModulePanel(MyModule* module) {
    setModule(module);
    setPanel(APP->window->loadSvg("MyDrums/res/MyModule.svg"));

    addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
    addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
    addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
    addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

    addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(15.24, 46.063)), module, MyModule::PITCH_PARAM));

    addInput(createInputCentered<PJ301MPort>(mm2px(Vec(15.24, 77.478)), module, MyModule::PITCH_INPUT));

    addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(15.24, 108.713)), module, MyModule::SINE_OUTPUT));

    addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(15.24, 25.81)), module, MyModule::BLINK_LIGHT));
}
