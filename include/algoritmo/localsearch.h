#ifndef LOCAL_SEARCH_H_
#define LOCAL_SEARCH_H_

#include "../instance/mdpinstance.h"
#include "../solution/mdpsolution.h"
#include "greedy.h"
#include "localsearchInterfaz.h"
#include <set>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

class LocalSearch: public LocalSearchInterfaz {
    public:
        LocalSearch() = default;
        MDPSolution solve(MDPSolution& solucion_inicial, MDPInstance&);
};

#endif