#pragma once
#include "ModuleControls.hpp"

class ModuleEngine {
    ModuleControls *controls;
    public:
        ModuleEngine() = default;
        ModuleEngine(ModuleControls *controls) { this->controls = controls; }
        virtual void process(float sampleRate, float sampleTime) = 0;
};