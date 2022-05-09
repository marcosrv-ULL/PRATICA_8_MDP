#include "../../include/algoritmo/greedy.h"

MDPSolution GreedyConstructivo::solve(MDPInstance& instancia) {
  std::vector<std::vector<double>> elementos_restantes = instancia.elementos();
  MDPSolution solution(instancia);
  std::vector<double> centro1 = centro(elementos_restantes);
  std::vector<std::vector<double>> solucion = {};
  do {
    double mas_lejano = 0;
    int mas_lejano_index = 0;
    for (auto elemento_no_presente: solution.conjunto_sin_seleccionar()) {
      double distancia = instancia.distance(centro1, instancia.elemento(elemento_no_presente));
      if ( distancia > mas_lejano) {
        mas_lejano = distancia;
        mas_lejano_index = elemento_no_presente;
      }
    }
    solution.addToSet(mas_lejano_index);
    solucion.push_back(instancia.elemento(mas_lejano_index));
    centro1 = centro(solucion);
  } while (solution.getM() < instancia.getMMax());
  return solution;
}