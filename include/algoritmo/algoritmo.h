#ifndef ALGORITMO_H_
#define ALGORITMO_H_

#include "../instance/mdpinstance.h"
#include "../solution/mdpsolution.h"
#include <set>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

const double MAX_DOUBLE = 100000;

class Algoritmo {
    public:
        Algoritmo() = default;
        virtual MDPSolution solve(MDPInstance&) = 0;
        std::vector<double> centro(std::vector<std::vector<double>>&);
};

#endif

