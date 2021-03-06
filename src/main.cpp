#include "../include/algoritmo/greedy.h"
#include "../include/algoritmo/grasp.h"
#include "../include/algoritmo/tabu.h"
#include "../include/algoritmo/localsearch.h"
#include "../include/algoritmo/localsearch_II.h"
#include "../include/algoritmo/ramificacion.h"
#include "../include/benchmark/benchmark.h"
#include "../include/instance/instanceparser.h"
#include "../include/factory/mdpfactory.h"

int main(int argc, char **argv) {
  std::vector<std::string> ficheros = {"15_2","15_3","20_2","20_3","30_2","30_3"};
  std::vector<int> m_totales = {2, 4, 5, 6, 7};
  for (unsigned int i = 0; i < ficheros.size(); i++) {
    std::string input_file = "instances/max_div_" + ficheros[i] + ".txt";
    std::cout << input_file << std::endl;
    std::cout << "Algoritmo " << "\t\t\t" << "m \t" << "Distancia: \t" << "Tiempo ms \t" << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;
    for (unsigned int j = 0; j < m_totales.size(); j++) {
      int m = m_totales[j];
      InstanceParser ins1(input_file, m);
      MDPInstance instancia = ins1.parse();
      GreedyConstructivo *greed1 = new GreedyConstructivo();
      GRASP* grasp1 = new GRASP(100, new LocalSearch);
      GRASP* grasp2 = new GRASP(100, new LocalSearch_II);
      Tabu* tabu1 = new Tabu(100, new LocalSearch);
      Ramificanacion* ram1 = new Ramificanacion;
      MDPSolution greedSolution = greed1->solve(instancia);
      MDPSolution greedSolution2 = greed1->solve(instancia);
      std::pair<std::string, MDPSolution> resultadoGreed = Benchmark::run(greed1, instancia);
      std::cout << "Greed: \t\t\t\t" << m << "\t"<< resultadoGreed.second.distance() << "\t\t" << resultadoGreed.first << std::endl;
      std::pair<std::string, MDPSolution> resultadoGRASP1 = Benchmark::run(grasp1, instancia);
      std::cout << "GRASP: Mejora ansiosa \t\t" << m << "\t" << resultadoGRASP1.second.distance() << "\t\t" << resultadoGRASP1.first << std::endl;
      std::pair<std::string, MDPSolution> resultadoGRASP2 = Benchmark::run(grasp2, instancia);    
      std::cout << "GRASP: Mejora Greedy \t\t" << m << "\t" << resultadoGRASP2.second.distance() << "\t\t" << resultadoGRASP2.first << std::endl;
      std::pair<std::string, MDPSolution> resultadoTABU1 = Benchmark::run(tabu1, instancia);
      std::cout << "Tabu: Version I \t\t" << m << "\t" << resultadoTABU1.second.distance() << "\t\t" << resultadoTABU1.first << std::endl;
      std::pair<std::string, MDPSolution> resultadoram1 = Benchmark::run(ram1, instancia);
      std::cout << "Ramificacion \t\t\t" << m << "\t" << resultadoram1.second.distance() << "\t\t" << resultadoram1.first << std::endl;
    }
    std::cout << std::endl;
  }
  
  
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