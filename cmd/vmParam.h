//
// Created by LJT on 17-4-12.
//

#ifndef EZJVM_PARAM_H
#define EZJVM_PARAM_H

#include <string>
#include <vector>
#include "cliParser.h"

namespace ez
{
    namespace cmd
    {
        using namespace std;
        class vmParam
        {
        public:
            vmParam(const cliParser &cliParser);
            virtual ~vmParam();

            const string &getClasspath() const;

            void setClasspath(const string &classpath);

            const string &getClazz() const;

            void setClazz(const string &clazz);

            const vector<string> &getArgs() const;

            void setArgs(const vector<string> &args);

            int checkParam();

            const string printUsage() const;

        private:
            string classpath;
            string clazz;
            vector<string> args;
        };
    }//end of cmd
}//end of ez


#endif //EZJVM_PARAM_H
