#include "ros/ros.h"
#include "std_msgs/Int32.h"

void callback(const std_msgs::Int32::ConstPtr& msg) {
    ROS_INFO("Received: %d", msg->data);
}

void listener() {
    ros::NodeHandle nh;
    std::string topic_name = "Shilikbay";
    ros::Subscriber sub = nh.subscribe(topic_name, 10, callback);
    ros::spin();
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "id_listener");
    listener();
    return 0;
}
