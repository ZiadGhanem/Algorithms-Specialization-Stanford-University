# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /snap/clion/110/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/110/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ziadyasser/Documents/CLion_Workspace/2-SAT

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ziadyasser/Documents/CLion_Workspace/2-SAT/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/2_SAT.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/2_SAT.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2_SAT.dir/flags.make

CMakeFiles/2_SAT.dir/main.cpp.o: CMakeFiles/2_SAT.dir/flags.make
CMakeFiles/2_SAT.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ziadyasser/Documents/CLion_Workspace/2-SAT/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/2_SAT.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/2_SAT.dir/main.cpp.o -c /home/ziadyasser/Documents/CLion_Workspace/2-SAT/main.cpp

CMakeFiles/2_SAT.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2_SAT.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ziadyasser/Documents/CLion_Workspace/2-SAT/main.cpp > CMakeFiles/2_SAT.dir/main.cpp.i

CMakeFiles/2_SAT.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2_SAT.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ziadyasser/Documents/CLion_Workspace/2-SAT/main.cpp -o CMakeFiles/2_SAT.dir/main.cpp.s

CMakeFiles/2_SAT.dir/Vertex.cpp.o: CMakeFiles/2_SAT.dir/flags.make
CMakeFiles/2_SAT.dir/Vertex.cpp.o: ../Vertex.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ziadyasser/Documents/CLion_Workspace/2-SAT/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/2_SAT.dir/Vertex.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/2_SAT.dir/Vertex.cpp.o -c /home/ziadyasser/Documents/CLion_Workspace/2-SAT/Vertex.cpp

CMakeFiles/2_SAT.dir/Vertex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2_SAT.dir/Vertex.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ziadyasser/Documents/CLion_Workspace/2-SAT/Vertex.cpp > CMakeFiles/2_SAT.dir/Vertex.cpp.i

CMakeFiles/2_SAT.dir/Vertex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2_SAT.dir/Vertex.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ziadyasser/Documents/CLion_Workspace/2-SAT/Vertex.cpp -o CMakeFiles/2_SAT.dir/Vertex.cpp.s

CMakeFiles/2_SAT.dir/Graph.cpp.o: CMakeFiles/2_SAT.dir/flags.make
CMakeFiles/2_SAT.dir/Graph.cpp.o: ../Graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ziadyasser/Documents/CLion_Workspace/2-SAT/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/2_SAT.dir/Graph.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/2_SAT.dir/Graph.cpp.o -c /home/ziadyasser/Documents/CLion_Workspace/2-SAT/Graph.cpp

CMakeFiles/2_SAT.dir/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2_SAT.dir/Graph.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ziadyasser/Documents/CLion_Workspace/2-SAT/Graph.cpp > CMakeFiles/2_SAT.dir/Graph.cpp.i

CMakeFiles/2_SAT.dir/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2_SAT.dir/Graph.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ziadyasser/Documents/CLion_Workspace/2-SAT/Graph.cpp -o CMakeFiles/2_SAT.dir/Graph.cpp.s

# Object files for target 2_SAT
2_SAT_OBJECTS = \
"CMakeFiles/2_SAT.dir/main.cpp.o" \
"CMakeFiles/2_SAT.dir/Vertex.cpp.o" \
"CMakeFiles/2_SAT.dir/Graph.cpp.o"

# External object files for target 2_SAT
2_SAT_EXTERNAL_OBJECTS =

2_SAT: CMakeFiles/2_SAT.dir/main.cpp.o
2_SAT: CMakeFiles/2_SAT.dir/Vertex.cpp.o
2_SAT: CMakeFiles/2_SAT.dir/Graph.cpp.o
2_SAT: CMakeFiles/2_SAT.dir/build.make
2_SAT: CMakeFiles/2_SAT.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ziadyasser/Documents/CLion_Workspace/2-SAT/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable 2_SAT"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/2_SAT.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2_SAT.dir/build: 2_SAT

.PHONY : CMakeFiles/2_SAT.dir/build

CMakeFiles/2_SAT.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/2_SAT.dir/cmake_clean.cmake
.PHONY : CMakeFiles/2_SAT.dir/clean

CMakeFiles/2_SAT.dir/depend:
	cd /home/ziadyasser/Documents/CLion_Workspace/2-SAT/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ziadyasser/Documents/CLion_Workspace/2-SAT /home/ziadyasser/Documents/CLion_Workspace/2-SAT /home/ziadyasser/Documents/CLion_Workspace/2-SAT/cmake-build-debug /home/ziadyasser/Documents/CLion_Workspace/2-SAT/cmake-build-debug /home/ziadyasser/Documents/CLion_Workspace/2-SAT/cmake-build-debug/CMakeFiles/2_SAT.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/2_SAT.dir/depend

