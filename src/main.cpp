#include "../include/instance/instanceparser.h"

int main(int argc, char **argv) {
  std::string input_file = argv[1];
  InstanceParser ins1(input_file);
  MDPInstance instancia = ins1.parse();
  instancia.showInstance();
  return 0;
}