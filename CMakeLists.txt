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
        classpath/zipClasspath.h
        zip/ioapi.h
        zip/ioapi.c
        zip/unzip.c
        zip/unzip.h)

#head
include_directories(${PROJECT_SOURCE_DIR}/include)

#3rdpart static obj
#[[link_directories(${PROJECT_SOURCE_DIR}/3rdparty)]]
link_libraries(${PROJECT_SOURCE_DIR}/3rdparty/libz.a)

add_executable(EzJVM ${SOURCE_FILES})
