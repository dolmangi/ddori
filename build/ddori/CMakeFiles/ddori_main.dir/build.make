# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dolmangi/catkin_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dolmangi/catkin_ws/build

# Include any dependencies generated for this target.
include ddori/CMakeFiles/ddori_main.dir/depend.make

# Include the progress variables for this target.
include ddori/CMakeFiles/ddori_main.dir/progress.make

# Include the compile flags for this target's objects.
include ddori/CMakeFiles/ddori_main.dir/flags.make

ddori/CMakeFiles/ddori_main.dir/src/ddori_main.cpp.o: ddori/CMakeFiles/ddori_main.dir/flags.make
ddori/CMakeFiles/ddori_main.dir/src/ddori_main.cpp.o: /home/dolmangi/catkin_ws/src/ddori/src/ddori_main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dolmangi/catkin_ws/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object ddori/CMakeFiles/ddori_main.dir/src/ddori_main.cpp.o"
	cd /home/dolmangi/catkin_ws/build/ddori && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ddori_main.dir/src/ddori_main.cpp.o -c /home/dolmangi/catkin_ws/src/ddori/src/ddori_main.cpp

ddori/CMakeFiles/ddori_main.dir/src/ddori_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ddori_main.dir/src/ddori_main.cpp.i"
	cd /home/dolmangi/catkin_ws/build/ddori && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/dolmangi/catkin_ws/src/ddori/src/ddori_main.cpp > CMakeFiles/ddori_main.dir/src/ddori_main.cpp.i

ddori/CMakeFiles/ddori_main.dir/src/ddori_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ddori_main.dir/src/ddori_main.cpp.s"
	cd /home/dolmangi/catkin_ws/build/ddori && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/dolmangi/catkin_ws/src/ddori/src/ddori_main.cpp -o CMakeFiles/ddori_main.dir/src/ddori_main.cpp.s

ddori/CMakeFiles/ddori_main.dir/src/ddori_main.cpp.o.requires:
.PHONY : ddori/CMakeFiles/ddori_main.dir/src/ddori_main.cpp.o.requires

ddori/CMakeFiles/ddori_main.dir/src/ddori_main.cpp.o.provides: ddori/CMakeFiles/ddori_main.dir/src/ddori_main.cpp.o.requires
	$(MAKE) -f ddori/CMakeFiles/ddori_main.dir/build.make ddori/CMakeFiles/ddori_main.dir/src/ddori_main.cpp.o.provides.build
.PHONY : ddori/CMakeFiles/ddori_main.dir/src/ddori_main.cpp.o.provides

ddori/CMakeFiles/ddori_main.dir/src/ddori_main.cpp.o.provides.build: ddori/CMakeFiles/ddori_main.dir/src/ddori_main.cpp.o

# Object files for target ddori_main
ddori_main_OBJECTS = \
"CMakeFiles/ddori_main.dir/src/ddori_main.cpp.o"

# External object files for target ddori_main
ddori_main_EXTERNAL_OBJECTS =

/home/dolmangi/catkin_ws/devel/lib/ddori/ddori_main: ddori/CMakeFiles/ddori_main.dir/src/ddori_main.cpp.o
/home/dolmangi/catkin_ws/devel/lib/ddori/ddori_main: ddori/CMakeFiles/ddori_main.dir/build.make
/home/dolmangi/catkin_ws/devel/lib/ddori/ddori_main: /opt/ros/indigo/lib/libroscpp.so
/home/dolmangi/catkin_ws/devel/lib/ddori/ddori_main: /usr/lib/arm-linux-gnueabihf/libboost_signals.so
/home/dolmangi/catkin_ws/devel/lib/ddori/ddori_main: /usr/lib/arm-linux-gnueabihf/libboost_filesystem.so
/home/dolmangi/catkin_ws/devel/lib/ddori/ddori_main: /opt/ros/indigo/lib/librosconsole.so
/home/dolmangi/catkin_ws/devel/lib/ddori/ddori_main: /opt/ros/indigo/lib/librosconsole_log4cxx.so
/home/dolmangi/catkin_ws/devel/lib/ddori/ddori_main: /opt/ros/indigo/lib/librosconsole_backend_interface.so
/home/dolmangi/catkin_ws/devel/lib/ddori/ddori_main: /usr/lib/liblog4cxx.so
/home/dolmangi/catkin_ws/devel/lib/ddori/ddori_main: /usr/lib/arm-linux-gnueabihf/libboost_regex.so
/home/dolmangi/catkin_ws/devel/lib/ddori/ddori_main: /opt/ros/indigo/lib/libxmlrpcpp.so
/home/dolmangi/catkin_ws/devel/lib/ddori/ddori_main: /opt/ros/indigo/lib/libroscpp_serialization.so
/home/dolmangi/catkin_ws/devel/lib/ddori/ddori_main: /opt/ros/indigo/lib/librostime.so
/home/dolmangi/catkin_ws/devel/lib/ddori/ddori_main: /usr/lib/arm-linux-gnueabihf/libboost_date_time.so
/home/dolmangi/catkin_ws/devel/lib/ddori/ddori_main: /opt/ros/indigo/lib/libcpp_common.so
/home/dolmangi/catkin_ws/devel/lib/ddori/ddori_main: /usr/lib/arm-linux-gnueabihf/libboost_system.so
/home/dolmangi/catkin_ws/devel/lib/ddori/ddori_main: /usr/lib/arm-linux-gnueabihf/libboost_thread.so
/home/dolmangi/catkin_ws/devel/lib/ddori/ddori_main: /usr/lib/arm-linux-gnueabihf/libconsole_bridge.so
/home/dolmangi/catkin_ws/devel/lib/ddori/ddori_main: /opt/ros/indigo/lib/libecl_threads.so
/home/dolmangi/catkin_ws/devel/lib/ddori/ddori_main: /usr/lib/arm-linux-gnueabihf/libpthread.so
/home/dolmangi/catkin_ws/devel/lib/ddori/ddori_main: /opt/ros/indigo/lib/libecl_type_traits.so
/home/dolmangi/catkin_ws/devel/lib/ddori/ddori_main: /opt/ros/indigo/lib/libecl_time.so
/home/dolmangi/catkin_ws/devel/lib/ddori/ddori_main: /opt/ros/indigo/lib/libecl_exceptions.so
/home/dolmangi/catkin_ws/devel/lib/ddori/ddori_main: /opt/ros/indigo/lib/libecl_errors.so
/home/dolmangi/catkin_ws/devel/lib/ddori/ddori_main: /opt/ros/indigo/lib/libecl_time_lite.so
/home/dolmangi/catkin_ws/devel/lib/ddori/ddori_main: /usr/lib/arm-linux-gnueabihf/librt.so
/home/dolmangi/catkin_ws/devel/lib/ddori/ddori_main: ddori/CMakeFiles/ddori_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable /home/dolmangi/catkin_ws/devel/lib/ddori/ddori_main"
	cd /home/dolmangi/catkin_ws/build/ddori && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ddori_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ddori/CMakeFiles/ddori_main.dir/build: /home/dolmangi/catkin_ws/devel/lib/ddori/ddori_main
.PHONY : ddori/CMakeFiles/ddori_main.dir/build

ddori/CMakeFiles/ddori_main.dir/requires: ddori/CMakeFiles/ddori_main.dir/src/ddori_main.cpp.o.requires
.PHONY : ddori/CMakeFiles/ddori_main.dir/requires

ddori/CMakeFiles/ddori_main.dir/clean:
	cd /home/dolmangi/catkin_ws/build/ddori && $(CMAKE_COMMAND) -P CMakeFiles/ddori_main.dir/cmake_clean.cmake
.PHONY : ddori/CMakeFiles/ddori_main.dir/clean

ddori/CMakeFiles/ddori_main.dir/depend:
	cd /home/dolmangi/catkin_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dolmangi/catkin_ws/src /home/dolmangi/catkin_ws/src/ddori /home/dolmangi/catkin_ws/build /home/dolmangi/catkin_ws/build/ddori /home/dolmangi/catkin_ws/build/ddori/CMakeFiles/ddori_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ddori/CMakeFiles/ddori_main.dir/depend

