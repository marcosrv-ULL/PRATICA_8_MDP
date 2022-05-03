#ifndef LOCAL_SEARCH_H_
#define LOCAL_SEARCH_H_

#include "../../instance/vrpinstance.h"
#include "../../solution/vrpsolution.h"
#include <set>
#include <stdlib.h> /* srand, rand */
#include <time.h>

class LocalSearch {
public:
  LocalSearch() = default;
  ~LocalSearch() = default;
  virtual VRPSolution search(VRPSolution &, VRPInstance &) = 0;
  virtual VRPSolution randomSearch(VRPSolution &, VRPInstance &) = 0;
};

#endif
