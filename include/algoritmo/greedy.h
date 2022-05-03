#ifndef GREEDY_H_
#define GREEDY_H_

#include "../instance/mdpinstance.h"
#include "../solution/mdpsolution.h"
#include "algoritmo.h"
#include <set>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

class GreedyConstructivo: public Algoritmo {
    public:
        GreedyConstructivo() = default;
        MDPSolution solve(MDPInstance&);
        std::vector<double> centro(std::vector<std::vector<double>>&);

};

#endif