#ifndef LOCAL_SEARCH_II_H_
#define LOCAL_SEARCH_II_H_

#include "../instance/mdpinstance.h"
#include "../solution/mdpsolution.h"
#include "greedy.h"
#include "algoritmo.h"
#include <set>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

class LocalSearch_II: public Algoritmo {
    private:
        MDPSolution solucion_inicial;
    public:
        LocalSearch_II() = default;
        MDPSolution solve(MDPInstance&);
        void setSolucionInicial(MDPSolution& solucion_inicial);
};

#endif