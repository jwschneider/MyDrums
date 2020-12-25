#include "MyModuleControls.hpp"

namespace mymodule {
    MyModuleControls Controls;
    class MyModuleEngine {
        public:
            MyModuleEngine(MyModuleControls *controls);
            void process();
    };

}; //namespace mymodule