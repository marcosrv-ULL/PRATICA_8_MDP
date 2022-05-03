#include "../include/instance/instanceparser.h"
#include "../include/benchmark/benchmark.h"
#include "../include/algoritmo/greedy.h"

int main(int argc, char **argv) {
  std::string input_file = argv[1];
  InstanceParser ins1(input_file);
  MDPInstance instancia = ins1.parse();
  instancia.showInstance();
  GreedyConstructivo* greed1 = new GreedyConstructivo();
  std::string result = Benchmark::run(greed1, instancia);
  std::cout << result << std::endl;
  return 0;
}