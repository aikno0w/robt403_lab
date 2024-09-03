cmake_minimum_required(VERSION 3.0.2)
project(turtlebot_controller)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  std_msgs
  turtlesim
)

catkin_package(
  CATKIN_DEPENDS geometry_msgs roscpp rospy std_msgs turtlesim
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)
## add_executable(turtle_listener src/exercise5_square.cpp)
add_executable(turtle_listener src/exercise5_triangle.cpp)
target_link_libraries(turtle_listener ${catkin_LIBRARIES})


