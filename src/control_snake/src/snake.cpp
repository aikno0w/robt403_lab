#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include <cmath>

double sine_wave(double time, double amplitude, double frequency, double phase_shift) {
    return amplitude * sin(2 * M_PI * frequency * time + phase_shift);
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "snake");
    ros::NodeHandle nh;

    ros::Publisher joint1_pub = nh.advertise<std_msgs::Float64>("/motortom2m/command", 10);
    ros::Publisher joint2_pub = nh.advertise<std_msgs::Float64>("/joint2/command", 10);
    ros::Publisher joint3_pub = nh.advertise<std_msgs::Float64>("/joint4/command", 10);
    ros::Publisher joint4_pub = nh.advertise<std_msgs::Float64>("/joint6/command", 10);
    ros::Publisher joint5_pub = nh.advertise<std_msgs::Float64>("/end/command", 10);

    ros::Duration(2.0).sleep();

    double amplitude = 0.25;
    double frequency = 0.6;
    double phase_shift = M_PI / 4;
    double rate = 50.0;

    ros::Rate loop_rate(rate);
    double time = 0.0;

    std_msgs::Float64 joint1_msg, joint2_msg, joint3_msg, joint4_msg, joint5_msg;

    joint1_msg.data = 0.0;
    joint2_msg.data = 0.0;
    joint3_msg.data = 0.0;
    joint4_msg.data = 0.0;
    joint5_msg.data = 0.0;
    ros::Duration(2.0).sleep();

    while (ros::ok()) {
        joint1_msg.data = sine_wave(time, amplitude, frequency, 0 * phase_shift);
        joint2_msg.data = sine_wave(time, amplitude, frequency, 1 * phase_shift);
        joint3_msg.data = sine_wave(time, amplitude, frequency, 2 * phase_shift);
        joint4_msg.data = sine_wave(time, amplitude, frequency, 3 * phase_shift);
        joint5_msg.data = sine_wave(time, amplitude, frequency, 4 * phase_shift);

        joint1_pub.publish(joint1_msg);
        joint2_pub.publish(joint2_msg);
        joint3_pub.publish(joint3_msg);
        joint4_pub.publish(joint4_msg);
        joint5_pub.publish(joint5_msg);

        ROS_INFO("Joint1: [%f], Joint2: [%f], Joint3: [%f], Joint4: [%f], Joint5: [%f]",
                 joint1_msg.data, joint2_msg.data, joint3_msg.data, joint4_msg.data, joint5_msg.data);

        ros::spinOnce();
        loop_rate.sleep();
        time += 1.0 / rate;
    }

    return 0;
}

