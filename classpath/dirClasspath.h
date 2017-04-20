//
// Created by LJT on 17-4-13.
//

#ifndef EZJVM_DIRCLASSPATH_H
#define EZJVM_DIRCLASSPATH_H

#endif //EZJVM_DIRCLASSPATH_H

#include <fstream>
#include "classpath.h"

namespace ez
{
    namespace classpath
    {
        //using namespace common;

        class dirClasspath: public classpath
        {
        public:
            dirClasspath(const string &dirPath)
            {
                this->dirPath = dirPath;
            }

            ~dirClasspath() override
            {}

            unsigned char *readClass(const string &clazzName) override
            {
                string clazz;
                clazz.append(dirPath)
                        .append(FILE_SEPARATOR)
                        .append(clazzName)
                        .append(CLAZZ_SUFFIX);
                shared_ptr<unsigned char> data;
                if (nullptr != (data = getClass(clazz))) {
                    return data.get();
                }
                //read file
                std::ifstream in(clazz, ios::in | ios::binary);
                string errMsg;
                ASSERTVMOPENFILEOK(in, BUILDMESSAGE3(errMsg, "open ", clazz, " error"));
                unsigned long size = -1;
                string readSizeErrMsg;
                ASSERTVMERR((size = getFileLength(clazz)),
                            BUILDMESSAGE3(readSizeErrMsg, "read ", clazz, " size error"));
                data = make_shared_array<unsigned char>(size);
                in.read((char *)data.get(), size);
                classMap[clazzName] = data;
                return data.get();
            }

            string toString() override
            {
                return dirPath;
            }


        private:
            string dirPath;
        };
    }
}
