#ifndef MDP_SOLUTION_H_
#define MDP_SOLUTION_H_

#include "../instance/mdpinstance.h"
#include <iostream>
#include <set>
#include <cmath>


class MDPSolution {
private:
  std::set<int> _conjunto;
  MDPInstance _instancia;
  int m;
  double _distancia;
public:
  MDPSolution() = default;
  MDPSolution(MDPInstance&);
  double distance();
  bool addToSet(int indice);
  bool removeFromSet(int indice);
  int getM();
  void showSolution();
};

#endif