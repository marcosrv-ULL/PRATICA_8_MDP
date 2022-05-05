#include "../../include/solution/mdpsolution.h"
#include <cmath>
#include <utility>

MDPSolution::MDPSolution(MDPInstance &mdp1) {
  _instancia = mdp1;
  for (int i = 0; i < _instancia.getN(); i++) {
    _conjunto_sin_seleccionar.insert(i);
  }
  m = 0;
  _distancia = 0;
}

double MDPSolution::distance() { return _distancia; }

bool MDPSolution::addToSet(int indice) {
  if (_conjunto.find(indice) == _conjunto.end() && m < _instancia.getMMax()) {
    m++;
    for (auto elemento : _conjunto) {
      _distancia += _instancia.distance(indice, elemento);
    }
    _conjunto.insert(indice);
    _conjunto_sin_seleccionar.erase(indice);
    return true;
  }
  return false;
}

bool MDPSolution::removeFromSet(int indice) {
  if (_conjunto.find(indice) != _conjunto.end()) {
    m--;
    _conjunto.erase(indice);
    for (auto elemento1 : _conjunto) {
      _distancia -= _instancia.distance(indice, elemento1);
    }
    _conjunto_sin_seleccionar.insert(indice);
    return true;
  }
  return false;
}

bool MDPSolution::exchange(int elemento, int elemento_cambio) {
  if (_conjunto.find(elemento_cambio) == _conjunto.end() && _conjunto.find(elemento) != _conjunto.end()) {
    _conjunto.erase(elemento);
    _conjunto_sin_seleccionar.insert(elemento);
    for (auto elemento1 : _conjunto) {
      _distancia -= _instancia.distance(elemento, elemento1);
    }
    for (auto elemento1 : _conjunto) {
      _distancia += _instancia.distance(elemento_cambio, elemento1);
    }
    _conjunto.insert(elemento_cambio);
    _conjunto_sin_seleccionar.erase(elemento);
    return true;
  }
  return false;
}

int MDPSolution::getM() {
  return m;
}

std::pair<int, double> MDPSolution::minimum_di_value(){
  double distancia = 1000000;
  int elemento_menor = -1;
  for (auto elemento1 : _conjunto) {
    double distancia_current = 0;
    for (auto elemento2: _conjunto) {
      distancia_current += _instancia.distance(elemento1, elemento2);
    }
    if (distancia_current < distancia) {
      elemento_menor = elemento1;
      distancia = distancia_current;
    }
  }
  return std::make_pair(elemento_menor, distancia);
}

double MDPSolution::calculate_di_value(int elemento) {
  double distancia = 0;
  for (auto elemento1 : _conjunto) {
    distancia += _instancia.distance(elemento1, elemento);
  }
  return distancia;
}


std::set<int> MDPSolution::conjunto_sin_seleccionar() {
  return _conjunto_sin_seleccionar;
}

std::set<int> MDPSolution::conjunto() {
  return _conjunto;
}


void MDPSolution::showSolution() {
  std::cout << "m: " << m << std::endl;
  std::cout << "distancia: " << _distancia << std::endl;
  for (auto elemento : _conjunto) {
    std::cout << "[";
    for (auto coordenada : _instancia.elemento(elemento)) {
      std::cout << coordenada << " ";
    }
    std::cout << "]";
  }
  std::cout << std::endl;
}

void MDPSolution::showConjuntiSinSeleccionar() {
  for (auto elemento : _conjunto_sin_seleccionar) {
    std::cout << "[";
    for (auto coordenada : _instancia.elemento(elemento)) {
      std::cout << coordenada << " ";
    }
    std::cout << "]";
  }
  std::cout << std::endl;
}