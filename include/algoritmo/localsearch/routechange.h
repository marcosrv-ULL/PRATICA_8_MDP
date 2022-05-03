#ifndef ROUTE_CHANGE_
#define ROUTE_CHANGE_

#include "../../instance/vrpinstance.h"
#include "../../solution/vrpsolution.h"
#include "localsearch.h"

class RouteChange : public LocalSearch {
public:
  RouteChange() = default;
  VRPSolution search(VRPSolution &, VRPInstance &);
  VRPSolution change(VRPSolution, VRPInstance &);
  VRPSolution randomSearch(VRPSolution &, VRPInstance &);
};

#endif
