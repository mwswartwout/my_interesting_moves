#include <ros/ros.h>
#include <my_interesting_moves/interesting_moves.h>
#include <trajectory_msgs/JointTrajectory.h>
#include <baxter_traj_streamer/baxter_traj_streamer.h>
#include <iostream>
#include <baxter_traj_streamer/trajAction.h>
#include <actionlib/client/simple_action_client.h>

// Baxter right arm joint states
// right_s0
// right_s1
// right_e0
// right_e1
// right_w0
// right_w1
// right_w2

InterestingMoves::InterestingMoves() { }
void InterestingMoves::set_move_wave(trajectory_msgs::JointTrajectory &des_trajectory) {
    std::vector<Eigen::VectorXd> des_path;
    Baxter_traj_streamer baxter_traj_streamer(&nh);
    
    q_pre_pose << 0, 0, 0, 0, 0, 0, 0;
    for (int i = 0; i < 100; i++) {
            ros::spinOnce();
            ros::Duration(0.01).sleep();
    }

    q_vec_right_arm = baxter_traj_streamer.get_qvec_right_arm();
    q_in_vecxd = q_vec_right_arm;
    des_path.push_back(q_in_vecxd);
    q_in_vecxd = q_pre_pose;
    des_path.push_back(q_in_vecxd);

    baxter_traj_streamer.stuff_trajectory(des_path, des_trajectory);
    /*
    baxter_traj_streamer::trajGoal goal;
    goal.trajectory = des_trajectory;

    actionlib::SimpleActionClient<baxter_traj_streamer::trajAction> action_client("trajActionServer", true);
    bool server_exists = action_client.waitForServer(ros::Duration(5.0));

    if (!server_exists) {
        ROS_WARN("Could not connect to server");
        exit(0);
    }

    g_count++;
    goal.traj_id = g_count;
    action_client.sendGoal(goal, &doneCb);
*/
}

void InterestingMoves::set_move_tsk_tsk(trajectory_msgs::JointTrajectory &des_trajectory) {
}

void InterestingMoves::set_move_chop(trajectory_msgs::JointTrajectory &des_trajectory) {
}
