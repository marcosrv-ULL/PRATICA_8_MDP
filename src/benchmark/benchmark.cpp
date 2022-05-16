#include "../../include/benchmark/benchmark.h"
#include <chrono>

std::pair<std::string, MDPSolution> Benchmark::run(Algoritmo *alg1, MDPInstance &vrp1) {
  std::string result = "";
  auto start = std::chrono::high_resolution_clock::now();
  MDPSolution s1 = alg1->solve(vrp1);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
  result += std::to_string(duration.count()) + " ms";

  return std::make_pair(result, s1);
}