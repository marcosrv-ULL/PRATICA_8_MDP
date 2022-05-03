#ifndef GRASP_H_
#define GRASP_H_

#include "algoritmo.h"
#include "localsearch/localsearch.h"


class GRASP : public Algoritmo {
private:
  LocalSearch *local;
  int _kmax;
  int _max_iter;

public:
  GRASP(LocalSearch *, int kmax, int max_iter);
  VRPSolution solve(VRPInstance);
  VRPSolution construct(VRPInstance &);
  VRPSolution constructRandom(VRPInstance &);
  std::pair<int, int> selectElement(VRPInstance &, VRPSolution &,
                                    std::set<int>);
  double heuristica(std::pair<int, int>, VRPInstance &, VRPSolution &,
                    std::set<int>);
  int selectElementForARoute(VRPInstance &vrp1, VRPSolution &solution,
                             std::set<int> toVisit, int ruta);
  void insertIfBetter(VRPInstance &vrp1, VRPSolution &solution,
                      std::vector<std::pair<std::pair<int, int>, double>> &,
                      std::pair<int, int>, double, int k);
};

#endif