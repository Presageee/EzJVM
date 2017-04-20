#include <iostream>
#include <fstream>
#include <cstring>
#include "cmd/cliParser.h"
#include "cmd/vmParam.h"
#include "classpath/zipClasspath.h"

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
    classpath::zipClasspath zipClasspath1("/home/sensetime/Desktop/333.jpg.zip");
    zipClasspath1.getFileInZip("", "333.jpg");
    cout << endl;
    zipClasspath1.getFileInZip("", "verify.db");
    startVM(args, argv);
    return 0;
}