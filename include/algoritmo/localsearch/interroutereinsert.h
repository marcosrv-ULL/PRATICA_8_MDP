#ifndef INTERREINSERT_H_
#define INTERREINSERT_H_

#include "../../instance/vrpinstance.h"
#include "../../solution/vrpsolution.h"
#include "localsearch.h"

class InterRouteReInsert : public LocalSearch {
public:
  InterRouteReInsert(){};
  VRPSolution search(VRPSolution &, VRPInstance &);
  VRPSolution reinsert(VRPSolution, VRPInstance &);
  VRPSolution randomSearch(VRPSolution &, VRPInstance &);
};

#endif
