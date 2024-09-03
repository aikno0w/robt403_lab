cmake_minimum_required(VERSION 3.0.2)
project(my_package)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS roscpp std_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(talker src/id_publisher.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})

add_executable(listener src/id_subscriber.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})

# Uncomment and adjust if you have messages, services, or actions
# add_message_files(FILES ...)
# add_service_files(FILES ...)
# add_action_files(FILES ...)
# generate_messages(DEPENDENCIES ...)

# Uncomment and adjust if you have dynamic reconfigure parameters
# generate_dynamic_reconfigure_options(cfg/...)

# Uncomment and adjust if you have installation requirements
# catkin_install_python(PROGRAMS scripts/my_python_script DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
# install(TARGETS talker listener RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

