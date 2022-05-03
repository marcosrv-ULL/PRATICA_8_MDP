#ifndef REINSERT_H_
#define REINSERT_H_

#include "../../instance/vrpinstance.h"
#include "../../solution/vrpsolution.h"
#include "localsearch.h"

class ReInsert : public LocalSearch {
public:
  ReInsert(){};
  VRPSolution search(VRPSolution &, VRPInstance &);
  VRPSolution reinsert(VRPSolution, VRPInstance &);
  VRPSolution randomSearch(VRPSolution &, VRPInstance &);
};

#endif
