#ifndef MDP_SOLUTION_H_
#define MDP_SOLUTION_H_

#include "../instance/mdpinstance.h"
#include <cmath>
#include <iostream>
#include <set>

class MDPSolution {
private:
  std::set<int> _conjunto;
  std::set<int> _conjunto_sin_seleccionar;
  MDPInstance _instancia;
  int m;
  double _distancia;

public:
  MDPSolution() = default;
  MDPSolution(MDPInstance &);
  double distance();
  bool addToSet(int indice);
  bool removeFromSet(int indice);
  bool exchange(int elemento, int elemento_cambio);
  std::pair<int, double> minimum_di_value();
  double calculate_di_value(int elemento);
  std::set<int> conjunto_sin_seleccionar();
  std::set<int> conjunto();
  int getM();
  void showSolution();
  void showConjuntiSinSeleccionar();
};

#endif