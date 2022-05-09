#ifndef LOCAL_SEARCH_II_H_
#define LOCAL_SEARCH_II_H_

#include "../instance/mdpinstance.h"
#include "../solution/mdpsolution.h"
#include "greedy.h"
#include "localsearchInterfaz.h"
#include <set>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

class LocalSearch_II: public LocalSearchInterfaz {
    public:
        LocalSearch_II() = default;
        MDPSolution solve(MDPSolution& solucion_inicial, MDPInstance&);
};

#endif