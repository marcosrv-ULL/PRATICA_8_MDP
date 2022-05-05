#include "../include/algoritmo/greedy.h"
#include "../include/algoritmo/localsearch.h"
#include "../include/algoritmo/localsearch_II.h"
#include "../include/benchmark/benchmark.h"
#include "../include/instance/instanceparser.h"

int main1(int argc, char **argv) {
  std::string input_file = argv[1];
  std::string m = argv[2];
  InstanceParser ins1(input_file, std::stoi(m));
  MDPInstance instancia = ins1.parse();
  instancia.showInstance();
  GreedyConstructivo *greed1 = new GreedyConstructivo();
  MDPSolution solucion = greed1->solve(instancia);
  solucion.showSolution();
  solucion.exchange(11, 3);
  solucion.exchange(3, 11);
  solucion.showSolution();
  solucion.showConjuntiSinSeleccionar();
  return 0;
}

int main(int argc, char **argv) {
  std::string input_file = argv[1];
  std::string m = argv[2];
  InstanceParser ins1(input_file, std::stoi(m));
  MDPInstance instancia = ins1.parse();
  instancia.showInstance();
  GreedyConstructivo *greed1 = new GreedyConstructivo();
  LocalSearch *localsearch = new LocalSearch;
  LocalSearch_II* localsearch2 = new LocalSearch_II;
  MDPSolution greedSolution = greed1->solve(instancia);
  MDPSolution greedSolution2 = greed1->solve(instancia);
  std::cout << "Greed Solution: " << std::endl;
  greedSolution.showSolution();
  std::cout << "\nGreed Mejora local I: " << std::endl;
  localsearch->setSolucionInicial(greedSolution);
  std::string result = Benchmark::run(localsearch, instancia);
  std::cout << result << std::endl;
  std::cout << "Greed Mejora local II: " << std::endl;
  localsearch2->setSolucionInicial(greedSolution2);
  result = Benchmark::run(localsearch2, instancia);
  std::cout << result << std::endl;
  return 0;
}