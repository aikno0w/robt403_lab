#include <ros/ros.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>
#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "move_group_interface_rectangle");
    ros::NodeHandle node_handle;
    ros::AsyncSpinner spinner(0);
    spinner.start();
    static const std::string PLANNING_GROUP = "move_aina";
    moveit::planning_interface::MoveGroupInterface move_group(PLANNING_GROUP);

    // Increase planning time to improve chances of finding a solution
    move_group.setPlanningTime(15.0);

    // Retrieve and save the initial position
    geometry_msgs::PoseStamped initial_pose = move_group.getCurrentPose();
    geometry_msgs::Pose target_pose1 = initial_pose.pose;

    // Define the target poses for the rectangle corners relative to the initial pose
    target_pose1.position.x -= 0.7; // Move left

    geometry_msgs::Pose target_pose2 = target_pose1;
    target_pose2.position.y -= 0.7; // Move down

    geometry_msgs::Pose target_pose3 = target_pose2;
    target_pose3.position.x += 0.7; // Move right

    geometry_msgs::Pose target_pose4 = target_pose3;
    target_pose4.position.y += 0.7; // Move up (back to initial y-position)

    std::vector<geometry_msgs::Pose> target_poses = {target_pose1, target_pose2, target_pose3, target_pose4};

    for (const auto& target_pose : target_poses)
    {
        move_group.setApproximateJointValueTarget(target_pose);

        moveit::planning_interface::MoveGroupInterface::Plan plan;
        bool success = (move_group.plan(plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);

        if (success)
        {
            ROS_INFO("Moving to next target...");
            move_group.move();
        }
        else
        {
            ROS_WARN("Planning to the target pose failed. Trying next target...");
        }

        ros::Duration(1.0).sleep();
    }

    // Move back to the initial position
    ROS_INFO("Returning to the initial position...");
    move_group.setApproximateJointValueTarget(initial_pose.pose);
    moveit::planning_interface::MoveGroupInterface::Plan return_plan;
    bool return_success = (move_group.plan(return_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);

    if (return_success)
    {
        move_group.move();
        ROS_INFO("Returned to initial position.");
    }
    else
    {
        ROS_WARN("Could not plan path back to initial position.");
    }

    ROS_INFO("Rectangle drawing completed.");
    ros::shutdown();
    return 0;
}
