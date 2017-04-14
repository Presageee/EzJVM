//
// Created by LJT on 17-4-14.
//

#include "classpath.h"

#ifndef EZJVM_ZIPCLASSPATH_H
#define EZJVM_ZIPCLASSPATH_H

#endif //EZJVM_ZIPCLASSPATH_H


namespace ez
{
    namespace classpath
    {
        class zipClasspath: public classpath
        {
        public:
            zipClasspath(const string &zipPath){
                this->zipPath = zipPath;
            }

            ~zipClasspath() override {

            }

            unsigned char *readClass(const string &clazzName) override {
                return classpath::readClass(clazzName);
            }

            string toString() override {
                return classpath::toString();
            }

        private:
            string zipPath;
        };
    }
}