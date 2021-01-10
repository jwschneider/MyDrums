#include "KickEngine.hpp"

using namespace kick;
using namespace dsp;

class FreqMagPair
{

    public:
        FreqMagPair() {
            val = new tuple {0.f, 0.f};
        }
        FreqMagPair(float freq, float magnitude)
        {
            val = new tuple {freq, magnitude};
        }
        ~FreqMagPair() {
            delete val;
        }
        float GetFrequency() { return std::get<0>(*val); }
        float GetMagnitude() { return std::get<1>(*val); }
    private:
        tuple<float, float> *val;
};

float scaleFrequency(float freq, float fundamental, float spread, int partials, float bend)
{
    return (1 + bend * (spread * (partials - 1) * freq + fundamental));
}

float KickEngine::processLows(float sampleRate, float sampleTime)
{
    vector<FreqMagPair*> FQs;
    float fun = controls->getFundamentalFQ();
    int partials = controls->getPartials();
    float spread = controls->getFQSpread();
    float bend = controls->getBend();
    for (int i = 0; i < partials; i++)
    {
        float frequency = fun + spread * i;
        FQs.push_back(new FreqMagPair(frequency, scaleFrequency(frequency, fun, spread, partials, bend)));
    }
    // accumulate and scale by decay
}

void KickEngine::process(float sampleRate, float sampleTime) {
    float out = 0;
    out += processLows(sampleRate, sampleTime);
    out += processMids(sampleRate, sampleTime);
    out += processHighs(sampleRate, sampleTime);
    controls->setOutputVoltage(out);
}

