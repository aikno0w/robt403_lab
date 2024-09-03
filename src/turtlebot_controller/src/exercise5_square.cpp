#include "ros/ros.h"
#include "turtlesim/Kill.h"
#include "turtlesim/Spawn.h"
#include "turtlesim/TeleportAbsolute.h"
#include "std_srvs/Empty.h"

void teleportTurtle(ros::ServiceClient &teleportClient, float x, float y, float theta) {
    turtlesim::TeleportAbsolute teleportSrv;
    teleportSrv.request.x = x;
    teleportSrv.request.y = y;
    teleportSrv.request.theta = theta;
    teleportClient.call(teleportSrv);
    ros::Duration(1.0).sleep();  // pause to simulate slow movement
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "turtle_square_mover");
    ros::NodeHandle nh;

    // killing the turtle1
    ros::ServiceClient killClient = nh.serviceClient<turtlesim::Kill>("kill");
    turtlesim::Kill killSrv;
    killSrv.request.name = "turtle1";
    killClient.call(killSrv);

    // spawning a new turtle at the center
    ros::ServiceClient spawnClient = nh.serviceClient<turtlesim::Spawn>("spawn");
    turtlesim::Spawn spawnSrv;
    spawnSrv.request.x = 5.5;
    spawnSrv.request.y = 5.5;
    spawnSrv.request.theta = 0.0;
    spawnSrv.request.name = "turtle_Aina";
    spawnClient.call(spawnSrv);

    // clearing the background
    ros::ServiceClient clearClient = nh.serviceClient<std_srvs::Empty>("clear");
    std_srvs::Empty clearSrv;
    clearClient.call(clearSrv);

    // teleporting the turtle
    ros::ServiceClient teleportClient = nh.serviceClient<turtlesim::TeleportAbsolute>("turtle_Aina/teleport_absolute");

    while (ros::ok()) {
        // moving through the corners of the square
        teleportTurtle(teleportClient, 0.0, 0.0, 0.0);     // Bottom-left corner
        teleportTurtle(teleportClient, 11.0, 0.0, 1.57);   // Bottom-right corner
        teleportTurtle(teleportClient, 11.0, 11.0, 3.14);  // Top-right corner
        teleportTurtle(teleportClient, 0.0, 11.0, -1.57);  // Top-left corner
        teleportTurtle(teleportClient, 0.0, 0.0, 0.0);     // Return to Bottom-left corner
    }

    return 0;
}

