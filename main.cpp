#include <iostream>
#include <fstream>
#include <cstring>
#include "cmd/cliParser.h"
#include "cmd/vmParam.h"
#include "classpath/dirClasspath.h"

using namespace ez;
using namespace classpath;
using namespace std;
void startVM(int args, char ** argv)
{
    cmd::cliParser parser;
    parser.parse(args, argv);
    parser.print();
    cmd::vmParam param(parser);
    ASSERTVMOK(param.checkParam(), param.printUsage())
}

int main(int args, char** argv) {
    ASSERTVMOK(0,"");

        dirClasspath dirClasspath1("/home/sensetime/Desktop/");
        cout << dirClasspath1.readClass("111.jpg") << endl;
    startVM(args, argv);
    return 0;
}