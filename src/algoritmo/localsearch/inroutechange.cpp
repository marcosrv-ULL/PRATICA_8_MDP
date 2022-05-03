#include "../../../include/algoritmo/localsearch/inroutechange.h"

VRPSolution InRouteChange::search(VRPSolution &solution,
                                  VRPInstance &instance) {
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

VRPSolution InRouteChange::change(VRPSolution solution, VRPInstance &instance) {
  VRPSolution bestSolution = solution;
  for (int ruta = 0; ruta < instance.rutas(); ruta++) {
    int rutaSize = solution.getRutaLength(ruta);
    for (int candidato = 1; candidato < rutaSize - 2; candidato++) {
      for (int cliente = 1; cliente < rutaSize - 2; cliente++) {
        VRPSolution current = solution;
        current.swap(ruta, candidato, cliente);
        if (current.cost() < bestSolution.cost()) {
          bestSolution = current;
        }
      }
    }
  }
  return bestSolution;
}

VRPSolution InRouteChange::randomSearch(VRPSolution &solution,
                                        VRPInstance &instancia) {
  VRPSolution bestSolution = solution;
  int ruta = std::rand() % instancia.rutas();
  int rutaSize = bestSolution.getRutaLength(ruta);
  int candidato1 = 1 + (std::rand() % (rutaSize - 2));

  for (int i = candidato1 - 6; i < candidato1 + 6; i++) {
    if (i > 0 && i != candidato1 && i < rutaSize - 1) {
      VRPSolution current = bestSolution;
      current.swap(ruta, i, candidato1);
      if (current.cost() < bestSolution.cost()) {
        bestSolution = current;
      }
    }
  }

  return bestSolution;
}