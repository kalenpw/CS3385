# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /media/kalenpw/HDD/Documents/School/2017Spring/CS3385/p658

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/kalenpw/HDD/Documents/School/2017Spring/CS3385/p658/release

# Include any dependencies generated for this target.
include CMakeFiles/dijkstra.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dijkstra.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dijkstra.dir/flags.make

CMakeFiles/dijkstra.dir/main.cpp.o: CMakeFiles/dijkstra.dir/flags.make
CMakeFiles/dijkstra.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/kalenpw/HDD/Documents/School/2017Spring/CS3385/p658/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dijkstra.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dijkstra.dir/main.cpp.o -c /media/kalenpw/HDD/Documents/School/2017Spring/CS3385/p658/main.cpp

CMakeFiles/dijkstra.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dijkstra.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/kalenpw/HDD/Documents/School/2017Spring/CS3385/p658/main.cpp > CMakeFiles/dijkstra.dir/main.cpp.i

CMakeFiles/dijkstra.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dijkstra.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/kalenpw/HDD/Documents/School/2017Spring/CS3385/p658/main.cpp -o CMakeFiles/dijkstra.dir/main.cpp.s

CMakeFiles/dijkstra.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/dijkstra.dir/main.cpp.o.requires

CMakeFiles/dijkstra.dir/main.cpp.o.provides: CMakeFiles/dijkstra.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/dijkstra.dir/build.make CMakeFiles/dijkstra.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/dijkstra.dir/main.cpp.o.provides

CMakeFiles/dijkstra.dir/main.cpp.o.provides.build: CMakeFiles/dijkstra.dir/main.cpp.o


CMakeFiles/dijkstra.dir/Graph.cpp.o: CMakeFiles/dijkstra.dir/flags.make
CMakeFiles/dijkstra.dir/Graph.cpp.o: ../Graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/kalenpw/HDD/Documents/School/2017Spring/CS3385/p658/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/dijkstra.dir/Graph.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dijkstra.dir/Graph.cpp.o -c /media/kalenpw/HDD/Documents/School/2017Spring/CS3385/p658/Graph.cpp

CMakeFiles/dijkstra.dir/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dijkstra.dir/Graph.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/kalenpw/HDD/Documents/School/2017Spring/CS3385/p658/Graph.cpp > CMakeFiles/dijkstra.dir/Graph.cpp.i

CMakeFiles/dijkstra.dir/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dijkstra.dir/Graph.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/kalenpw/HDD/Documents/School/2017Spring/CS3385/p658/Graph.cpp -o CMakeFiles/dijkstra.dir/Graph.cpp.s

CMakeFiles/dijkstra.dir/Graph.cpp.o.requires:

.PHONY : CMakeFiles/dijkstra.dir/Graph.cpp.o.requires

CMakeFiles/dijkstra.dir/Graph.cpp.o.provides: CMakeFiles/dijkstra.dir/Graph.cpp.o.requires
	$(MAKE) -f CMakeFiles/dijkstra.dir/build.make CMakeFiles/dijkstra.dir/Graph.cpp.o.provides.build
.PHONY : CMakeFiles/dijkstra.dir/Graph.cpp.o.provides

CMakeFiles/dijkstra.dir/Graph.cpp.o.provides.build: CMakeFiles/dijkstra.dir/Graph.cpp.o


CMakeFiles/dijkstra.dir/glfw/deps/glad.c.o: CMakeFiles/dijkstra.dir/flags.make
CMakeFiles/dijkstra.dir/glfw/deps/glad.c.o: ../glfw/deps/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/kalenpw/HDD/Documents/School/2017Spring/CS3385/p658/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/dijkstra.dir/glfw/deps/glad.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dijkstra.dir/glfw/deps/glad.c.o   -c /media/kalenpw/HDD/Documents/School/2017Spring/CS3385/p658/glfw/deps/glad.c

CMakeFiles/dijkstra.dir/glfw/deps/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dijkstra.dir/glfw/deps/glad.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/kalenpw/HDD/Documents/School/2017Spring/CS3385/p658/glfw/deps/glad.c > CMakeFiles/dijkstra.dir/glfw/deps/glad.c.i

CMakeFiles/dijkstra.dir/glfw/deps/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dijkstra.dir/glfw/deps/glad.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/kalenpw/HDD/Documents/School/2017Spring/CS3385/p658/glfw/deps/glad.c -o CMakeFiles/dijkstra.dir/glfw/deps/glad.c.s

CMakeFiles/dijkstra.dir/glfw/deps/glad.c.o.requires:

.PHONY : CMakeFiles/dijkstra.dir/glfw/deps/glad.c.o.requires

CMakeFiles/dijkstra.dir/glfw/deps/glad.c.o.provides: CMakeFiles/dijkstra.dir/glfw/deps/glad.c.o.requires
	$(MAKE) -f CMakeFiles/dijkstra.dir/build.make CMakeFiles/dijkstra.dir/glfw/deps/glad.c.o.provides.build
.PHONY : CMakeFiles/dijkstra.dir/glfw/deps/glad.c.o.provides

CMakeFiles/dijkstra.dir/glfw/deps/glad.c.o.provides.build: CMakeFiles/dijkstra.dir/glfw/deps/glad.c.o


# Object files for target dijkstra
dijkstra_OBJECTS = \
"CMakeFiles/dijkstra.dir/main.cpp.o" \
"CMakeFiles/dijkstra.dir/Graph.cpp.o" \
"CMakeFiles/dijkstra.dir/glfw/deps/glad.c.o"

# External object files for target dijkstra
dijkstra_EXTERNAL_OBJECTS =

dijkstra: CMakeFiles/dijkstra.dir/main.cpp.o
dijkstra: CMakeFiles/dijkstra.dir/Graph.cpp.o
dijkstra: CMakeFiles/dijkstra.dir/glfw/deps/glad.c.o
dijkstra: CMakeFiles/dijkstra.dir/build.make
dijkstra: glfw/src/libglfw3.a
dijkstra: /usr/lib/x86_64-linux-gnu/librt.so
dijkstra: /usr/lib/x86_64-linux-gnu/libm.so
dijkstra: /usr/lib/x86_64-linux-gnu/libX11.so
dijkstra: /usr/lib/x86_64-linux-gnu/libXrandr.so
dijkstra: /usr/lib/x86_64-linux-gnu/libXinerama.so
dijkstra: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
dijkstra: /usr/lib/x86_64-linux-gnu/libXcursor.so
dijkstra: CMakeFiles/dijkstra.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/kalenpw/HDD/Documents/School/2017Spring/CS3385/p658/release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable dijkstra"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dijkstra.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dijkstra.dir/build: dijkstra

.PHONY : CMakeFiles/dijkstra.dir/build

CMakeFiles/dijkstra.dir/requires: CMakeFiles/dijkstra.dir/main.cpp.o.requires
CMakeFiles/dijkstra.dir/requires: CMakeFiles/dijkstra.dir/Graph.cpp.o.requires
CMakeFiles/dijkstra.dir/requires: CMakeFiles/dijkstra.dir/glfw/deps/glad.c.o.requires

.PHONY : CMakeFiles/dijkstra.dir/requires

CMakeFiles/dijkstra.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dijkstra.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dijkstra.dir/clean

CMakeFiles/dijkstra.dir/depend:
	cd /media/kalenpw/HDD/Documents/School/2017Spring/CS3385/p658/release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/kalenpw/HDD/Documents/School/2017Spring/CS3385/p658 /media/kalenpw/HDD/Documents/School/2017Spring/CS3385/p658 /media/kalenpw/HDD/Documents/School/2017Spring/CS3385/p658/release /media/kalenpw/HDD/Documents/School/2017Spring/CS3385/p658/release /media/kalenpw/HDD/Documents/School/2017Spring/CS3385/p658/release/CMakeFiles/dijkstra.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dijkstra.dir/depend

