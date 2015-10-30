#ifndef INTERESTING_MOVES_H
#define INTERESTING_MOVES_H

#include <ros/ros.h>
#include <trajectory_msgs/JointTrajectory.h>
#include <Eigen/Eigen>

typedef Eigen::Matrix<double, 7, 1> Vectorq7x1;

class InterestingMoves {
public:
    InterestingMoves();
    void set_move_wave(trajectory_msgs::JointTrajectory &des_trajectory);
    void set_move_tsk_tsk(trajectory_msgs::JointTrajectory &des_trajectory);
    void set_move_chop(trajectory_msgs::JointTrajectory &des_trajectory);

private:
    ros::NodeHandle nh;
    Vectorq7x1 q_vec_right_arm;
    Vectorq7x1 q_pre_pose;
    Eigen::VectorXd q_in_vecxd;
    std::vector<Eigen::VectorXd> des_path; 
    int g_count;
};
#endif
