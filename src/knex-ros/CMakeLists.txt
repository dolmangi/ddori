cmake_minimum_required(VERSION 2.8.3)
project(knex_ros)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  rospy
  std_msgs
  tf
  robot_state_publisher
  differential_drive
  rosserial_arduino
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES knex_ros
#  CATKIN_DEPENDS rospy std_msgs tf   robot_state_publisher
#  DEPENDS system_lib
)

###########
## Build ##
###########

include_directories(
  ${catkin_INCLUDE_DIRS}
)
