cmake_minimum_required(VERSION 2.8.3)
project(differential_drive)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  rospy
  std_msgs
  tf
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES diffdrive
#  CATKIN_DEPENDS rospy std_msgs tf
#  DEPENDS system_lib
)

###########
## Build ##
###########

include_directories(
  ${catkin_INCLUDE_DIRS}
)
