#ifndef BENCHMARK_T
#define BENCHMARK_T

#include "../algoritmo/algoritmo.h"
#include "../instance/mdpinstance.h"
#include "../solution/mdpsolution.h"
#include <chrono>
#include <iostream>
#include <string>

class Benchmark {
public:
  static std::pair<std::string, MDPSolution> run(Algoritmo *alg1, MDPInstance&);
};

#endif