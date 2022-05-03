#ifndef MDP_SOLUTION_H_
#define MDP_SOLUTION_H_

#include "../instance/mdpinstance.h"
#include <iostream>
#include <vector>

class VRPSolution {
private:
  std::vector<std::vector<int>> _camino;
  MDPInstance mdp1;
  double _cost;

public:
  VRPSolution() = default;
  VRPSolution(VRPInstance &, int n_vehiculos);
  void addToPath(int ruta, int nodo);
  void addToPath(int ruta, int orden, int nodo);
  void insertAt(int ruta, int posicion, int nodo);
  void reInsertAt(int ruta, int posicion, int pos_inicial);
  void interReInsertAt(int ruta, int ruta2, int posicion, int pos_inicial);
  void swap(int ruta, int pos1, int pos2);
  void interSwap(int ruta1, int ruta2, int pos1, int pos2);
  bool isFull(int ruta);
  int last(int ruta);
  int getRutaLength(int ruta);
  double cost();
  void setCost(double);
  std::vector<std::vector<int>> camino();
  void endSolution();
  void showSolution();
};

#endif