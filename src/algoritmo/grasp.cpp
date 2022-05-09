#include "../../include/algoritmo/grasp.h"
#include <cstdlib>

GRASP::GRASP(int iters, LocalSearchInterfaz* busqueda) {
  localsearch = busqueda;
  max_iter = iters;
}

MDPSolution GRASP::solve(MDPInstance& instancia) {
  std::srand(time(NULL));
  std::vector<std::vector<double>> elementos_restantes = instancia.elementos();
  MDPSolution bestSolution = construct(instancia);
  int iteracion = 1;
  do {
    MDPSolution solution = construct(instancia);
    solution = localsearch->solve(solution, instancia);
    if (solution.distance() > bestSolution.distance()) {
        bestSolution = solution;
    }
  } while (iteracion++ < max_iter);
  return bestSolution;
}

MDPSolution GRASP::construct(MDPInstance& instancia) {
  
  std::vector<std::vector<double>> elementos_restantes = instancia.elementos();
  MDPSolution solution(instancia);
  int n = elementos_restantes.size();
  std::vector<double> centro1 = centro(elementos_restantes);
  
  const double alpha = 0.5;
  std::vector<std::vector<double>> solucion = {};
  do {
    double distancia_maxima = 0;
    double distancia_minima = MAX_DOUBLE;
    std::vector<int> LRC = {};
    for (auto elemento_no_presente: solution.conjunto_sin_seleccionar()) {
        double distancia = instancia.distance(centro1, instancia.elemento(elemento_no_presente));
        if ( distancia < distancia_minima) {
            distancia_minima = distancia;
        }
        if (distancia > distancia_maxima) {
            distancia_maxima = distancia;
        }
    }
    double criterio = (distancia_minima + (alpha * (distancia_maxima - distancia_minima)));
    for (auto elemento_no_presente: solution.conjunto_sin_seleccionar()) {
        double distancia = instancia.distance(centro1, instancia.elemento(elemento_no_presente));
        if ( distancia >= criterio) {
            LRC.push_back(elemento_no_presente);
        }
    }
    int candidato = LRC[std::rand() % LRC.size()];
    solution.addToSet(candidato);
    solucion.push_back(instancia.elemento(candidato));
    centro1 = centro(solucion);
  } while (solution.getM() < instancia.getMMax());
  return solution;
}