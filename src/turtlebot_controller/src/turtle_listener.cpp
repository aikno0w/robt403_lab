#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Spawn.h"

ros::Publisher pub;

void turtleCallback(const turtlesim::Pose::ConstPtr& msg)
{
    ROS_INFO("Turtle subscriber@[%f, %f, %f]",
             msg->x, msg->y, msg->theta);

    geometry_msgs::Twist my_vel;
    my_vel.linear.x = 1.0;
    my_vel.angular.z = 1.0;

    pub.publish(my_vel);
}

int main (int argc, char **argv)
{
    ros::init(argc, argv, "turtlebot_subscriber");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("turtle1/pose", 1, turtleCallback);
    pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1);
    ros::ServiceClient client1 = nh.serviceClient<turtlesim::Spawn>("/spawn");
    turtlesim::Spawn srv1;
    srv1.request.x = 1.0;
    srv1.request.y = 5.0;
    srv1.request.theta = 0.0;
    srv1.request.name = "Turtle_Aina_Shilikbay";

    client1.call(srv1);
    ros::spin();

    return 0;
}

