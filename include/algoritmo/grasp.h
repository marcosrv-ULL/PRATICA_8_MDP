#ifndef GRASP_H_
#define GRASP_H_

#include "../instance/mdpinstance.h"
#include "../solution/mdpsolution.h"
#include "algoritmo.h"
#include "localsearch.h"
#include "localsearch_II.h"
#include <set>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

class GRASP : public Algoritmo{
    public:
        GRASP() = default;
        MDPSolution solve(MDPInstance&);
        MDPSolution construct(MDPInstance&);
};

#endif

