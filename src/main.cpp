#include "../include/algoritmo/greedy.h"
#include "../include/algoritmo/grasp.h"
#include "../include/algoritmo/tabu.h"
#include "../include/algoritmo/localsearch.h"
#include "../include/algoritmo/localsearch_II.h"
#include "../include/benchmark/benchmark.h"
#include "../include/instance/instanceparser.h"
#include "../include/factory/mdpfactory.h"

int main(int argc, char **argv) {
  std::string input_file = argv[1];
  std::string m = argv[2];
  InstanceParser ins1(input_file, std::stoi(m));
  MDPInstance instancia = ins1.parse();
  GreedyConstructivo *greed1 = new GreedyConstructivo();
  GRASP* grasp1 = new GRASP(100, new LocalSearch);
  GRASP* grasp2 = new GRASP(100, new LocalSearch_II);
  Tabu* tabu1 = new Tabu(10, new LocalSearch);
  MDPSolution greedSolution = greed1->solve(instancia);
  MDPSolution greedSolution2 = greed1->solve(instancia);
  std::cout << "Algoritmo " << "\t\t\t" << "m \t" << "Distancia: \t" << std::endl; 
  std::cout << "Greed Solution: \t\t" << m << "\t"<< greedSolution.distance() << "\t" << std::endl;
  std::cout << "Local Search: Metodo Ansioso \t" << m << "\t" << (new LocalSearch)->solve(greedSolution, instancia).distance() << "\t" << std::endl;
  //std::cout << "Local Search: Metodo Greedy \t" << m << "\t" << (new LocalSearch_II)->solve(greedSolution, instancia).distance() << "\t" << std::endl;  
  std::cout << "GRASP: Mejora ansiosa \t\t" << m << "\t" << grasp1->solve(instancia).distance() << "\t" << std::endl;    
  //std::cout << "GRASP: Mejora Greedy \t\t" << m << "\t" << grasp2->solve(instancia).distance() << "\t" << std::endl; 
  std::cout << "Tabu: Version I \t\t" << m << "\t" << tabu1->solve(instancia).distance() << "\t" << std::endl;    
  return 0;
}

int main1(int argc, char **argv) {
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