//
// Created by LJT on 17-4-13.
//

#ifndef EZJVM_CLASSPATH_H
#define EZJVM_CLASSPATH_H

#endif //EZJVM_CLASSPATH_H

#include <string>
#include <map>
#include <memory>
#include <sys/stat.h>
#include "../common/common.h"


namespace ez
{
    namespace classpath
    {
        using namespace std;

        static map<string, shared_ptr<unsigned char>> classMap;

        inline shared_ptr<unsigned char> &getClass(const string& name)
        {
            classMap.end() != classMap.find(name) ? classMap.find(name)->second : nullptr;
        }

        class classpath
        {
        public:
            classpath()
            {

            }
            virtual ~classpath()
            {

            }

            virtual unsigned char* readClass(const string &clazzName)
            {

            }

            virtual string toString(){};

            virtual inline unsigned long getFileLength(const string &path)
            {
                struct stat info;
                if (stat(path.c_str(), &info) < 0)
                {
                    return (unsigned long)VMERR;
                }
                else
                {
                    return (unsigned long)info.st_size;
                }
            }

        };
    }//end of classpath
}//end of ez