#include "../../include/solution/vrpsolution.h"

VRPSolution::VRPSolution(VRPInstance &vrp, int n_vehiculos) {
  _camino.resize(n_vehiculos, std::vector<int>(0));
  vrp1 = vrp;
  for (int i = 0; i < vrp1.rutas(); i++) {
    _camino[i].push_back(0);
  }
  _cost = 0;
}

void VRPSolution::addToPath(int ruta, int nodo) {
  _cost += vrp1.cost(last(ruta), nodo);
  _camino[ruta].push_back(nodo);
}

void VRPSolution::insertAt(int ruta, int posicion, int nodo) {
  _camino[ruta].insert(_camino[ruta].begin() + posicion, nodo);
}

bool VRPSolution::isFull(int ruta) {
  return (getRutaLength(ruta) >= vrp1.getLimitSizeRoute());
}

void VRPSolution::reInsertAt(int ruta, int posicion, int pos_inicial) {
  if (pos_inicial == posicion || pos_inicial + 1 == posicion)
    return;

  int nodo1 = _camino[ruta][pos_inicial];
  int nodo1prev = _camino[ruta][pos_inicial - 1];
  int nodo1pos = _camino[ruta][pos_inicial + 1];
  int nodo2prev = _camino[ruta][posicion - 1];
  int nodo2pos = _camino[ruta][posicion];
  if (posicion < pos_inicial) {
    _camino[ruta].insert(_camino[ruta].begin() + posicion,
                         _camino[ruta][pos_inicial]);
    _camino[ruta].erase(_camino[ruta].begin() + pos_inicial + 1);
  } else if (posicion > pos_inicial) {
    _camino[ruta].insert(_camino[ruta].begin() + posicion,
                         _camino[ruta][pos_inicial]);
    _camino[ruta].erase(_camino[ruta].begin() + pos_inicial);
  }

  _cost = _cost - vrp1.cost(nodo1prev, nodo1) - vrp1.cost(nodo1, nodo1pos) -
          vrp1.cost(nodo2prev, nodo2pos) + vrp1.cost(nodo2prev, nodo1) +
          vrp1.cost(nodo1, nodo2pos) + vrp1.cost(nodo1prev, nodo1pos);
}

void VRPSolution::interReInsertAt(int ruta, int ruta2, int posicion,
                                  int pos_inicial) {
  if (ruta == ruta2 || isFull(ruta2))
    return;
  int nodo1 = _camino[ruta][pos_inicial];
  int nodo1prev = _camino[ruta][pos_inicial - 1];
  int nodo1pos = _camino[ruta][pos_inicial + 1];

  _camino[ruta2].insert(_camino[ruta2].begin() + posicion,
                        _camino[ruta][pos_inicial]);
  _camino[ruta].erase(_camino[ruta].begin() + pos_inicial);
  int nodo2prev = _camino[ruta2][posicion - 1];
  int nodo2pos = _camino[ruta2][posicion + 1];
  std::vector<std::vector<double>> mapa = vrp1.map();
  _cost = _cost - mapa[nodo1prev][nodo1] - mapa[nodo1][nodo1pos] -
          mapa[nodo2prev][nodo2pos] + mapa[nodo2prev][nodo1] +
          mapa[nodo1][nodo2pos] + mapa[nodo1prev][nodo1pos];
}

void VRPSolution::swap(int ruta, int pos1, int pos2) {
  int nodo1, nodo2, nodo1pos, nodo1prev, nodo2pos, nodo2prev;
  if (pos1 == pos2)
    return;
  if (pos1 > pos2) {
    int temp1 = pos1;
    pos1 = pos2;
    pos2 = temp1;
  }
  if (pos1 + 1 == pos2) {
    nodo1 = _camino[ruta][pos1];
    nodo1prev = _camino[ruta][pos1 - 1];
    nodo2 = _camino[ruta][pos2];
    nodo2pos = _camino[ruta][pos2 + 1];
    _cost = _cost - vrp1.cost(nodo1prev, nodo1) - vrp1.cost(nodo1, nodo2) -
            vrp1.cost(nodo2, nodo2pos) + vrp1.cost(nodo1prev, nodo2) +
            vrp1.cost(nodo1, nodo2pos) + vrp1.cost(nodo2, nodo1);
    int temp = _camino[ruta][pos2];
    _camino[ruta][pos2] = _camino[ruta][pos1];
    _camino[ruta][pos1] = temp;

  } else {
    nodo1 = _camino[ruta][pos1];
    nodo1prev = _camino[ruta][pos1 - 1];
    nodo1pos = _camino[ruta][pos1 + 1];
    nodo2 = _camino[ruta][pos2];
    nodo2prev = _camino[ruta][pos2 - 1];
    nodo2pos = _camino[ruta][pos2 + 1];
    int temp = _camino[ruta][pos2];
    _camino[ruta][pos2] = _camino[ruta][pos1];
    _camino[ruta][pos1] = temp;
    _cost = _cost - vrp1.cost(nodo1prev, nodo1) - vrp1.cost(nodo1, nodo1pos) -
            vrp1.cost(nodo2prev, nodo2) - vrp1.cost(nodo2, nodo2pos) +
            vrp1.cost(nodo1prev, nodo2) + vrp1.cost(nodo2prev, nodo1) +
            vrp1.cost(nodo1, nodo2pos) + vrp1.cost(nodo2, nodo1pos);
  }
}

void VRPSolution::interSwap(int ruta1, int ruta2, int pos1, int pos2) {
  if (ruta1 == ruta2)
    return;
  int nodo1 = _camino[ruta1][pos1];
  int nodo1prev = _camino[ruta1][pos1 - 1];
  int nodo1pos = _camino[ruta1][pos1 + 1];
  int nodo2 = _camino[ruta2][pos2];
  int nodo2prev = _camino[ruta2][pos2 - 1];
  int nodo2pos = _camino[ruta2][pos2 + 1];
  int temp = _camino[ruta2][pos2];
  _camino[ruta2][pos2] = _camino[ruta1][pos1];
  _camino[ruta1][pos1] = temp;

  _cost = _cost - vrp1.cost(nodo1prev, nodo1) - vrp1.cost(nodo1, nodo1pos) -
          vrp1.cost(nodo2prev, nodo2) - vrp1.cost(nodo2, nodo2pos) +
          vrp1.cost(nodo1prev, nodo2) + vrp1.cost(nodo2prev, nodo1) +
          vrp1.cost(nodo1, nodo2pos) + vrp1.cost(nodo2, nodo1pos);
}

void VRPSolution::endSolution() {
  for (int i = 0; i < vrp1.rutas(); i++) { // Terminamos el ciclo
    addToPath(i, 0);
  }
}

int VRPSolution::getRutaLength(int ruta) { return _camino[ruta].size(); }

void VRPSolution::addToPath(int ruta, int orden, int nodo) {
  _camino[ruta][orden] = nodo;
}

int VRPSolution::last(int ruta) {
  return _camino[ruta][_camino[ruta].size() - 1];
}

double VRPSolution::cost() {
  // double coste = 0;
  // for (int i = 0; i < vrp1.rutas(); i++) {
  //   for (unsigned int j = 1; j < _camino[i].size(); j++) {
  //     coste += vrp1.cost(_camino[i][j - 1], _camino[i][j]);
  //   }
  // }
  // return coste;
  return _cost;
}

void VRPSolution::setCost(double coste) { _cost = coste; }

std::vector<std::vector<int>> VRPSolution::camino() { return _camino; }

void VRPSolution::showSolution() {
  for (int i = 0; i < vrp1.rutas(); i++) {
    std::cout << "Ruta " << i << ": ";
    for (unsigned int j = 0; j < _camino[i].size(); j++) {
      std::cout << _camino[i][j] << " ";
    }
    std::cout << std::endl;
  }

  std::cout << " Coste: " << cost() << std::endl;
}