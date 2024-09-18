#include "ros/ros.h"
#include "std_msgs/Float64.h"

double prev_value = 0.0;

ros::Publisher* pub_ptr = nullptr;

void callback(const std_msgs::Float64::ConstPtr& msg) {
    double new_value = msg->data;
    if (new_value > prev_value) {
        std_msgs::Float64 msg_to_send;
        msg_to_send.data = new_value;

        // TASK1: 
        //Simulation
        pub_ptr->publish(msg_to_send);
        ROS_INFO("New value: [%f], published to /robot/joint2_position_controller/command", new_value);
        
	//REAL ROBOT
	//ROS_INFO("New value: [%f], published to /joint2/command", new_value);
        
        prev_value = new_value;
    } else {
        ROS_INFO("New value: [%f] is not higher than previous: [%f], not publishing", new_value, prev_value);
    }
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "moving_snake");

    ros::NodeHandle nh;

    //Simulation
    ros::Publisher pub = nh.advertise<std_msgs::Float64>("/robot/joint2_position_controller/command", 100);
    
    //REAL ROBOT
    //ros::Publisher pub = nh.advertise<std_msgs::Float64>("/joint2/command", 100);
    
    pub_ptr = &pub;
    
    ros::Subscriber sub = nh.subscribe<std_msgs::Float64>("/incoming_data", 100, callback);

    ros::spin();

    return 0;
}

