#include "plugin.hpp"


struct Kick : Module {
	enum ParamIds {
		LOW_FUNDAMENTAL_PARAM,
		LOW_PARTIALS_PARAM,
		LOW_SPREAD_PARAM,
		LOW_BEND_PARAM,
		LOW_DECAY_PARAM,
		LOW_LEVEL_PARAM,
		MID_TONE_PARAM,
		MID_CHARACTER_PARAM,
		MID_LP_PARAM,
		MID_HP_PARAM,
		MID_DECAY_PARAM,
		MID_LEVEL_PARAM,
		HEAD_TONE_PARAM,
		HEAD_CHARACTER_PARAM,
		HEAD_LP_PARAM,
		HEAD_HP_PARAM,
		HEAD_DECAY_PARAM,
		HEAD_LEVEL_PARAM,
		NUM_PARAMS
	};
	enum InputIds {
		LOW_FUNDAMENTAL_INPUT,
		LOW_PARTIALS_INPUT,
		LOW_SPREAD_INPUT,
		LOW_BEND_INPUT,
		LOW_DECAY_INPUT,
		LOW_LEVEL_INPUT,
		MID_TONE_INPUT,
		MID_CHARACTER_INPUT,
		MID_LP_INPUT,
		MID_HP_INPUT,
		MID_DECAY_INPUT,
		MID_LEVEL_INPUT,
		TRIG_INPUT,
		HEAD_TONE_INPUT,
		HEAD_CHARACTER_INPUT,
		HEAD_LP_INPUT,
		HEAD_HP_INPUT,
		HEAD_DECAY_INPUT,
		HEAD_LEVEL_INPUT,
		NUM_INPUTS
	};
	enum OutputIds {
		OUTPUT_OUTPUT,
		NUM_OUTPUTS
	};
	enum LightIds {
		NUM_LIGHTS
	};

	Kick() {
		config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
		configParam(LOW_FUNDAMENTAL_PARAM, 0.f, 1.f, 0.f, "");
		configParam(LOW_PARTIALS_PARAM, 0.f, 1.f, 0.f, "");
		configParam(LOW_SPREAD_PARAM, 0.f, 1.f, 0.f, "");
		configParam(LOW_BEND_PARAM, 0.f, 1.f, 0.f, "");
		configParam(LOW_DECAY_PARAM, 0.f, 1.f, 0.f, "");
		configParam(LOW_LEVEL_PARAM, 0.f, 1.f, 0.f, "");
		configParam(MID_TONE_PARAM, 0.f, 1.f, 0.f, "");
		configParam(MID_CHARACTER_PARAM, 0.f, 1.f, 0.f, "");
		configParam(MID_LP_PARAM, 0.f, 1.f, 0.f, "");
		configParam(MID_HP_PARAM, 0.f, 1.f, 0.f, "");
		configParam(MID_DECAY_PARAM, 0.f, 1.f, 0.f, "");
		configParam(MID_LEVEL_PARAM, 0.f, 1.f, 0.f, "");
		configParam(HEAD_TONE_PARAM, 0.f, 1.f, 0.f, "");
		configParam(HEAD_CHARACTER_PARAM, 0.f, 1.f, 0.f, "");
		configParam(HEAD_LP_PARAM, 0.f, 1.f, 0.f, "");
		configParam(HEAD_HP_PARAM, 0.f, 1.f, 0.f, "");
		configParam(HEAD_DECAY_PARAM, 0.f, 1.f, 0.f, "");
		configParam(HEAD_LEVEL_PARAM, 0.f, 1.f, 0.f, "");
	}

	void process(const ProcessArgs& args) override {
	}
};


struct KickWidget : ModuleWidget {
	KickWidget(Kick* module) {
		setModule(module);
		setPanel(APP->window->loadSvg(asset::plugin(pluginInstance, "res/Kick.svg")));

		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

		addParam(createParamCentered<RoundLargeBlackKnob>(mm2px(Vec(30.48, 21.417)), module, Kick::LOW_FUNDAMENTAL_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(50.8, 21.417)), module, Kick::LOW_PARTIALS_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(71.12, 21.417)), module, Kick::LOW_SPREAD_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(91.44, 21.417)), module, Kick::LOW_BEND_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(111.76, 21.417)), module, Kick::LOW_DECAY_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(132.08, 21.417)), module, Kick::LOW_LEVEL_PARAM));
		addParam(createParamCentered<RoundLargeBlackKnob>(mm2px(Vec(30.48, 64.25)), module, Kick::MID_TONE_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(50.8, 64.25)), module, Kick::MID_CHARACTER_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(71.12, 64.25)), module, Kick::MID_LP_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(91.44, 64.25)), module, Kick::MID_HP_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(111.76, 64.25)), module, Kick::MID_DECAY_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(132.08, 64.25)), module, Kick::MID_LEVEL_PARAM));
		addParam(createParamCentered<RoundLargeBlackKnob>(mm2px(Vec(30.48, 107.083)), module, Kick::HEAD_TONE_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(50.8, 107.083)), module, Kick::HEAD_CHARACTER_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(71.12, 107.083)), module, Kick::HEAD_LP_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(91.44, 107.083)), module, Kick::HEAD_HP_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(111.76, 107.083)), module, Kick::HEAD_DECAY_PARAM));
		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(132.08, 107.083)), module, Kick::HEAD_LEVEL_PARAM));

		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(30.48, 33.464)), module, Kick::LOW_FUNDAMENTAL_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(50.8, 33.464)), module, Kick::LOW_PARTIALS_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(71.12, 33.464)), module, Kick::LOW_SPREAD_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(91.44, 33.464)), module, Kick::LOW_BEND_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(111.76, 33.464)), module, Kick::LOW_DECAY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(132.08, 33.464)), module, Kick::LOW_LEVEL_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(30.48, 76.297)), module, Kick::MID_TONE_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(50.8, 76.297)), module, Kick::MID_CHARACTER_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(71.12, 76.297)), module, Kick::MID_LP_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(91.44, 76.297)), module, Kick::MID_HP_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(111.76, 76.297)), module, Kick::MID_DECAY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(132.08, 76.297)), module, Kick::MID_LEVEL_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(154.94, 102.629)), module, Kick::TRIG_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(30.48, 119.13)), module, Kick::HEAD_TONE_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(50.8, 119.13)), module, Kick::HEAD_CHARACTER_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(71.12, 119.13)), module, Kick::HEAD_LP_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(91.44, 119.13)), module, Kick::HEAD_HP_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(111.76, 119.13)), module, Kick::HEAD_DECAY_INPUT));
		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(132.08, 119.13)), module, Kick::HEAD_LEVEL_INPUT));

		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(154.94, 119.004)), module, Kick::OUTPUT_OUTPUT));
	}
};


Model* modelKick = createModel<Kick, KickWidget>("Kick");