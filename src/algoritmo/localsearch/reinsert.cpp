#include "../../../include/algoritmo/localsearch/reinsert.h"

VRPSolution ReInsert::search(VRPSolution &solution, VRPInstance &instance) {
  int iteracionesSinMejora = 0;
  int iteracionesMaximasSinMejora = 1;
  VRPSolution bestSolution = solution;
  do {
    VRPSolution current = reinsert(bestSolution, instance);
    if (current.cost() < bestSolution.cost()) {
      bestSolution = current;
      iteracionesSinMejora = 0;
    }
  } while (iteracionesSinMejora++ < iteracionesMaximasSinMejora);
  return bestSolution;
}

VRPSolution ReInsert::reinsert(VRPSolution solution, VRPInstance &instance) {
  VRPSolution bestSolution = solution;
  for (int ruta = 0; ruta < instance.rutas(); ruta++) {
    int rutaSize = solution.getRutaLength(ruta);
    for (int candidato = 1; candidato < rutaSize - 2; candidato++) {
      for (int cliente = 1; cliente < rutaSize - 2; cliente++) {
        VRPSolution current = solution;
        current.reInsertAt(ruta, cliente, candidato);
        if (current.cost() < bestSolution.cost()) {
          bestSolution = current;
        }
      }
    }
  }
  return bestSolution;
}

VRPSolution ReInsert::randomSearch(VRPSolution &solution,
                                   VRPInstance &instancia) {
  int ruta = std::rand() % instancia.rutas();
  int rutaSize = solution.getRutaLength(ruta);
  int candidato = 1 + (std::rand() % (rutaSize - 2));
  VRPSolution bestSolution = solution;
  for (int i = 1; i < rutaSize - 2; i++) {
    VRPSolution current = bestSolution;
    current.reInsertAt(ruta, i, candidato);
    if (current.cost() < bestSolution.cost()) {
      bestSolution = current;
    }
  }
  return bestSolution;
}