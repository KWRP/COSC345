# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\willy\Source\Repos\COSC345

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\willy\Source\Repos\COSC345\build

# Include any dependencies generated for this target.
include CMakeFiles/planner.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/planner.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/planner.dir/flags.make

CMakeFiles/planner.dir/Source.cpp.obj: CMakeFiles/planner.dir/flags.make
CMakeFiles/planner.dir/Source.cpp.obj: ../Source.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\willy\Source\Repos\COSC345\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/planner.dir/Source.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\planner.dir\Source.cpp.obj -c C:\Users\willy\Source\Repos\COSC345\Source.cpp

CMakeFiles/planner.dir/Source.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/planner.dir/Source.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\willy\Source\Repos\COSC345\Source.cpp > CMakeFiles\planner.dir\Source.cpp.i

CMakeFiles/planner.dir/Source.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/planner.dir/Source.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\willy\Source\Repos\COSC345\Source.cpp -o CMakeFiles\planner.dir\Source.cpp.s

CMakeFiles/planner.dir/Source.cpp.obj.requires:

.PHONY : CMakeFiles/planner.dir/Source.cpp.obj.requires

CMakeFiles/planner.dir/Source.cpp.obj.provides: CMakeFiles/planner.dir/Source.cpp.obj.requires
	$(MAKE) -f CMakeFiles\planner.dir\build.make CMakeFiles/planner.dir/Source.cpp.obj.provides.build
.PHONY : CMakeFiles/planner.dir/Source.cpp.obj.provides

CMakeFiles/planner.dir/Source.cpp.obj.provides.build: CMakeFiles/planner.dir/Source.cpp.obj


# Object files for target planner
planner_OBJECTS = \
"CMakeFiles/planner.dir/Source.cpp.obj"

# External object files for target planner
planner_EXTERNAL_OBJECTS =

planner.exe: CMakeFiles/planner.dir/Source.cpp.obj
planner.exe: CMakeFiles/planner.dir/build.make
planner.exe: CMakeFiles/planner.dir/linklibs.rsp
planner.exe: CMakeFiles/planner.dir/objects1.rsp
planner.exe: CMakeFiles/planner.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\willy\Source\Repos\COSC345\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable planner.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\planner.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/planner.dir/build: planner.exe

.PHONY : CMakeFiles/planner.dir/build

CMakeFiles/planner.dir/requires: CMakeFiles/planner.dir/Source.cpp.obj.requires

.PHONY : CMakeFiles/planner.dir/requires

CMakeFiles/planner.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\planner.dir\cmake_clean.cmake
.PHONY : CMakeFiles/planner.dir/clean

CMakeFiles/planner.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\willy\Source\Repos\COSC345 C:\Users\willy\Source\Repos\COSC345 C:\Users\willy\Source\Repos\COSC345\build C:\Users\willy\Source\Repos\COSC345\build C:\Users\willy\Source\Repos\COSC345\build\CMakeFiles\planner.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/planner.dir/depend
