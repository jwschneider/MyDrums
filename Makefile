# If RACK_DIR is not defined when calling the Makefile, default to two directories above
RACK_DIR ?= ../..

# FLAGS will be passed to both the C and C++ compiler
FLAGS +=
CFLAGS +=
CXXFLAGS +=

# Careful about linking to shared libraries, since you can't assume much about the user's environment and library search path.
# Static libraries are fine, but they should be added to this plugin's build system.
LDFLAGS +=

# Add .cpp files to the build
SOURCES += $(wildcard src/*.cpp)

# Add files to the ZIP package when running `make dist`
# The compiled plugin and "plugin.json" are automatically added.
DISTRIBUTABLES += res
DISTRIBUTABLES += $(wildcard LICENSE*)

# Include the Rack plugin Makefile framework
include $(RACK_DIR)/plugin.mk

#CPPUTest Makefile Variables
#--- Input Variables
TEST_SRC_DIRS = \
	test

SRC_DIRS = \
	src

INCLUDE_DIRS = \
	$(CPPUTEST_HOME)/include \
	$(RACK_DIR)/include \
	$(RACK_DIR)/dep/include

#--- Additional variables
COMPONENT_NAME = MyDrums
CPPUTEST_HOME = ../cpputest
CPPUTEST_OBJS_DIR = build
TEST_TARGET=test_runner
CPPUTEST_WARNINGFLAGS =  -Wall -Wextra -Wswitch-default -Wswitch-enum -Wno-long-long -Wno-unused-parameter
CPPUTEST_MEMLEAK_DETECTOR_NEW_MACRO_FILE = -include test/NewMacros.h
CPPUTEST_LDFLAGS := -shared -L$(RACK_DIR) -lRack



#run MakefileWorker.mk with the variables defined here
include $(CPPUTEST_HOME)/build/MakefileWorker.mk

