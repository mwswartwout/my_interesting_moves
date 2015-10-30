// Copyright 2015 Matthew Swartwout

#include <ros/ros.h>
#include <my_interesting_moves/interesting_moves.h>
#include <trajectory_msgs/JointTrajectory.h>
#include <baxter_traj_streamer/baxter_traj_streamer.h>
#include <iostream>
#include <baxter_traj_streamer/trajAction.h>
#include <actionlib/client/simple_action_client.h>
#include <vector>

// Baxter right arm joint states
// right_s0
// right_s1
// right_e0
// right_e1
// right_w0
// right_w1
// right_w2

void InterestingMoves::set_move_ready(trajectory_msgs::JointTrajectory &des_trajectory)
{
    Baxter_traj_streamer baxter_traj_streamer(&nh);
    /// Spin up baxter_traj_streamer
    for (int i = 0; i < 100; i++)
    {
        ros::spinOnce();
        ros::Duration(0.01).sleep();
    }   
    std::vector<Eigen::VectorXd> des_path;
    q_vec_right_arm = baxter_traj_streamer.get_qvec_right_arm();
    q_in_vecxd = q_vec_right_arm;
    des_path.push_back(q_in_vecxd);
    q_pre_pose << -.75, 0, 0, 0, 0, 0, 0;
    q_in_vecxd = q_pre_pose;
    des_path.push_back(q_in_vecxd);
    baxter_traj_streamer.stuff_trajectory(des_path, des_trajectory);
}

void InterestingMoves::set_move_wave(trajectory_msgs::JointTrajectory &des_trajectory)
{
    Baxter_traj_streamer baxter_traj_streamer(&nh);
    /// Spin up baxter_traj_streamer
    for (int i = 0; i < 100; i++)
    {
        ros::spinOnce();
        ros::Duration(0.01).sleep();
    }
    std::vector<Eigen::VectorXd> des_path;
    q_vec_right_arm = baxter_traj_streamer.get_qvec_right_arm();
    q_in_vecxd = q_vec_right_arm;
    des_path.push_back(q_in_vecxd);
    q_pre_pose << -.75, 0, 3, 1.5, 0, 0, 0;
    q_in_vecxd = q_pre_pose;
    des_path.push_back(q_in_vecxd);
    q_pre_pose << -.75, 0, 3, .5, 0, 0, 0;
    q_in_vecxd = q_pre_pose;
    des_path.push_back(q_in_vecxd);
    q_pre_pose << -.75, 0, 3, 2.5, 0, 0, 0;
    q_in_vecxd = q_pre_pose;
    des_path.push_back(q_in_vecxd);
    q_pre_pose << -.75, 0, 3, .5, 0, 0, 0;
    q_in_vecxd = q_pre_pose;
    des_path.push_back(q_in_vecxd);
    q_pre_pose << -.75, 0, 3, 2.5, 0, 0, 0;
    q_in_vecxd = q_pre_pose;
    des_path.push_back(q_in_vecxd);
    baxter_traj_streamer.stuff_trajectory(des_path, des_trajectory);
}

void InterestingMoves::set_move_tsk_tsk(trajectory_msgs::JointTrajectory &des_trajectory)
{
    Baxter_traj_streamer baxter_traj_streamer(&nh);
    /// Spin up baxter_traj_streamer
    for (int i = 0; i < 100; i++)
    {
        ros::spinOnce();
        ros::Duration(0.01).sleep();
    }
    std::vector<Eigen::VectorXd> des_path;
    q_vec_right_arm = baxter_traj_streamer.get_qvec_right_arm();
    q_in_vecxd = q_vec_right_arm;
    des_path.push_back(q_in_vecxd);
    q_pre_pose << -.75, 0, 1.5, 1.5, 1.5, 1.5, 0;
    q_in_vecxd = q_pre_pose;
    des_path.push_back(q_in_vecxd);
    q_pre_pose << -.75, 0, 1.5, 1.5, 2.5, 1.5, 0;
    q_in_vecxd = q_pre_pose;
    des_path.push_back(q_in_vecxd);
    q_pre_pose << -.75, 0, 1.5, 1.5, .5, 1.5, 0;
    q_in_vecxd = q_pre_pose;
    des_path.push_back(q_in_vecxd);
    q_pre_pose << -.75, 0, 1.5, 1.5, 2.5, 1.5, 0;
    q_in_vecxd = q_pre_pose;
    des_path.push_back(q_in_vecxd);
    q_pre_pose << -.75, 0, 1.5, 1.5, .5, 1.5, 0;
    q_in_vecxd = q_pre_pose;
    des_path.push_back(q_in_vecxd);
    baxter_traj_streamer.stuff_trajectory(des_path, des_trajectory);
}

void InterestingMoves::set_move_chop(trajectory_msgs::JointTrajectory &des_trajectory)
{
    Baxter_traj_streamer baxter_traj_streamer(&nh);
    /// Spin up baxter_traj_streamer
    for (int i = 0; i < 100; i++)
    {
        ros::spinOnce();
        ros::Duration(0.01).sleep();
    }
    std::vector<Eigen::VectorXd> des_path;
    q_vec_right_arm = baxter_traj_streamer.get_qvec_right_arm();
    q_in_vecxd = q_vec_right_arm;
    des_path.push_back(q_in_vecxd);
    q_pre_pose << -.75, 0, 3, 1.5, 0, 0, 0;
    q_in_vecxd = q_pre_pose;
    des_path.push_back(q_in_vecxd);
    q_pre_pose << -.75, 0, 1, 1.5, 0, 0, 0;
    q_in_vecxd = q_pre_pose;
    des_path.push_back(q_in_vecxd);
    q_pre_pose << -.75, 0, 3, 1.5, 0, 0, 0;
    q_in_vecxd = q_pre_pose;
    des_path.push_back(q_in_vecxd);
    baxter_traj_streamer.stuff_trajectory(des_path, des_trajectory);
}
