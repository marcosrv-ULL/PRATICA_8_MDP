#ifndef TWO_OPT_
#define TWO_OPT_

#include "../../instance/vrpinstance.h"
#include "../../solution/vrpsolution.h"
#include "localsearch.h"


class TwoOpt : public LocalSearch {
    public:
        TwoOpt() = default;
        VRPSolution search(VRPSolution&, VRPInstance&);
        VRPSolution twoopt(VRPSolution, VRPInstance&);
};

#endif
