#ifndef TABU_II_H_
#define TABU_II_H_

#include "../instance/mdpinstance.h"
#include "../solution/mdpsolution.h"
#include "algoritmo.h"
#include "localsearchInterfaz.h"
#include <set>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

class Tabu_II : public Algoritmo {
    private:
     LocalSearchInterfaz* localsearch;
     int max_iter;
    public:
        Tabu_II(int max_iter, LocalSearchInterfaz* busqueda);
        MDPSolution solve(MDPInstance&);
        MDPSolution construct(MDPInstance&);
};

#endif

