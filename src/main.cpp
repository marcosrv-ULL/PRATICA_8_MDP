#include "../include/algoritmo/greedy.h"
#include "../include/algoritmo/grasp.h"
#include "../include/algoritmo/localsearch.h"
#include "../include/algoritmo/localsearch_II.h"
#include "../include/benchmark/benchmark.h"
#include "../include/instance/instanceparser.h"
#include "../include/factory/mdpfactory.h"

int main1(int argc, char **argv) {
  std::string input_file = argv[1];
  std::string m = argv[2];
  InstanceParser ins1(input_file, std::stoi(m));
  MDPInstance instancia = ins1.parse();
  GreedyConstructivo *greed1 = new GreedyConstructivo();
  GRASP* grasp1 = new GRASP(100, new LocalSearch);
  MDPSolution greedSolution = greed1->solve(instancia);
  MDPSolution greedSolution2 = greed1->solve(instancia);
  std::cout << "Greed Solution: " << std::endl;
  greedSolution.showSolution();
  std::cout << "\nGreed Mejora local: Metodo Ansioso" << std::endl;
  (new LocalSearch)->solve(greedSolution, instancia).showSolution();
  std::cout << "\nGreed Mejora local: Metodo Greedy" << std::endl;
  (new LocalSearch_II)->solve(greedSolution2, instancia).showSolution();
  std::cout << "GRASP Solution: " << std::endl;
  std::string result = Benchmark::run(grasp1, instancia);
  std::cout << result << std::endl;
  return 0;
}

int main(int argc, char **argv) {
  MDPFactory::generate(10000, 3, 0, 15).toFile();
  MDPFactory::generate(10000, 2, 0, 15).toFile();
  MDPFactory::generate(10000, 4, 0, 15).toFile();
  MDPFactory::generate(20000, 3, 0, 15).toFile();
  MDPFactory::generate(20000, 2, 0, 15).toFile();
  MDPFactory::generate(20000, 4, 0, 15).toFile();
  MDPFactory::generate(30000, 3, 0, 15).toFile();
  MDPFactory::generate(30000, 2, 0, 15).toFile();
  MDPFactory::generate(30000, 4, 0, 15).toFile();
  return 0;
}