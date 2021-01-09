#pragma once
#include "../ModuleEngine.hpp"
#include "KickControls.hpp"

namespace kick{

    class KickEngine : ModuleEngine {
        public:
        KickEngine(ModuleControls *controls) : ModuleEngine { controls }
        {

        }
        void process(float sampleRate, float sampleTime);
    };
} //namespace Kick