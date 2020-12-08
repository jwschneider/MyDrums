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


#Test framework
# test: test/build/main.cpp.o test/build/testKick.cpp.o
# 	$(CCX) $(CXXFLAGS) -o test/main test/build/main.cpp.o test/build/testKick.cpp.o

# test/build/main.cpp.o: test/main.cpp test/testKick.hpp
# 	$(CCX) $(CXXFLAGS) -o test/build/main.cpp.o  test/main.cpp

# test/build/testKick.cpp.o: test/testKick.cpp test/testKick.hpp
# 	$(CCX) $(CXXFLAGS) -o test/build/testKick.cpp.o test/testKick.cpp

#TEST_SOURCES = $(wildcard test/*.cpp)

#TEST_OBJECTS = $(patsubst %, build_test/%.o, $(TEST_SOURCES))
#--------------------
CPPUTEST_HOME = C:/msys64/home/John/cpputest
CPPFLAGS += -I$(CPPUTEST_HOME)/include
CXXFLAGS += -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorNewMacros.h
CFLAGS += -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorMallocMacros.h

LD_LIBRARIES = -L$(CPPUTEST_HOME)/cpputest_build/lib -lCppUTest -lCppUTestExt

TEST_SOURCES = test/testKick.cpp

TEST_OBJECTS = build_test/testKick.cpp.o

build_test/testKick.cpp.o: test/testKick.cpp
	mkdir -p $(@D)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $^

build_test/main: test/main.cpp $(TEST_OBJECTS)
	mkdir -p $(@D)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $^ $(LD_LIBRARIES)

test: build_test/main
	build_test/main.exe

cleantest:
	rm -rfv build_test
	rm -fv test.exe

