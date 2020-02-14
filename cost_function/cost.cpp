#include "cost.h"
#include <cmath>

double goal_distance_cost(int goal_lane, int intended_lane, int final_lane, 
                          double distance_to_goal) {
  // The cost increases with both the distance of intended lane from the goal
  //   and the distance of the final lane from the goal. The cost of being out 
  //   of the goal lane also becomes larger as the vehicle approaches the goal.
    
  /**
   * TODO: Replace cost = 0 with an appropriate cost function.
   */
  int delta_d = 2.0 * goal_lane - intended_lane - final_lane;
  
  double cost = 1 - exp(-1 * (delta_d)/distance_to_goal);
    
  return cost;
}