#pragma once
#include "../ModuleEngine.hpp"
#include "KickControls.hpp"
#include "../DecayEnvelope.hpp"

namespace kick{

    class KickEngine : ModuleEngine {
        KickControls *controls;
        public:
        KickEngine(KickControls *controls)
        {
            this->controls = controls;
        }
        void process(float sampleRate, float sampleTime) override;
        private:
        float phase = 0.f;
        float processLows(float sampleRate, float sampleTime);
        float processMids(float sampleRate, float sampleTime);
        float processHighs(float sampleRate, float sampleTime);
    };
} //namespace Kick