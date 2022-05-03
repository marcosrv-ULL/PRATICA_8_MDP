#include "../../include/algoritmo/grasp.h"

GRASP::GRASP(LocalSearch *l, int kmax, int max_iter) {
  local = l;
  _kmax = kmax;
  _max_iter = max_iter;
}

VRPSolution GRASP::solve(VRPInstance vrp1) {
  VRPSolution currentBest = constructRandom(vrp1);
  int iter = 1;
  int MAX_ITER = _max_iter;
  do {
    VRPSolution current = construct(vrp1);
    current = local->search(current, vrp1);
    if (current.cost() < currentBest.cost()) {
      currentBest = current;
    }
  } while (iter++ != MAX_ITER);
  return currentBest;
}

VRPSolution GRASP::construct(VRPInstance &vrp1) {
  VRPSolution currentBest(vrp1, vrp1.clientes());
  std::set<int> toVisit; // cambiar a un set
  for (int i = 0; i < vrp1.clientes(); i++) {
    toVisit.insert(i);
  }
  int total_visited = 1;
  toVisit.erase(0);
  for (int i = 0; i < vrp1.rutas(); i++) {
    int candidato = selectElementForARoute(vrp1, currentBest, toVisit, i);
    currentBest.addToPath(i, candidato);
    toVisit.erase(candidato);
    total_visited++;
  }
  while (total_visited < vrp1.clientes()) {
    std::pair<int, int> candidato = selectElement(vrp1, currentBest, toVisit);
    currentBest.addToPath(candidato.first, candidato.second);
    toVisit.erase(candidato.second);
    total_visited++;
  }
  currentBest.endSolution();
  return currentBest;
}

std::pair<int, int> GRASP::selectElement(VRPInstance &vrp1,
                                         VRPSolution &solution,
                                         std::set<int> toVisit) {
  std::vector<std::pair<std::pair<int, int>, double>> listaCandidatos;
  for (int i = 0; i < vrp1.rutas(); i++) {
    for (auto nodo : toVisit) {
      std::pair<int, int> candidato = std::make_pair(i, nodo);
      double h = heuristica(candidato, vrp1, solution, toVisit);
      insertIfBetter(vrp1, solution, listaCandidatos, candidato, h, _kmax);
    }
  }
  int index = std::rand() % listaCandidatos.size();
  return listaCandidatos[index].first;
}

int GRASP::selectElementForARoute(VRPInstance &vrp1, VRPSolution &solution,
                                  std::set<int> toVisit, int ruta) {
  std::vector<std::pair<std::pair<int, int>, double>> listaCandidatos;
  for (auto nodo : toVisit) {
    std::pair<int, int> candidato = std::make_pair(ruta, nodo);
    double h = heuristica(candidato, vrp1, solution, toVisit);
    insertIfBetter(vrp1, solution, listaCandidatos, candidato, h, _kmax);
  }
  int index = std::rand() % listaCandidatos.size();
  return listaCandidatos[index].first.second;
}

double GRASP::heuristica(std::pair<int, int> candidato, VRPInstance &instance,
                         VRPSolution &solution, std::set<int> toVisit) {
  return instance.cost(solution.last(candidato.first), candidato.second);
}

VRPSolution GRASP::constructRandom(VRPInstance &vrp1) {
  srand(time(NULL));
  VRPSolution currentBest(vrp1, vrp1.clientes());
  int experiment = 1;
  int total_random_tries = 1;
  do {
    std::vector<int> toVisit; // cambiar a un set
    VRPSolution currentSol(vrp1, vrp1.clientes());
    for (int i = 0; i < vrp1.clientes(); i++) {
      toVisit.push_back(i);
    }
    toVisit.erase(toVisit.begin());
    while (toVisit.size() != 0) {
      int ruta = std::rand() % vrp1.rutas();
      int index = std::rand() % toVisit.size();
      currentSol.addToPath(ruta, toVisit[index]);
      toVisit.erase(toVisit.begin() + index);
    }
    currentSol.endSolution();
    if (currentBest.cost() > currentSol.cost() || experiment == 1) {
      currentBest = currentSol;
    }
  } while (experiment++ <= total_random_tries);
  return currentBest;
}

void GRASP::insertIfBetter(
    VRPInstance &vrp1, VRPSolution &solution,
    std::vector<std::pair<std::pair<int, int>, double>> &candidatos,
    std::pair<int, int> candidato, double h, int k) {
  if ((int)candidatos.size() < k &&
      solution.getRutaLength(candidato.first) < vrp1.getLimitSizeRoute()) {
    candidatos.push_back(std::make_pair(candidato, h));
    return;
  }
  for (unsigned int i = 0; i < candidatos.size(); i++) {
    if (solution.getRutaLength(candidato.first) < vrp1.getLimitSizeRoute() &&
        candidatos[i].second > h) {
      candidatos.erase(candidatos.begin() + i);
      candidatos.push_back(std::make_pair(candidato, h));
      break;
    }
  }
}