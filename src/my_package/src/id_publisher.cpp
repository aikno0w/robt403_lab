#include "ros/ros.h"
#include "std_msgs/Int32.h"

class IDPublisher {
public:
    IDPublisher(int rate) : rate_(rate) {
        topic_name_ = "Shilikbay";
        pub_ = nh_.advertise<std_msgs::Int32>(topic_name_, 10);
        nu_id_ = {2, 0, 2, 0, 9, 3, 0, 0, 6};
    }

    void publishDigits() {
        ros::Rate loop_rate(rate_);
        while (ros::ok()) {
            for (int digit : nu_id_) {
                ROS_INFO("Publishing: %d", digit);
                std_msgs::Int32 msg;
                msg.data = digit;
                pub_.publish(msg);
                loop_rate.sleep();
            }
        }
    }

private:
    ros::NodeHandle nh_;
    ros::Publisher pub_;
    std::string topic_name_;
    int rate_;
    std::vector<int> nu_id_;
};

int main(int argc, char **argv) {
    ros::init(argc, argv, "id_publisher");
    ros::NodeHandle private_nh("~");
    int rate;
    private_nh.param("rate", rate, 50);  
    IDPublisher id_publisher(rate);
    id_publisher.publishDigits();
    return 0;
}

