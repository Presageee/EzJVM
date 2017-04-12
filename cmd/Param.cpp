//
// Created by LJT on 17-4-12.
//

#include "Param.h"
#include <iostream>

namespace ez {
    namespace cmd {
        Param::Param(const CliParser &cliParser)
        {
            cout << "success" << endl;
        }

        Param::~Param()
        {

        }

        const string &Param::getClasspath() const {
            return classpath;
        }

        void Param::setClasspath(const string &classpath) {
            Param::classpath = classpath;
        }

        const string &Param::getClazz() const {
            return clazz;
        }

        void Param::setClazz(const string &clazz) {
            Param::clazz = clazz;
        }

        const vector<string> &Param::getArgs() const {
            return args;
        }

        void Param::setArgs(const vector<string> &args) {
            Param::args = args;
        }

        int Param::checkParam()
        {

        }
    }
}

