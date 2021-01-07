#pragma once
#include "../src/MyModule/MyModuleControls.hpp"

class TestHarness {
    public:
        TestHarness() = default;        
        TestHarness(int numParams, int numInputs, int numOutputs, int numLights);
        ~TestHarness();
        mymodule::MyModuleControls* getControls();
        void setParam(int param, float val);
        void setInput(int input, float val);
        float getLight(int light);
        float getOutput(float output);
    private:
        void initMembers(int numParams, int numInputs, int numOutputs, int numLights);
        void destroyMembers();
        mymodule::MyModuleControls* ctrl;
        vector<Param> params;
        vector<Output> outputs;
        vector<Input> inputs;
        vector<Light> lights;
        vector<ParamQuantity*> paramQuantities;
};