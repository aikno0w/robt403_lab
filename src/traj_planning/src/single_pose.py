#!/usr/bin/env python

import rospy
from std_msgs.msg import Float64
import numpy as np

# Lengths of the manipulator links
L1 = 0.675 * 2  # Length of Link 1
L2 = 0.675 * 2  # Length of Link 2
L3 = 0.467      # Length of Link 3

def initialize_publishers():
    rospy.init_node('robot_mover_single_point', anonymous=True)

    # Real robot publishers
    publishers = [
        rospy.Publisher('/robot/joint1_position_controller/command', Float64, queue_size=10),  # Joint 1
        rospy.Publisher('/robot/joint2_position_controller/command', Float64, queue_size=10),  # Joint 2 (set to 0)
        rospy.Publisher('/robot/joint3_position_controller/command', Float64, queue_size=10),  # Joint 3
        rospy.Publisher('/robot/joint4_position_controller/command', Float64, queue_size=10),  # Joint 4 (set to 0)
        rospy.Publisher('/robot/joint5_position_controller/command', Float64, queue_size=10)   # Joint 5
    ]
    
    return publishers

def inverse_kinematics_with_orientation(x, y, phi):
    x_wrist = x - L3 * np.cos(phi)
    y_wrist = y - L3 * np.sin(phi)
    D = (x_wrist**2 + y_wrist**2 - L1**2 - L2**2) / (2 * L1 * L2)

    if abs(D) > 1:
        raise ValueError("Target is outside of the reachable workspace.")

    q2 = np.arctan2(np.sqrt(1 - D**2), D)  
    q1 = np.arctan2(y_wrist, x_wrist) - np.arctan2(L2 * np.sin(q2), L1 + L2 * np.cos(q2))
    q3 = phi - q1 - q2

    return q1, q2, q3

def publish_joint_angles(publishers, angles):
    if len(angles) != 3:
        rospy.logerr("Expected 3 angles for joints 1, 3, and 5 but got %d.", len(angles))
        return

    msg = [Float64() for _ in range(5)]
    
    msg[0].data = angles[0]  # Joint 1
    msg[1].data = 0.0        # Joint 2 (set to 0)
    msg[2].data = angles[1]  # Joint 3
    msg[3].data = 0.0        # Joint 4 (set to 0)
    msg[4].data = angles[2]  # Joint 5

    for i in range(len(publishers)):
        publishers[i].publish(msg[i])
        rospy.loginfo("joint %d: %f", i + 1, msg[i].data)

if __name__ == '__main__':
    publishers = initialize_publishers()

    target_point = (1.5, 2.0, np.pi / 4)  # (x, y, phi)

    x, y, phi = target_point
    try:
        q1, q2, q3 = inverse_kinematics_with_orientation(x, y, phi)
        print(f"q1: {q1}, q2: {q2}, q3: {q3}")
        
        rate = rospy.Rate(10)  # 10 Hz loop
        while not rospy.is_shutdown():
            publish_joint_angles(publishers, (q1, q2, q3))
            rate.sleep()

    except ValueError as e:
        print("Error: Point ({}, {}) is outside of the reachable workspace: {}".format(x, y, e))

    rospy.loginfo("Execution completed.")

