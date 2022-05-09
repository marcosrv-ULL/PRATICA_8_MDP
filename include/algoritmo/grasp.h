#ifndef GRASP_H_
#define GRASP_H_

#include "../instance/mdpinstance.h"
#include "../solution/mdpsolution.h"
#include "algoritmo.h"
#include "localsearchInterfaz.h"
#include <set>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

class GRASP : public Algoritmo{
    private:
     LocalSearchInterfaz* localsearch;
     int max_iter;
    public:
        GRASP(int max_iter, LocalSearchInterfaz* busqueda);
        MDPSolution solve(MDPInstance&);
        MDPSolution construct(MDPInstance&);
};

#endif

