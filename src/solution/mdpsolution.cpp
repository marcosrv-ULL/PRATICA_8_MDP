#include "../../include/solution/mdpsolution.h"
#include <cmath>

MDPSolution::MDPSolution(MDPInstance &mdp1) {
   _instancia = mdp1;
   m = 0;
   _distancia = 0;
}

double MDPSolution::distance() {
  return _distancia;
}


bool MDPSolution::addToSet(int indice) {
  if (_conjunto.find(indice) == _conjunto.end() && m < _instancia.getMMax()) {
    m++;
    for (auto elemento: _conjunto) {
      _distancia += _instancia.distance(indice, elemento);
    }
    _conjunto.insert(indice);
    
    return true;
  }
  return false;
}

bool MDPSolution::removeFromSet(int indice) {
  if (_conjunto.find(indice) != _conjunto.end()) {
    m--;
    _conjunto.erase(indice);
    for (auto elemento: _conjunto) {
      _distancia -= _instancia.distance(indice, elemento);
    }
    return true;
  }
  return false;
}

int MDPSolution::getM() {
  return m;
}

void MDPSolution::showSolution() {
  std::cout << "m: " << m << std::endl;
  std::cout << "distancia: " << _distancia << std::endl;
  for (auto elemento: _conjunto) {
      std::cout << "[";
      for(auto coordenada: _instancia.elemento(elemento)) {
        std::cout << coordenada << " ";
      }
      std::cout << "]";
  }
  std::cout << std::endl;
}