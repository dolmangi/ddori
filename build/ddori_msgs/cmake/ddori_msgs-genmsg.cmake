# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "ddori_msgs: 12 messages, 0 services")

set(MSG_I_FLAGS "-Iddori_msgs:/home/dolmangi/catkin_ws/src/ddori_msgs/msg;-Iddori_msgs:/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg;-Iactionlib_msgs:/opt/ros/indigo/share/actionlib_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(ddori_msgs_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingActionResult.msg" NAME_WE)
add_custom_target(_ddori_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ddori_msgs" "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingActionResult.msg" "actionlib_msgs/GoalStatus:actionlib_msgs/GoalID:std_msgs/Header:ddori_msgs/AutoDockingResult"
)

get_filename_component(_filename "/home/dolmangi/catkin_ws/src/ddori_msgs/msg/ddori_sensor.msg" NAME_WE)
add_custom_target(_ddori_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ddori_msgs" "/home/dolmangi/catkin_ws/src/ddori_msgs/msg/ddori_sensor.msg" ""
)

get_filename_component(_filename "/home/dolmangi/catkin_ws/src/ddori_msgs/msg/motor_speed.msg" NAME_WE)
add_custom_target(_ddori_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ddori_msgs" "/home/dolmangi/catkin_ws/src/ddori_msgs/msg/motor_speed.msg" ""
)

get_filename_component(_filename "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingGoal.msg" NAME_WE)
add_custom_target(_ddori_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ddori_msgs" "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingGoal.msg" ""
)

get_filename_component(_filename "/home/dolmangi/catkin_ws/src/ddori_msgs/msg/MotorPower.msg" NAME_WE)
add_custom_target(_ddori_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ddori_msgs" "/home/dolmangi/catkin_ws/src/ddori_msgs/msg/MotorPower.msg" ""
)

get_filename_component(_filename "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingAction.msg" NAME_WE)
add_custom_target(_ddori_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ddori_msgs" "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingAction.msg" "ddori_msgs/AutoDockingActionResult:ddori_msgs/AutoDockingFeedback:actionlib_msgs/GoalStatus:actionlib_msgs/GoalID:ddori_msgs/AutoDockingActionFeedback:ddori_msgs/AutoDockingGoal:ddori_msgs/AutoDockingActionGoal:ddori_msgs/AutoDockingResult:std_msgs/Header"
)

get_filename_component(_filename "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingActionGoal.msg" NAME_WE)
add_custom_target(_ddori_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ddori_msgs" "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingActionGoal.msg" "ddori_msgs/AutoDockingGoal:actionlib_msgs/GoalID:std_msgs/Header"
)

get_filename_component(_filename "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingActionFeedback.msg" NAME_WE)
add_custom_target(_ddori_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ddori_msgs" "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingActionFeedback.msg" "actionlib_msgs/GoalStatus:actionlib_msgs/GoalID:std_msgs/Header:ddori_msgs/AutoDockingFeedback"
)

get_filename_component(_filename "/home/dolmangi/catkin_ws/src/ddori_msgs/msg/KeyboardInput.msg" NAME_WE)
add_custom_target(_ddori_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ddori_msgs" "/home/dolmangi/catkin_ws/src/ddori_msgs/msg/KeyboardInput.msg" ""
)

get_filename_component(_filename "/home/dolmangi/catkin_ws/src/ddori_msgs/msg/servo_control.msg" NAME_WE)
add_custom_target(_ddori_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ddori_msgs" "/home/dolmangi/catkin_ws/src/ddori_msgs/msg/servo_control.msg" ""
)

get_filename_component(_filename "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingResult.msg" NAME_WE)
add_custom_target(_ddori_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ddori_msgs" "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingResult.msg" ""
)

get_filename_component(_filename "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingFeedback.msg" NAME_WE)
add_custom_target(_ddori_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "ddori_msgs" "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingFeedback.msg" ""
)

#
#  langs = gencpp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(ddori_msgs
  "/home/dolmangi/catkin_ws/src/ddori_msgs/msg/ddori_sensor.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ddori_msgs
)
_generate_msg_cpp(ddori_msgs
  "/home/dolmangi/catkin_ws/src/ddori_msgs/msg/motor_speed.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ddori_msgs
)
_generate_msg_cpp(ddori_msgs
  "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ddori_msgs
)
_generate_msg_cpp(ddori_msgs
  "/home/dolmangi/catkin_ws/src/ddori_msgs/msg/MotorPower.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ddori_msgs
)
_generate_msg_cpp(ddori_msgs
  "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingAction.msg"
  "${MSG_I_FLAGS}"
  "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingActionResult.msg;/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingFeedback.msg;/opt/ros/indigo/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/indigo/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingActionFeedback.msg;/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingGoal.msg;/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingActionGoal.msg;/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingResult.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ddori_msgs
)
_generate_msg_cpp(ddori_msgs
  "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingGoal.msg;/opt/ros/indigo/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ddori_msgs
)
_generate_msg_cpp(ddori_msgs
  "/home/dolmangi/catkin_ws/src/ddori_msgs/msg/KeyboardInput.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ddori_msgs
)
_generate_msg_cpp(ddori_msgs
  "/home/dolmangi/catkin_ws/src/ddori_msgs/msg/servo_control.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ddori_msgs
)
_generate_msg_cpp(ddori_msgs
  "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ddori_msgs
)
_generate_msg_cpp(ddori_msgs
  "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ddori_msgs
)
_generate_msg_cpp(ddori_msgs
  "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/indigo/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingResult.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ddori_msgs
)
_generate_msg_cpp(ddori_msgs
  "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/indigo/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingFeedback.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ddori_msgs
)

### Generating Services

### Generating Module File
_generate_module_cpp(ddori_msgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ddori_msgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(ddori_msgs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(ddori_msgs_generate_messages ddori_msgs_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingActionResult.msg" NAME_WE)
add_dependencies(ddori_msgs_generate_messages_cpp _ddori_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dolmangi/catkin_ws/src/ddori_msgs/msg/ddori_sensor.msg" NAME_WE)
add_dependencies(ddori_msgs_generate_messages_cpp _ddori_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dolmangi/catkin_ws/src/ddori_msgs/msg/motor_speed.msg" NAME_WE)
add_dependencies(ddori_msgs_generate_messages_cpp _ddori_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingGoal.msg" NAME_WE)
add_dependencies(ddori_msgs_generate_messages_cpp _ddori_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dolmangi/catkin_ws/src/ddori_msgs/msg/MotorPower.msg" NAME_WE)
add_dependencies(ddori_msgs_generate_messages_cpp _ddori_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingAction.msg" NAME_WE)
add_dependencies(ddori_msgs_generate_messages_cpp _ddori_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingActionGoal.msg" NAME_WE)
add_dependencies(ddori_msgs_generate_messages_cpp _ddori_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingActionFeedback.msg" NAME_WE)
add_dependencies(ddori_msgs_generate_messages_cpp _ddori_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dolmangi/catkin_ws/src/ddori_msgs/msg/KeyboardInput.msg" NAME_WE)
add_dependencies(ddori_msgs_generate_messages_cpp _ddori_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dolmangi/catkin_ws/src/ddori_msgs/msg/servo_control.msg" NAME_WE)
add_dependencies(ddori_msgs_generate_messages_cpp _ddori_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingResult.msg" NAME_WE)
add_dependencies(ddori_msgs_generate_messages_cpp _ddori_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingFeedback.msg" NAME_WE)
add_dependencies(ddori_msgs_generate_messages_cpp _ddori_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(ddori_msgs_gencpp)
add_dependencies(ddori_msgs_gencpp ddori_msgs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ddori_msgs_generate_messages_cpp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(ddori_msgs
  "/home/dolmangi/catkin_ws/src/ddori_msgs/msg/ddori_sensor.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ddori_msgs
)
_generate_msg_py(ddori_msgs
  "/home/dolmangi/catkin_ws/src/ddori_msgs/msg/motor_speed.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ddori_msgs
)
_generate_msg_py(ddori_msgs
  "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ddori_msgs
)
_generate_msg_py(ddori_msgs
  "/home/dolmangi/catkin_ws/src/ddori_msgs/msg/MotorPower.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ddori_msgs
)
_generate_msg_py(ddori_msgs
  "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingAction.msg"
  "${MSG_I_FLAGS}"
  "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingActionResult.msg;/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingFeedback.msg;/opt/ros/indigo/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/indigo/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingActionFeedback.msg;/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingGoal.msg;/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingActionGoal.msg;/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingResult.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ddori_msgs
)
_generate_msg_py(ddori_msgs
  "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingGoal.msg;/opt/ros/indigo/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ddori_msgs
)
_generate_msg_py(ddori_msgs
  "/home/dolmangi/catkin_ws/src/ddori_msgs/msg/KeyboardInput.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ddori_msgs
)
_generate_msg_py(ddori_msgs
  "/home/dolmangi/catkin_ws/src/ddori_msgs/msg/servo_control.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ddori_msgs
)
_generate_msg_py(ddori_msgs
  "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ddori_msgs
)
_generate_msg_py(ddori_msgs
  "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ddori_msgs
)
_generate_msg_py(ddori_msgs
  "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/indigo/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingResult.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ddori_msgs
)
_generate_msg_py(ddori_msgs
  "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/indigo/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingFeedback.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ddori_msgs
)

### Generating Services

### Generating Module File
_generate_module_py(ddori_msgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ddori_msgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(ddori_msgs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(ddori_msgs_generate_messages ddori_msgs_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingActionResult.msg" NAME_WE)
add_dependencies(ddori_msgs_generate_messages_py _ddori_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dolmangi/catkin_ws/src/ddori_msgs/msg/ddori_sensor.msg" NAME_WE)
add_dependencies(ddori_msgs_generate_messages_py _ddori_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dolmangi/catkin_ws/src/ddori_msgs/msg/motor_speed.msg" NAME_WE)
add_dependencies(ddori_msgs_generate_messages_py _ddori_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingGoal.msg" NAME_WE)
add_dependencies(ddori_msgs_generate_messages_py _ddori_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dolmangi/catkin_ws/src/ddori_msgs/msg/MotorPower.msg" NAME_WE)
add_dependencies(ddori_msgs_generate_messages_py _ddori_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingAction.msg" NAME_WE)
add_dependencies(ddori_msgs_generate_messages_py _ddori_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingActionGoal.msg" NAME_WE)
add_dependencies(ddori_msgs_generate_messages_py _ddori_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingActionFeedback.msg" NAME_WE)
add_dependencies(ddori_msgs_generate_messages_py _ddori_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dolmangi/catkin_ws/src/ddori_msgs/msg/KeyboardInput.msg" NAME_WE)
add_dependencies(ddori_msgs_generate_messages_py _ddori_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dolmangi/catkin_ws/src/ddori_msgs/msg/servo_control.msg" NAME_WE)
add_dependencies(ddori_msgs_generate_messages_py _ddori_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingResult.msg" NAME_WE)
add_dependencies(ddori_msgs_generate_messages_py _ddori_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dolmangi/catkin_ws/devel/share/ddori_msgs/msg/AutoDockingFeedback.msg" NAME_WE)
add_dependencies(ddori_msgs_generate_messages_py _ddori_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(ddori_msgs_genpy)
add_dependencies(ddori_msgs_genpy ddori_msgs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS ddori_msgs_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ddori_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/ddori_msgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(ddori_msgs_generate_messages_cpp std_msgs_generate_messages_cpp)
add_dependencies(ddori_msgs_generate_messages_cpp actionlib_msgs_generate_messages_cpp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ddori_msgs)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ddori_msgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/ddori_msgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(ddori_msgs_generate_messages_py std_msgs_generate_messages_py)
add_dependencies(ddori_msgs_generate_messages_py actionlib_msgs_generate_messages_py)
