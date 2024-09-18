#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include <cmath>

double sine_wave(double time, double amplitude, double frequency) {

    return amplitude * sin(2 * M_PI * frequency * time);
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "sine_wave_node");
    ros::NodeHandle nh;
    //REAL ROBOT
    //ros::Publisher joint_pub = nh.advertise<std_msgs::Float64>("/motortom2m/command", 10);
    //SIMULATOR
    
    ros::Publisher joint_pub = nh.advertise<std_msgs::Float64>("/robot/joint1_position_controller/command", 10);
    double amplitude = 1.0;   
    double frequency = 0.5;   
    double rate = 50.0;       

    ros::Rate loop_rate(rate);
    double time = 0.0;

    while (ros::ok()) {
        std_msgs::Float64 msg;

        msg.data = sine_wave(time, amplitude, frequency);

        joint_pub.publish(msg);

        ROS_INFO("Published sine wave to /robot/joint1_position_controller/command: [%f]", msg.data);

        ros::spinOnce();
        loop_rate.sleep();
        time += 1.0 / rate; 
    }

    return 0;
} 

