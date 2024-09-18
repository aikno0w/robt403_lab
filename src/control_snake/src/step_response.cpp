#include "ros/ros.h"
#include "std_msgs/Float64.h"

double step_response(double time, double step_time, double amplitude) {
    
    return (time >= step_time) ? amplitude : 0.0;
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "step_response_node");
    ros::NodeHandle nh;

    // ros::Publisher joint_pub = nh.advertise<std_msgs::Float64>("/motortom2m/command", 10);
    ros::Publisher joint_pub = nh.advertise<std_msgs::Float64>("/robot/joint1_position_controller/command", 10);
    
    double amplitude = 1.0;  
    double step_time = 2.0;   
    double rate = 50.0;      

    ros::Rate loop_rate(rate);

    ros::Time start_time = ros::Time::now();

    while (ros::ok()) {
        std_msgs::Float64 msg;

        ros::Duration elapsed_time = ros::Time::now() - start_time;
        double time = elapsed_time.toSec();

        msg.data = step_response(time, step_time, amplitude);

        joint_pub.publish(msg);

        ROS_INFO("Published step response to /robot/joint1_position_controller/command: [%f]", msg.data);

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}

