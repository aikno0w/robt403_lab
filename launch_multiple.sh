#!/bin/bash
# Source the ROS environment
source /opt/ros/noetic/setup.bash  # ROS Noetic as an example, adjust according to your ROS distro
source ~/catkin_ws/devel/setup.bash # Source your workspace

# Run the first script
rosrun traj_planning multiple_via.py &

# Run the second script
rosrun animate multiple_anim.py &

# Wait for all background processes to finish
wait

