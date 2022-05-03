#ifndef INROUTE_CHANGE_
#define INROUTE_CHANGE_

#include "../../instance/vrpinstance.h"
#include "../../solution/vrpsolution.h"
#include "localsearch.h"

class InRouteChange : public LocalSearch {
public:
  InRouteChange() = default;
  VRPSolution search(VRPSolution &, VRPInstance &);
  VRPSolution change(VRPSolution, VRPInstance &);
  VRPSolution randomSearch(VRPSolution &, VRPInstance &);
};

#endif
