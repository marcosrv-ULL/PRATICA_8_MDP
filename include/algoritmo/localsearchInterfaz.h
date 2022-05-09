#ifndef LocalSearchInterfaz_H_
#define LocalSearchInterfaz_H_

#include "../instance/mdpinstance.h"
#include "../solution/mdpsolution.h"
#include "greedy.h"
#include "algoritmo.h"
#include <set>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

class LocalSearchInterfaz {
    public:
        LocalSearchInterfaz() = default;
        virtual MDPSolution solve(MDPSolution&, MDPInstance&) = 0;
};

#endif