#pragma once
#include "../ModuleControls.hpp"
#include "Kick.hpp"

namespace kick {
class KickControls : public ModuleControls {
    public:
    KickControls(vector<Param>* p, vector<Output>* o, vector<Input>* i, vector<Light>* l, vector<ParamQuantity*>* pq) : ModuleControls {p, o, i, l, pq}
    {

    }
    void setOutputVoltage(float val)
    {
        this->setOutput(Kick::OUTPUT_OUTPUT, val);
    }
    // Fundamental frequency in [10, 100] Hz
    float getFundamentalFQ();
    // Frequency spread in [0, 90] Hz
    float getFQSpread();
    // Get Bend in [-1, 1] unitless
    float getBend();
    // Gets number of partials to include in [0, 16]
    int getPartials();
    // Gets amplitude in [0, 1]
    float getLevel();
};
} //namespace Kick