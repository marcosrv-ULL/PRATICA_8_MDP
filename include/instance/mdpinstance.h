#ifndef MDP_INSTANCE_H_
#define MDP_INSTANCE_H_

#include "../IOController/IOController.h"
#include <iostream>
#include <map>
#include <vector>

class MDPInstance {
private:
  std::vector<std::vector<double>> _elementos;
  
public:
  MDPInstance() = default;
  MDPInstance(std::vector<std::vector<double>> elementos);
  ~MDPInstance() = default;
  std::vector<double> elemento(int indice);
  std::vector<std::vector<double>> elementos();
  
  void showInstance();
};

#endif