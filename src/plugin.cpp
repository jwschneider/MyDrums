#include "plugin.hpp"

#include "MyModule/MyModule.hpp"
using namespace mymodule;

Plugin* pluginInstance;


void init(Plugin* p) {
	pluginInstance = p;

	// Add modules here
	p->addModel(createModel<mymodule::MyModule, mymodule::MyModulePanel>("MyModule"));
	//p->addModel(modelKick);
	// Any other plugin initialization may go here.
	// As an alternative, consider lazy-loading assets and lookup tables when your module is created to reduce startup times of Rack.
}
