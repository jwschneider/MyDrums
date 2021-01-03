#pragma once
#include "MyModuleControls.hpp"

namespace mymodule {

    class MyModuleEngine {
        MyModuleControls controls;
        float phase;
        float blinkPhase;
        public:
            MyModuleEngine() = default;
            MyModuleEngine(MyModuleControls& controls);
            void process(float sampleRate, float sampleTime);
    };

}; //namespace mymodule