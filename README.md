# Unit Test Playground

## Introduction
This repository serves as a playground for getting started with writing
unit tests with the googletest (gtest) framework.
The code is split into two parts, production code and test code.
Production code are the software parts which are delivered to the customer
or are used to build the binaries. The test code is usually seperated from
the production code and is used to verify the functionality of the
production code. Once the code is verified, the test software is removed and
the production code gets shipped.

## Production Code
Production code should be added to the directories 'src' and 'include'.
The source files (cpp) have to be added to the CMakeLists.txt file, in order
to be built. A comment in the file indicates where to add them.

## Test Code
All test related code should be added to the 'unit\_tests' directory.
Similar to other source files, their names and path have to be added to the
CMakeLists.txt file.<br />

The unit\_tests directory already contains to files, namely test\_runner.cpp
and test\_template.cpp. The former automatically picks up all defined tests
and runs them. You can edit this file but usually you are not required to do
so. The test\_template.cpp includes everything you should need to get started
with writing your own tests.

## Building the Software
The software is built using cmake and requires a network connection if built
for the first time to download the googletest framework. <br />

The build.sh will create a 'build' directory and perform all necessary steps
to build the test application.
If everything works as expected, the application test\_runner should be
present in the build directory. Commandline arguments are forwarded to
googletest. Call the application with the help flag (--help) to get yourself
familiar with its options.

