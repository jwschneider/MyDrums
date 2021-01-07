#pragma once
#include "../src/MyModule/MyModuleControls.hpp"

class TestHarness {
    public:
        TestHarness() = default;        
        TestHarness(int numParams, int numInputs, int numOutputs, int numLights);
        mymodule::MyModuleControls* getControls();
    private:
        void initMembers(int numParams, int numInputs, int numOutputs, int numLights);
        mymodule::MyModuleControls* ctrl;
        vector<Param> params;
        vector<Output> outputs;
        vector<Input> inputs;
        vector<Light> lights;
        vector<ParamQuantity*> paramQuantities;
};