#pragma once

#include "ControlInterface.hpp"
#include "MyModule.hpp"

namespace mymodule
{
    class MyModuleControls {
        public:
            MyModuleControls() = default;
            MyModuleControls(ControlInterface& i)
            {
                interface = i;
            }
            float getPitch();
            float getInputVoltage();
            void setOutputVoltage(float v);
            void setLightBrightness(float b);
        private:
            ControlInterface interface;
            float getParam(int param) {return interface.getParam(param);}
            float getInput(int input) {return interface.getInput(input);}
            void setOutput(int output, float val) {interface.setOutput(output, val);}
            void setLight(int light, float val) {interface.setLight(light, val);}
    };
};