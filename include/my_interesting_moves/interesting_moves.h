// Copyright 2015 Matthew Swartwout

#ifndef MY_INTERESTING_MOVES_INTERESTING_MOVES_H
#define MY_INTERESTING_MOVES_INTERESTING_MOVES_H

#include <ros/ros.h>
#include <trajectory_msgs/JointTrajectory.h>
#include <Eigen/Eigen>
#include <baxter_traj_streamer/baxter_traj_streamer.h>
#include <vector>

typedef Eigen::Matrix<double, 7, 1> Vectorq7x1;

class InterestingMoves
{
public:
    /**
     * Creates a trajectory for Baxter's right arm to fully extended to his side, parallel to the ground
     * @param des_trajectory Reference to the JointTrajectory object where the new trajectory will be populated
     */
    void set_move_ready(trajectory_msgs::JointTrajectory &des_trajectory);

    /**
     * Creates a trajectory for  Baxter's right arm to wave 
     * @param des_trajectory Reference to the JointTrajectory object where the new trajectory will be populated
     */
    void set_move_wave(trajectory_msgs::JointTrajectory &des_trajectory);

    /**
     * Creates a trajectory for Baxter's right arm to tsk tsk with his hand 
     * @param des_trajectory Reference to the JointTrajectory object where the new trajectory will be populated
     */
    void set_move_tsk_tsk(trajectory_msgs::JointTrajectory &des_trajectory);

    /**
     * Creates a trajectory for Baxter's right arm to karate chop 
     * @param des_trajectory Reference to the JointTrajectory object where the new trajectory will be populated
     */
    void set_move_chop(trajectory_msgs::JointTrajectory &des_trajectory);

private:
    ros::NodeHandle nh;
    Vectorq7x1 q_vec_right_arm;
    Vectorq7x1 q_pre_pose;
    Eigen::VectorXd q_in_vecxd;
    std::vector<Eigen::VectorXd> des_path;
    int g_count;
};

#endif  // MY_INTERESTING_MOVES_INTERESTING_MOVES_H
