#ifndef LOCAL_SEARCH_H_
#define LOCAL_SEARCH_H_

#include "../instance/mdpinstance.h"
#include "../solution/mdpsolution.h"
#include "greedy.h"
#include "algoritmo.h"
#include <set>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

class LocalSearch: public Algoritmo {
    private:
        MDPSolution solucion_inicial;
    public:
        LocalSearch() = default;
        MDPSolution solve(MDPInstance&);
        void setSolucionInicial(MDPSolution& solucion_inicial);
};

#endif