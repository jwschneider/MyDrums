// http://www.martin-finke.de/blog/articles/audio-plugins-011-envelopes/
#include <cmath>

using namespace std;

class DecayEnvelope {
    public:
        DecayEnvelope(float duration, float sampleRate)
        {
            this->sampleRate = sampleRate;
            currentLevel = 1.f;
            multiplier = 1.0 + log(minimumLevel)/(sampleRate * duration);
        }
        float nextSample() {
            currentLevel *= multiplier;
            return currentLevel;
        }
    private:
        const float minimumLevel = 0.0001;
        float currentLevel;
        float multiplier;
        float sampleRate;
};