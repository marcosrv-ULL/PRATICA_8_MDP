#include "../../include/algoritmo/greedy.h"

MDPSolution GreedyConstructivo::solve(MDPInstance& instancia) {
  std::vector<std::vector<double>> elementos_restantes = instancia.elementos();
  MDPSolution solution(instancia);
  int n = elementos_restantes.size();
  std::vector<double> centro1 = centro(elementos_restantes);

  do {
    double mas_lejano = 0;
    int mas_lejano_index = 0;
    for(int i = 1; i < n; i++) {
      double distancia = instancia.distance(centro1, elementos_restantes[i]);
      if ( distancia > mas_lejano) {
        mas_lejano = distancia;
        mas_lejano_index = i;
      }
    }
    solution.addToSet(mas_lejano_index);
    elementos_restantes.erase(elementos_restantes.begin() + mas_lejano_index);
    n--;
    centro1 = centro(elementos_restantes);
  } while (solution.getM() < instancia.getMMax());
  return solution;
}


std::vector<double> GreedyConstructivo::centro(std::vector<std::vector<double>>& elementos) {
  std::vector<double> centro(elementos[0].size(), 0);
  int n = elementos.size();
  int k = elementos[0].size();
  for(int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      centro[j] += elementos[i][j];
    }
  }
  for (int j = 0; j < k; j++) {
      centro[j] /= elementos.size();
  }
  return centro;
}