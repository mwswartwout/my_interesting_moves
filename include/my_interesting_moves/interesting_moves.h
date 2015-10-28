#ifndef INTERESTING_MOVES_H
#define INTERESTING_MOVES_H

#include <ros/ros.h>
#include <trajectory_msgs/JointTrajectory.h>
class InterestingMoves {
public:
        InterestingMoves();
        void set_move_one(trajectory_msgs::JointTrajectory &des_trajectory);
        void set_move_two(trajectory_msgs::JointTrajectory &des_trajectory);
        void set_move_three(trajectory_msgs::JointTrajectory &des_trajectory);
};
#endif
