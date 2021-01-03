#include "../src/MyModule/MyModuleControls.hpp"

class TestHarness {
    public:        
        TestHarness(int numParams, int numInputs, int numOutputs, int numLights);
        mymodule::MyModuleControls* getControls();
};