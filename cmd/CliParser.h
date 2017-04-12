//
// Created by LJT on 17-4-12.
//
#ifndef EZJVM_CMD_H
#define EZJVM_CMD_H



#include <string>
#include <map>
#include <stdint.h>

namespace ez
{
    namespace cmd
    {
    using namespace std;

        class CliParser
        {
        public :
            CliParser();

            virtual ~CliParser();

            int parse(int argc, char **argv);

            void print();

            inline void clear() {
                properties.clear();
            }

            inline const char *getLaseErr() {
                return lastErr;
            }

            inline bool hasKey(const string &key) const {
                return properties.end() != properties.find(key);
            }

            inline string getStr(const string &key, const string &defaultValue = "") const {
                return hasKey(key) ? properties.find(key)->second : defaultValue;
            }

            inline int32_t getInt32(const string &key, const int32_t defaultValue = 0) const {
                return hasKey(key) ?
                       (int32_t) strtol(properties.find(key)->second.c_str(), NULL, 0) : defaultValue;
            }

            inline int64_t getInt64(const string &key, const int64_t defaultValue = 0) const {
                return hasKey(key) ?
                       (int64_t) strtoll(properties.find(key)->second.c_str(), NULL, 0) : defaultValue;
            }

            inline uint32_t getU32(const string &key, const uint32_t defaultValue = 0) const {
                return hasKey(key) ?
                       (uint32_t) strtoul(properties.find(key)->second.c_str(), NULL, 0) : defaultValue;
            }

            inline uint64_t getU64(const string &key, const uint64_t defaultValue = 0) const {
                return hasKey(key) ?
                       (uint64_t) strtoull(properties.find(key)->second.c_str(), NULL, 0) : defaultValue;
            }

            inline double getDouble(const string &key, const double defaultVale = 0) const {
                return hasKey(key) ? strtod(properties.find(key)->second.c_str(), NULL) : defaultVale;
            }

            inline map<string, string>::const_iterator begin() const {
                return properties.begin();
            }

            inline map<string, string>::const_iterator end() const {
                return properties.end();
            }

        private:
            char lastErr[128];
            map<string, string> properties;
        };
    }//end of cli
}//end of ez

#endif //EZJVM_CMD_H