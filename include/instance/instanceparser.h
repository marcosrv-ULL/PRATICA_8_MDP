#ifndef INSTANCEPARSER_H_
#define INSTANCEPARSER_H_

#include "mdpinstance.h"
#include <string>

class InstanceParser {
private:
  std::string _string_program;
  int head;
  int m;

public:
  InstanceParser(std::string filename, int m);
  ~InstanceParser() = default;
  char peek();
  char get();
  std::string omitWord();
  bool isBlank();
  void omitBlanks();
  MDPInstance parse();
};

#endif