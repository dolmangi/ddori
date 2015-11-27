cmake_minimum_required(VERSION 2.8.3)
project(imu_offset)

find_package(catkin REQUIRED roscpp sensor_msgs)


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES imu_offset
#  CATKIN_DEPENDS other_catkin_pkg
#  DEPENDS system_lib
)

include_directories(${catkin_INCLUDE_DIRS})
add_executable(imu_yaw_offset src/imu_yaw_offset.cpp)

target_link_libraries(imu_yaw_offset
   ${catkin_LIBRARIES}
)

