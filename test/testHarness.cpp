#include "testHarness.hpp"

class TestHarness {
    public:
        TestHarness(int numParams, int numInputs, int numOutputs, int numLights)
        {
            initMembers(numParams, numInputs, numOutputs, numLights);
            ctrl = new mymodule::MyModuleControls(params, outputs, inputs, lights, paramQuantities);
        }
        mymodule::MyModuleControls *getControls()
        {
            return ctrl;
        }
    private:
        void initMembers(int numParams, int numInputs, int numOutputs, int numLights)
        {
            for (int i = 0; i < numParams; i++)
            {
                Param* p = new Param;
                params.push_back(*p);
            }
            for (int i = 0; i < numInputs; i++)
            {
                Input* p = new Input;
                inputs.push_back(*p);
            }
            for (int i = 0; i < numOutputs; i++)
            {
                Output* p = new Output;
                outputs.push_back(*p);
            }            
            for (int i = 0; i < numLights; i++)
            {
                Light* p = new Light;
                lights.push_back(*p);
            }
            for (int i = 0; i < numParams; i++)
            {
                ParamQuantity* p = new ParamQuantity;
                paramQuantities.push_back(p);
            }
        }
        mymodule::MyModuleControls* ctrl;
        vector<Param> params;
        vector<Output> outputs;
        vector<Input> inputs;
        vector<Light> lights;
        vector<ParamQuantity*> paramQuantities;
};