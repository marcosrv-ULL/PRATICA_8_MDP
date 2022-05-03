#ifndef INSTANCEPARSER_H_
#define INSTANCEPARSER_H_

#include <string>
#include "mdpinstance.h"

class InstanceParser {
    private:
        std::string _string_program;
        int head;
    public:
        InstanceParser(std::string filename);
        ~InstanceParser() = default;
        char peek();
        char get();
        std::string omitWord();
        bool isBlank();
        void omitBlanks();
        MDPInstance parse();
};

#endif