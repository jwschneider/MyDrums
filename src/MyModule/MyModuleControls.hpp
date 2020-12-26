#include "ControlInterface.hpp"

namespace mymodule
{
    class MyModuleControls {
        public:
            MyModuleControls(ControlInterface& i)
            {
                interface = i;
            }
        private:
            ControlInterface interface;
            float getParam(int param) {return interface.getParam(param);}
            float getInput(int input) {return interface.getInput(input);}
            void setOutput(int output, float val) {interface.setOutput(output, val);}
            void setLight(int light, float val) {interface.setLight(light, val);}
    };
};