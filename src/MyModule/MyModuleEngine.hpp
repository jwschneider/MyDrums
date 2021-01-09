#pragma once
#include "../ModuleEngine.hpp"
#include "MyModuleControls.hpp"

namespace mymodule {

    class MyModuleEngine : ModuleEngine {
        float phase;
        float blinkPhase;
        MyModuleControls *controls;
        public:
            MyModuleEngine(MyModuleControls *controls)
            {
                phase = 0.f;
                blinkPhase = 0.f;
                this->controls = controls;
            };
            void process(float sampleRate, float sampleTime) override;
    };

}; //namespace mymodule