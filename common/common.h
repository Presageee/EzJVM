//
// Created by LJT on 17-4-12.
//

#ifndef EZJVM_COMMON_H
#define EZJVM_COMMON_H

#endif //EZJVM_COMMON_H

#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <memory>

#define VMSTDOUT(str) std::cout << str << std::endl;
#define VMPOUT(str) printf("%s\n", str)



#define VMOK 0

#define VMERR -1

#define ASSERTVMOK(status, message) if (VMOK != status) {\
    VMSTDOUT(message);\
    exit(0);\
}

#define ASSERTVMOPENFILEOK(stream, message) if (!stream) {\
    VMSTDOUT(message);\
    exit(0);\
}

#define ASSERTVMERR(status, message) if (VMERR == status) {\
    VMSTDOUT(message);\
    exit(0);\
}


#define FILE_SEPARATOR "/"

#define CLAZZ_SUFFIX ".class"

#define BUILDMESSAGE3(str, m1, m2, m3) str.append(m1).append(m2).append(m3)

//namespace ez
//{
//    namespace common
//    {
        template <typename T>
        std::shared_ptr<T> make_shared_array(size_t size)
        {
            return std::shared_ptr<T>(new T[size], std::default_delete<T[]>());
        }
//    }
//}
