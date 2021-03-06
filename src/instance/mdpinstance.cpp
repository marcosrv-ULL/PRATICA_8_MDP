#include "../../include/instance/mdpinstance.h"
#include <string>

MDPInstance::MDPInstance(std::vector<std::vector<double>> elementos, int m_max) {
  _elementos = elementos;
  _m_max = m_max;
  k = elementos[0].size();
  n = elementos.size();
}

std::vector<double> MDPInstance::elemento(int indice) {
  return _elementos[indice];
}

void MDPInstance::setName(std::string nombre) {
  name = nombre;
}

void MDPInstance::toFile() {
  std::string instanciastring = "";
  instanciastring += std::to_string(_elementos.size()) + " \n";
  instanciastring += std::to_string(_elementos[0].size()) + " \n";
  for (auto elemento: _elementos) {
    for(auto coordenada: elemento) {
      instanciastring += std::to_string(coordenada) + " ";
    }
    instanciastring +=  " \n";
  }
  std::string name = "max_div_" + std::to_string(n) + "_" + std::to_string(k) + ".txt";
  IOController::toFile(name, instanciastring);
}

double MDPInstance::distance(int i, int j) {
  double distancia = 0;
  int kmax = getK();
  for (int k = 0; k < kmax; k++){
    distancia += std::pow( elemento(i)[k] - elemento(j)[k], 2);
  }
  return std::sqrt(distancia);
}

double MDPInstance::distance(std::vector<double> i, std::vector<double> j) {
  double distancia = 0;
  int kmax = getK();
  for (int k = 0; k < kmax; k++){
    distancia += std::pow( i[k] - j[k], 2);
  }
  return std::sqrt(distancia);
}

std::vector<std::vector<double>> MDPInstance::elementos() {
  return _elementos;
}
int MDPInstance::getMMax() {
  return _m_max;
}

int MDPInstance::getK() {
  return k;
}

int MDPInstance::getN() {
  return n;
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