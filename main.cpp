#include <iostream>
#include "cmd/CliParser.h"
#include "cmd/Param.h"


using namespace ez;
void startVM(int args, char ** argv)
{
    cmd::CliParser parser;
    parser.parse(args, argv);
    parser.print();
    cmd::Param param(parser);
}

int main(int args, char** argv) {
    startVM(args, argv);
    return 0;
}