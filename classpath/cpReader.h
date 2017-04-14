//
// Created by LJT on 17-4-13.
//

#ifndef EZJVM_CPREADER_H
#define EZJVM_CPREADER_H

#endif //EZJVM_CPREADER_H

#include <string>

namespace ez
{
    namespace classpath
    {
        using namespace std;
        class cpReader
        {
        public:
            cpReader(const string &classpath)
            {
                this->classpath = classpath;
            }

            virtual ~cpReader(){

            }

            unsigned char* readClass(string clazzName);
        private:
            string classpath;
        };
    }
}