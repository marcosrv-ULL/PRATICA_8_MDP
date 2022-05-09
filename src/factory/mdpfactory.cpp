#include "../../include/factory/mdpfactory.h"
#include <cstdlib>
#include <string>

MDPInstance MDPFactory::generate(int size,int dimensiones, double cost_limit_lo, double cost_limit_hi) {
    srand(time(NULL));
    std::vector<std::vector<double>> elementos(size, std::vector<double>(dimensiones));
    for (auto& elemento: elementos) {
        for (int i = 0; i < dimensiones; i++) {
            elemento[i] = (cost_limit_lo + ((double)std::rand() / RAND_MAX)) * (cost_limit_hi - cost_limit_lo);
        }
    }
    return MDPInstance(elementos, 2);
}