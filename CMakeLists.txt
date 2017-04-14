cmake_minimum_required(VERSION 3.7)
project(EzJVM)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp cmd/cliParser.h
        common/common.h
        cmd/cliParser.cpp
        cmd/vmParam.cpp
        cmd/vmParam.h
        classpath/classpath.h
        classpath/cpReader.h
        classpath/dirClasspath.h
        classpath/zipClasspath.h)
add_executable(EzJVM ${SOURCE_FILES})