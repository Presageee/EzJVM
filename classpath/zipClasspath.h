//
// Created by LJT on 17-4-14.
//

#ifndef EZJVM_ZIPCLASSPATH_H
#define EZJVM_ZIPCLASSPATH_H

#endif //EZJVM_ZIPCLASSPATH_H


#include "classpath.h"
#include "../zip/unzip.h"
#include <zlib.h>


namespace ez
{
    namespace classpath
    {
#define WRITEBUFFERSIZE (1242880) // 5MB

        class zipClasspath: public classpath
        {
        public:
            zipClasspath(const string &zipPath)
            {
                this->zipPath = zipPath;
                uf = unzOpen64(this->zipPath.c_str());
            }

            ~zipClasspath() override
            {
                unzClose(uf);
            }

            unsigned char *readClass(const string &clazzName) override
            {
                return classpath::readClass(clazzName);
            }

            string toString() override
            {
                return classpath::toString();
            }

            int getFileInZip(const string& zipFile, const string& className)
            {
                int status = UNZ_OK;
                uInt buffSize = WRITEBUFFERSIZE;
                void* buf;
                string sout;
                char filename_inzip[256];
                unz_file_info file_info;

                //unzFile uf = unzOpen64(zipFile.c_str());
                if (NULL == uf)
                {
                    string msg;
                    EXCEPTION_EXIT(BUILDMESSAGE3(msg, "open ", zipFile, " failed"));
                }

                if (unzLocateFile(uf, className.c_str(), 1))
                {
                    string msg;
                    EXCEPTION_EXIT(BUILDMESSAGE3(msg, "", className, " not found"));
                }

                if (unzGetCurrentFileInfo(uf, &file_info, filename_inzip, sizeof(filename_inzip),
                                          NULL, 0, NULL, 0))
                {
                    string msg;
                    EXCEPTION_EXIT(BUILDMESSAGE3(msg, "get ", className, " info error"));
                }

                buf = new unsigned char[file_info.uncompressed_size];

                status = unzOpenCurrentFilePassword(uf, NULL);
                if (status != UNZ_OK)
                {
                    string msg;
                    EXCEPTION_EXIT(BUILDMESSAGE3(msg, "get ",className, " openCurrentFile error"));
                }

                do
                {
                    status = unzReadCurrentFile(uf, buf, buffSize);
                    if (status < 0)
                    {
                        string msg;
                        EXCEPTION_EXIT(BUILDMESSAGE3(msg, "read ", className, " error"));
                    }
                    shared_ptr<unsigned char> data = make_shared_array<unsigned char>(status);
                    for (int i = 0; i < (int) status; i++)
                    {
                        data.get()[i] = *((unsigned char*)buf + i);
                    }
                    classMap[className] = data;
                    for (int i = 0; i < status; i++)
                    {
                        cout << (int)data.get()[i] << " ";
                    }
                }
                while(status > 0);

                status = unzCloseCurrentFile(uf);
                if (status != UNZ_OK)
                {
                    string msg;
                    EXCEPTION_EXIT(BUILDMESSAGE3(msg, "close ", className, " error"));
                }
                delete[] (unsigned char*)buf;
                return VMOK;
            }

        private:
            string zipPath;
            unzFile uf;
        };



    }
}