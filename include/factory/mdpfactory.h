#ifndef TSPFACTORY_H_
#define TSPFACTORY_H_

#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include "../instance/mdpinstance.h"

class MDPFactory {
    public:
        static MDPInstance generate(int size, int dimensiones, double cost_limit_lo, double cost_limit_hi);
};

#endif