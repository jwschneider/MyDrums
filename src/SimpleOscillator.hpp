class SimpleOscillator {
    public:
        SimpleOscillator() {
            frequency = 0;
            magnitude = 1;
            phase = 0;
        }
        SimpleOscillator(float freq) : SimpleOscillator {} {
            frequency = freq;
        }
        void setFrequency(float freq);
        void setMagnitude(float mag);
        void process(float sampleRate, float sampleTime);
        float getReal();
        float getImaginary();
        void reset() {
            phase = 0.f;
        }
    private:
        float frequency;
        float magnitude;
        float phase;
};