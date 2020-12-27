#pragma once

class ControlInterface {
    public:
        virtual float getParam(int param);
        virtual float getInput(int input);
        virtual void setOutput(int output, float val);
        virtual void setLight(int light, float val);
};