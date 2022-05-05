#include "../../include/algoritmo/localsearch.h"

MDPSolution LocalSearch::solve(MDPInstance& instancia) {
  MDPSolution solution = solucion_inicial;
  MDPSolution bestSolution = solution;
  bool mejora = true;
  std::pair<int, double> minimo_di_elemento;
  do {
    minimo_di_elemento = solution.minimum_di_value();
    mejora = false;
    solution.removeFromSet(minimo_di_elemento.first);
    for (auto elemento_no_presente: solution.conjunto_sin_seleccionar()) {
        double valor = solution.calculate_di_value(elemento_no_presente);
        if (valor > minimo_di_elemento.second) {
            minimo_di_elemento.first = elemento_no_presente;
            minimo_di_elemento.second = valor;
            mejora = true;
            break;-*
        }
    }
    solution.addToSet(minimo_di_elemento.first);
  } while (mejora);
  if (!mejora) solution.addToSet(minimo_di_elemento.first);
  return solution;
}

void LocalSearch::setSolucionInicial(MDPSolution& solucion) {
    solucion_inicial = solucion;
}