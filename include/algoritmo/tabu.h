#ifndef TABU_H_
#define TABU_H_

#include "../instance/mdpinstance.h"
#include "../solution/mdpsolution.h"
#include "algoritmo.h"
#include "localsearchInterfaz.h"
#include <set>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

class Tabu : public Algoritmo {
    private:
     LocalSearchInterfaz* localsearch;
     int max_iter;
    public:
        Tabu(int max_iter, LocalSearchInterfaz* busqueda);
        MDPSolution solve(MDPInstance&);
        MDPSolution construct(MDPInstance&);
};

#endif

