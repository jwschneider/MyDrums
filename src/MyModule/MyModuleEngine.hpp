#pragma once
#include "MyModuleControls.hpp"

namespace mymodule {

    class MyModuleEngine {
        float phase;
        float blinkPhase;
        MyModuleControls *controls;
        public:
            MyModuleEngine(MyModuleControls *ctrl)
            {
                phase = 0.f;
                blinkPhase = 0.f;
                controls = ctrl;
            };
            void process(float sampleRate, float sampleTime);
    };

}; //namespace mymodule