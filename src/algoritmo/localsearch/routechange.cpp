#include "../../../include/algoritmo/localsearch/routechange.h"

VRPSolution RouteChange::search(VRPSolution &solution, VRPInstance &instance) {
  int iteracionesSinMejora = 0;
  int iteracionesMaximasSinMejora = 1;
  VRPSolution bestSolution = solution;
  do {
    VRPSolution current = change(bestSolution, instance);
    if (current.cost() < bestSolution.cost()) {
      bestSolution = current;
    }
  } while (iteracionesSinMejora++ <= iteracionesMaximasSinMejora);
  return bestSolution;
}

VRPSolution RouteChange::change(VRPSolution solution, VRPInstance &instance) {
  VRPSolution bestSolution = solution;
  for (int ruta = 0; ruta < instance.rutas(); ruta++) {
    int rutaSize = solution.getRutaLength(ruta);
    for (int ruta2 = 0; ruta2 < instance.rutas(); ruta2++) {
      int rutaSize2 = solution.getRutaLength(ruta2);
      for (int candidato = 1; candidato < rutaSize - 2; candidato++) {
        for (int cliente = 1; cliente < rutaSize2 - 2; cliente++) {
          VRPSolution current = solution;
          current.interSwap(ruta, ruta2, candidato, cliente);
          if (current.cost() < bestSolution.cost()) {
            bestSolution = current;
          }
        }
      }
    }
  }
  return bestSolution;
}

VRPSolution RouteChange::randomSearch(VRPSolution &solution,
                                      VRPInstance &instancia) {
  int ruta1 = std::rand() % instancia.rutas();
  int ruta2 = std::rand() % instancia.rutas();
  while (ruta2 == ruta1)
    ruta2 = std::rand() % instancia.rutas();
  int rutaSize1 = solution.getRutaLength(ruta1);
  int rutaSize2 = solution.getRutaLength(ruta2);
  int candidato1 = 1 + (std::rand() % (rutaSize1 - 2));
  int candidato2 = 1 + (std::rand() % (rutaSize2 - 2));
  while (candidato2 == candidato1)
    candidato2 = 1 + (std::rand() % (rutaSize2 - 2));
  solution.interSwap(ruta1, ruta2, candidato1, candidato2);
  return solution;
}