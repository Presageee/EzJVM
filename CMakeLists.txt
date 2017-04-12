cmake_minimum_required(VERSION 3.7)
project(EzJVM)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp cmd/CliParser.h common/common.h cmd/CliParser.cpp)
add_executable(EzJVM ${SOURCE_FILES})