#include "../../include/algoritmo/algoritmo.h"

std::vector<double> Algoritmo::centro(std::vector<std::vector<double>>& elementos) {
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