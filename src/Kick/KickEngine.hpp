#pragma once
#include "../ModuleEngine.hpp"
#include "KickControls.hpp"

namespace kick{

    class KickEngine : ModuleEngine {
        KickControls *controls;
        public:
        KickEngine(KickControls *controls)
        {
            this->controls = controls;
        }
        void process(float sampleRate, float sampleTime) override;
    };
} //namespace Kick