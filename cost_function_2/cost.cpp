#include "cost.h"

#include <cmath>
#include <vector>

using namespace std;

double inefficiency_cost(int target_speed, int intended_lane, int final_lane, 
                         const std::vector<int> &lane_speeds) {
  // Cost becomes higher for trajectories with intended lane and final lane 
  //   that have traffic slower than target_speed.

  /**
   * TODO: Replace cost = 0 with an appropriate cost function.
   */
  double cost = 0;

  cost = 2 * target_speed - lane_speeds[final_lane] - lane_speeds[intended_lane];
  cost = 1 - exp(-1 * cost);

  return cost;
}
