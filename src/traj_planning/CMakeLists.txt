cmake_minimum_required(VERSION 3.0.2)
project(traj_planning)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  rospy
  std_msgs
)

## catkin specific configuration
catkin_package(
  #  INCLUDE_DIRS include
  #  LIBRARIES traj_planning
  CATKIN_DEPENDS rospy std_msgs
  #  DEPENDS system_lib
)

## Specify additional locations of header files
include_directories(
  ${catkin_INCLUDE_DIRS}
)

#############
## Install ##
#############

## Mark executable Python scripts for installation
## In this case, we are installing 'test.py' from the 'src' folder
catkin_install_python(PROGRAMS
  src/execution.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

#############
## Testing ##
#############

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)

