//
// Created by LJT on 17-4-12.
//

#include "vmParam.h"
#include <iostream>
#include <sstream>
#include "../common/common.h"


namespace ez
{
    namespace cmd
    {
        vmParam::vmParam(const cliParser &cliParser)
        {
            classpath = cliParser.getStr("classpath", "");
            clazz = cliParser.getStr("class", "");
            // clear exists param
            if (args.size() > 0)
            {
                args.clear();
            }

            string tmp = cliParser.getStr("param", "");
            stringstream ss(tmp);
            string param;
            while (getline(ss, param, ' '))
            {
                args.push_back(param);
            }
            for (auto str : args)
            {
                VMSTDOUT(str);
            }
            //VMSTDOUT("success");
        }

        vmParam::~vmParam()
        {

        }

        const string &vmParam::getClasspath() const {
            return classpath;
        }

        void vmParam::setClasspath(const string &classpath) {
            vmParam::classpath = classpath;
        }

        const string &vmParam::getClazz() const {
            return clazz;
        }

        void vmParam::setClazz(const string &clazz) {
            vmParam::clazz = clazz;
        }

        const vector<string> &vmParam::getArgs() const {
            return args;
        }

        void vmParam::setArgs(const vector<string> &args) {
            vmParam::args = args;
        }

        int vmParam::checkParam()
        {
            if (!classpath.compare(""))
            {
                return VMERR;
            }

            if (!clazz.compare(""))
            {
                return VMERR;
            }

            return VMOK;
        }

        const string vmParam::printUsage() const
        {
            string str = "Usage:\n"\
            "--classpath [value] java core class path\n"\
            "--class [value] .class file\n"\
            "--param [value ...] app running params\n";
            return str;
        }
    }
}

