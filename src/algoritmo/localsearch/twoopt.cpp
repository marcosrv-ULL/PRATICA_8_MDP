#include "../../../include/algoritmo/localsearch/twoopt.h"

VRPSolution TwoOpt::search(VRPSolution& solution, VRPInstance& instance) {
    int iteracionesSinMejora = 0;
    int iteracionesMaximasSinMejora = 500;
    VRPSolution bestSolution = solution;
    do {
        VRPSolution current = twoopt(bestSolution, instance);
        if (current.cost() < bestSolution.cost()) {
            bestSolution = current;
        }
    } while (iteracionesSinMejora++ <= iteracionesMaximasSinMejora);
    return bestSolution;
}

VRPSolution TwoOpt::twoopt(VRPSolution solution, VRPInstance& instance) {
    return solution;
}