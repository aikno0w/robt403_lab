#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit_msgs/DisplayTrajectory.h>
#include <ros/ros.h>
#include <cmath>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "snake_robot_rectangular_path");
    ros::NodeHandle node_handle;
    ros::AsyncSpinner spinner(0);
    spinner.start();

    static const std::string PLANNING_GROUP = "move_aina";
    moveit::planning_interface::MoveGroupInterface move_group(PLANNING_GROUP);

    const std::vector<std::string>& joint_names = move_group.getJointNames();
    moveit::core::RobotStatePtr current_state = move_group.getCurrentState();
    std::vector<double> joint_group_positions;
    current_state->copyJointGroupPositions(move_group.getCurrentState()->getJointModelGroup(PLANNING_GROUP), joint_group_positions);

    // Rectangle path parameters
    const double x_movement = 0.2;  // X-axis movement in meters
    const double y_movement = 0.1;  // Y-axis movement in meters
    const int steps = 50;           // Number of steps per side of the rectangle

    ros::Rate loop_rate(20); // Control frequency

    // Define four corners of the rectangle path
    std::vector<std::pair<double, double>> path_points = {
        {x_movement, 0.0},
        {0.0, y_movement},
        {-x_movement, 0.0},
        {0.0, -y_movement}
    };

    for (const auto& point : path_points) {
        double dx = point.first / steps;
        double dy = point.second / steps;

        for (int i = 0; i < steps; ++i) {
            geometry_msgs::PoseStamped current_pose = move_group.getCurrentPose();
            geometry_msgs::Pose target_pose = current_pose.pose;

            // Adjust target pose
            target_pose.position.x += dx;
            target_pose.position.y += dy;

            // Wave-like motion in joints
            for (size_t j = 0; j < joint_group_positions.size(); ++j) {
                joint_group_positions[j] = 0.2 * sin(ros::Time::now().toSec() + j); // Wave pattern
            }

            // Set joint positions and target pose
            move_group.setJointValueTarget(joint_group_positions);
            move_group.setPoseTarget(target_pose);

            // Plan and execute
            moveit::planning_interface::MoveGroupInterface::Plan plan;
            bool success = (move_group.plan(plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);

            if (success) {
                move_group.move();
            } else {
                ROS_WARN("Planning failed for step %d", i);
            }

            loop_rate.sleep();
        }
    }

    ROS_INFO("Completed rectangular path.");
    ros::shutdown();
    return 0;
}
