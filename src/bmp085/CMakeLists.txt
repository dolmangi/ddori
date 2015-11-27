cmake_minimum_required(VERSION 2.8.3)
project(bmp085)

find_package(catkin REQUIRED COMPONENTS
  message_generation 
  roscpp
  std_msgs
)

 add_message_files(
   FILES
   bmp085_measurement.msg
 )

 add_service_files(
   FILES
   measure.srv
   weather_forcast.srv
 )

 generate_messages(
   DEPENDENCIES
   std_msgs
 )

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES bmp085
  CATKIN_DEPENDS roscpp std_msgs 
  DEPENDS system_lib
)


include_directories(
  ${catkin_INCLUDE_DIRS}
  include
  src/glue
)

add_library(bmp085_bst src/bmp085_bst.c src/glue/linux_glue.c)
add_executable(bmp085_node src/bmp085_node.cpp)
add_dependencies(bmp085_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(bmp085_node bmp085_bst
   ${catkin_LIBRARIES}
 )
