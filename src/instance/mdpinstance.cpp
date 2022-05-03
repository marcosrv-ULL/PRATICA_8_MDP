#include "../../include/instance/mdpinstance.h"

MDPInstance::MDPInstance(std::vector<std::vector<double>> elementos) {
  _elementos = elementos;
}

std::vector<double> MDPInstance::elemento(int indice) {
  return _elementos[indice];
}

std::vector<std::vector<double>> MDPInstance::elementos() {
  return _elementos;
}

void MDPInstance::showInstance() {
  std::cout << "N: " << _elementos.size() << std::endl;
  std::cout << "K: " << _elementos[0].size() << std::endl;
  std::cout << "Elementos: " << std::endl;
  for (auto elemento: _elementos) {
    std::cout << "[";
    for(auto coordenada: elemento) {
      std::cout << coordenada << "\t";
    }
    std::cout << "]\n";
  } 
}