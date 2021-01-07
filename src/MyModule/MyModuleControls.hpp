//#include <plugin/Model.hpp>
#pragma once
#include <engine/Param.hpp>
#include <engine/Port.hpp>
#include <engine/Light.hpp>
#include <engine/ParamQuantity.hpp>
#include <vector>

using namespace rack::engine;
using namespace std;

namespace mymodule
{
    class MyModuleControls {
        public:
            MyModuleControls() = default;
            MyModuleControls(vector<Param>& p, vector<Output>& o, vector<Input>& i, vector<Light>& l, vector<ParamQuantity*>& pq);
            float getPitch();
            float getInputVoltage();
            void setOutputVoltage(float v);
            void setLightBrightness(float b);
        private:
            float getParam(int param);
            float getInput(int input);
            void setOutput(int output, float val);
            void setLight(int light, float val);
            vector<Param> params;
            vector<Output> outputs;
            vector<Input> inputs;
            vector<Light> lights;
            vector<ParamQuantity*> paramQuantities;
    };
};