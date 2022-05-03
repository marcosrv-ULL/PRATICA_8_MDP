#ifndef MDP_INSTANCE_H_
#define MDP_INSTANCE_H_

#include "../IOController/IOController.h"
#include <iostream>
#include <map>
#include <vector>
#include <cmath>

class MDPInstance {
private:
  std::vector<std::vector<double>> _elementos;
  int _m_max;
  int k;
  int n;
public:
  MDPInstance() = default;
  MDPInstance(std::vector<std::vector<double>> elementos, int m_max);
  ~MDPInstance() = default;
  std::vector<double> elemento(int indice);
  std::vector<std::vector<double>> elementos();
  double distance(int i, int j);
  double distance(std::vector<double> i, std::vector<double> j);
  int getMMax();
  int getK();
  int getN();
  void showInstance();
};

#endif