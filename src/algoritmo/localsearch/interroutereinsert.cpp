#include "../../../include/algoritmo/localsearch/interroutereinsert.h"

VRPSolution InterRouteReInsert::search(VRPSolution &solution,
                                       VRPInstance &instance) {
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

VRPSolution InterRouteReInsert::reinsert(VRPSolution solution,
                                         VRPInstance &instance) {
  VRPSolution bestSolution = solution;
  for (int ruta = 0; ruta < instance.rutas(); ruta++) {
    int rutaSize = solution.getRutaLength(ruta);
    for (int ruta2 = 0; ruta2 < instance.rutas(); ruta2++) {
      int rutaSize2 = solution.getRutaLength(ruta2);
      for (int candidato = 1; candidato < rutaSize - 2; candidato++) {
        for (int cliente = 1; cliente < rutaSize2 - 2; cliente++) {
          VRPSolution current = solution;
          current.interReInsertAt(ruta, ruta2, cliente, candidato);
          if (current.cost() < bestSolution.cost()) {
            bestSolution = current;
          }
        }
      }
    }
  }
  return bestSolution;
}

VRPSolution InterRouteReInsert::randomSearch(VRPSolution &solution,
                                             VRPInstance &instancia) {
  int ruta = std::rand() % instancia.rutas();
  int rutaSize = solution.getRutaLength(ruta);
  int candidato = 1 + (std::rand() % (rutaSize - 2));
  while (candidato == solution.getRutaLength(ruta) - 1)
    candidato = 1 + (std::rand() % (rutaSize - 2));
  int ruta2 = std::rand() % instancia.rutas();
  while (ruta2 == ruta)
    ruta2 = std::rand() % instancia.rutas();
  VRPSolution bestSolution = solution;
  int rutaSize2 = solution.getRutaLength(ruta2);
  for (int i = 1; i < rutaSize2 - 2; i++) {
    VRPSolution current = solution;
    current.interReInsertAt(ruta, ruta2, i, candidato);
    if (current.cost() < bestSolution.cost()) {
      bestSolution = current;
    }
  }
  return bestSolution;
}