//
// Created by LJT on 17-4-12.
//

#include "CliParser.h"
#include <iostream>

namespace ez {
    namespace cli {
        using namespace std;

        CliParser::CliParser()
        {
            lastErr[0] = '\0';
            properties.clear();
        }

        CliParser::~CliParser()
        {

        }

        int CliParser::parse(int argc, char **argv)
        {
            string key = "";
            string value = "";

            for (int i = 1; i < argc; i++)
            {
                string str = argv[i];

                int pos = 0;
                for (; '-' == str[pos]; pos++)
                {

                }

                // Handle the minus number, don't treated it as key
                if ((1 == pos) && (1 < str.length()) && ('0' <= str[pos] && '9' >= str[pos]))
                {
                    pos = 0;
                }

                if (0 != pos)
                {
                    if (0 < key.length())
                    {
                        properties[key] = value;
                    }
                    key = str.substr(pos);
                    value = "";
                }
                else
                {
                    if (0 < value.length())
                    {
                        value += " " + str;
                    }
                    else
                    {
                        value = str;
                    }
                }
            }

            if (0 < key.length())
            {
                properties[key] = value;
            }

            return 0;
        }

        void CliParser::print()
        {
            map<string, string>::const_iterator it = begin();
            for (;it != end(); it++)
            {
                cout << it->first << "=" << it->second << endl;
            }
        }
    }
}