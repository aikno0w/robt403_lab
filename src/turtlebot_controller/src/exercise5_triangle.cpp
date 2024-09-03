#include "ros/ros.h"
#include "turtlesim/Kill.h"
#include "turtlesim/Spawn.h"
#include "turtlesim/TeleportAbsolute.h"
#include "std_srvs/Empty.h"

// Function to teleport the turtle to a specified position and orientation
void teleportTurtle(ros::ServiceClient &teleportClient, float x, float y, float theta) {
    turtlesim::TeleportAbsolute teleportSrv;
    teleportSrv.request.x = x;
    teleportSrv.request.y = y;
    teleportSrv.request.theta = theta;
    teleportClient.call(teleportSrv);
    ros::Duration(1.0).sleep();  // Pause to simulate slow movement
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "turtle_triangle_mover");
    ros::NodeHandle nh;

    ros::ServiceClient killClient = nh.serviceClient<turtlesim::Kill>("kill");
    turtlesim::Kill killSrv;
    killSrv.request.name = "turtle1";
    killClient.call(killSrv);

    ros::ServiceClient spawnClient = nh.serviceClient<turtlesim::Spawn>("spawn");
    turtlesim::Spawn spawnSrv;
    spawnSrv.request.x = 5.5;
    spawnSrv.request.y = 5.5;
    spawnSrv.request.theta = 0.0;
    spawnSrv.request.name = "turtle_Aina";
    spawnClient.call(spawnSrv);

    ros::ServiceClient clearClient = nh.serviceClient<std_srvs::Empty>("clear");
    std_srvs::Empty clearSrv;
    clearClient.call(clearSrv);

    ros::ServiceClient teleportClient = nh.serviceClient<turtlesim::TeleportAbsolute>("turtle_Aina/teleport_absolute");

    while (ros::ok()) {
        // move to bottom-left corner (0, 0)
        teleportTurtle(teleportClient, 0.0, 0.0, 0.0);

        // move to bottom-right corner (11, 0)
        teleportTurtle(teleportClient, 11.0, 0.0, 1.57);  // facing up

        // move to top-right corner (11, 11)
        teleportTurtle(teleportClient, 11.0, 11.0, 3.14);  // facing left

        // move back to bottom-left corner (0, 0) diagonally
        teleportTurtle(teleportClient, 0.0, 0.0, -1.57);  // facing down
    }

    return 0;
}

