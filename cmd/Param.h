//
// Created by LJT on 17-4-12.
//

#ifndef EZJVM_PARAM_H
#define EZJVM_PARAM_H

#include <string>
#include <vector>
#include "CliParser.h"

namespace ez
{
    namespace cmd
    {
        using namespace std;
        class Param
        {
        public:
            Param(const CliParser &cliParser);
            virtual ~Param();

            const string &getClasspath() const;

            void setClasspath(const string &classpath);

            const string &getClazz() const;

            void setClazz(const string &clazz);

            const vector<string> &getArgs() const;

            void setArgs(const vector<string> &args);

            int checkParam();

        private:
            string classpath;
            string clazz;
            vector<string> args;
        };
    }//end of cmd
}//end of ez


#endif //EZJVM_PARAM_H
