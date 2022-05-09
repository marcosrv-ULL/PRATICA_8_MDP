#include "../../include/algoritmo/localsearch_II.h"
#include <utility>

MDPSolution LocalSearch_II::solve(MDPSolution& solucion_inicial, MDPInstance& instancia) {
  MDPSolution solution = solucion_inicial;
  MDPSolution bestSolution = solution;
  bool mejora = true;
  std::pair<int, double> minimo_di_elemento;
  do {
    mejora = false;
    for (auto elemento_presente: solution.conjunto()) {
        for (auto elemento_no_presente: solution.conjunto_sin_seleccionar()) {
            MDPSolution current = solution;
            current.exchange(elemento_presente, elemento_no_presente);
            if (bestSolution.distance() < current.distance()) {
                mejora = true;
                bestSolution = current;
            }
        }
    }
    solution = bestSolution;
  } while (mejora);
  if (!mejora) solution.addToSet(minimo_di_elemento.first);
  return solution;
}