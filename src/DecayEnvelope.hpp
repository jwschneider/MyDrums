// http://www.martin-finke.de/blog/articles/audio-plugins-011-envelopes/
#include <cmath>

using namespace std;

class DecayEnvelope {
    public:
        DecayEnvelope() = default;
        DecayEnvelope(float duration, float sampleRate)
        {
            this->sampleRate = sampleRate;
            currentLevel = 1.f;
            multiplier = 1.0 + log(minimumLevel)/(sampleRate * duration);
        }
        void process(float sampleRate, float sampleTime);
        float getValue();
    private:
        float nextSample() {
            currentLevel *= multiplier;
            return currentLevel;
        }
        const float minimumLevel = 0.0001;
        float currentLevel;
        float multiplier;
        float sampleRate;
};