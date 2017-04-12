#include <iostream>
#include "cmd/CliParser.h"

void startVM(int args, char ** argv)
{
    ez::cli::CliParser parser;
    parser.parse(args, argv);
    parser.print();
}

int main(int args, char** argv) {
    startVM(args, argv);
    return 0;
}