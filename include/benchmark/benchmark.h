#ifndef BENCHMARK_T
#define BENCHMARK_T

#include "../algoritmo/algoritmo.h"
#include "../instance/vrpinstance.h"
#include "../solution/vrpsolution.h"
#include <chrono>
#include <iostream>
#include <string>

class Benchmark {
public:
  static std::string run(Algoritmo *alg1, VRPInstance &);
};

#endif