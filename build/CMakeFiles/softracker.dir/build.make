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
CMAKE_SOURCE_DIR = /home/user/projects/softracker

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/projects/softracker/build

# Include any dependencies generated for this target.
include CMakeFiles/softracker.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/softracker.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/softracker.dir/flags.make

CMakeFiles/softracker.dir/main.c.o: CMakeFiles/softracker.dir/flags.make
CMakeFiles/softracker.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/projects/softracker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/softracker.dir/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/softracker.dir/main.c.o   -c /home/user/projects/softracker/main.c

CMakeFiles/softracker.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/softracker.dir/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/projects/softracker/main.c > CMakeFiles/softracker.dir/main.c.i

CMakeFiles/softracker.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/softracker.dir/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/projects/softracker/main.c -o CMakeFiles/softracker.dir/main.c.s

CMakeFiles/softracker.dir/main.c.o.requires:

.PHONY : CMakeFiles/softracker.dir/main.c.o.requires

CMakeFiles/softracker.dir/main.c.o.provides: CMakeFiles/softracker.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/softracker.dir/build.make CMakeFiles/softracker.dir/main.c.o.provides.build
.PHONY : CMakeFiles/softracker.dir/main.c.o.provides

CMakeFiles/softracker.dir/main.c.o.provides.build: CMakeFiles/softracker.dir/main.c.o


CMakeFiles/softracker.dir/cmdparam.c.o: CMakeFiles/softracker.dir/flags.make
CMakeFiles/softracker.dir/cmdparam.c.o: ../cmdparam.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/projects/softracker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/softracker.dir/cmdparam.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/softracker.dir/cmdparam.c.o   -c /home/user/projects/softracker/cmdparam.c

CMakeFiles/softracker.dir/cmdparam.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/softracker.dir/cmdparam.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/projects/softracker/cmdparam.c > CMakeFiles/softracker.dir/cmdparam.c.i

CMakeFiles/softracker.dir/cmdparam.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/softracker.dir/cmdparam.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/projects/softracker/cmdparam.c -o CMakeFiles/softracker.dir/cmdparam.c.s

CMakeFiles/softracker.dir/cmdparam.c.o.requires:

.PHONY : CMakeFiles/softracker.dir/cmdparam.c.o.requires

CMakeFiles/softracker.dir/cmdparam.c.o.provides: CMakeFiles/softracker.dir/cmdparam.c.o.requires
	$(MAKE) -f CMakeFiles/softracker.dir/build.make CMakeFiles/softracker.dir/cmdparam.c.o.provides.build
.PHONY : CMakeFiles/softracker.dir/cmdparam.c.o.provides

CMakeFiles/softracker.dir/cmdparam.c.o.provides.build: CMakeFiles/softracker.dir/cmdparam.c.o


CMakeFiles/softracker.dir/settings.c.o: CMakeFiles/softracker.dir/flags.make
CMakeFiles/softracker.dir/settings.c.o: ../settings.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/projects/softracker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/softracker.dir/settings.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/softracker.dir/settings.c.o   -c /home/user/projects/softracker/settings.c

CMakeFiles/softracker.dir/settings.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/softracker.dir/settings.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/projects/softracker/settings.c > CMakeFiles/softracker.dir/settings.c.i

CMakeFiles/softracker.dir/settings.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/softracker.dir/settings.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/projects/softracker/settings.c -o CMakeFiles/softracker.dir/settings.c.s

CMakeFiles/softracker.dir/settings.c.o.requires:

.PHONY : CMakeFiles/softracker.dir/settings.c.o.requires

CMakeFiles/softracker.dir/settings.c.o.provides: CMakeFiles/softracker.dir/settings.c.o.requires
	$(MAKE) -f CMakeFiles/softracker.dir/build.make CMakeFiles/softracker.dir/settings.c.o.provides.build
.PHONY : CMakeFiles/softracker.dir/settings.c.o.provides

CMakeFiles/softracker.dir/settings.c.o.provides.build: CMakeFiles/softracker.dir/settings.c.o


CMakeFiles/softracker.dir/sockutils.c.o: CMakeFiles/softracker.dir/flags.make
CMakeFiles/softracker.dir/sockutils.c.o: ../sockutils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/projects/softracker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/softracker.dir/sockutils.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/softracker.dir/sockutils.c.o   -c /home/user/projects/softracker/sockutils.c

CMakeFiles/softracker.dir/sockutils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/softracker.dir/sockutils.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/projects/softracker/sockutils.c > CMakeFiles/softracker.dir/sockutils.c.i

CMakeFiles/softracker.dir/sockutils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/softracker.dir/sockutils.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/projects/softracker/sockutils.c -o CMakeFiles/softracker.dir/sockutils.c.s

CMakeFiles/softracker.dir/sockutils.c.o.requires:

.PHONY : CMakeFiles/softracker.dir/sockutils.c.o.requires

CMakeFiles/softracker.dir/sockutils.c.o.provides: CMakeFiles/softracker.dir/sockutils.c.o.requires
	$(MAKE) -f CMakeFiles/softracker.dir/build.make CMakeFiles/softracker.dir/sockutils.c.o.provides.build
.PHONY : CMakeFiles/softracker.dir/sockutils.c.o.provides

CMakeFiles/softracker.dir/sockutils.c.o.provides.build: CMakeFiles/softracker.dir/sockutils.c.o


CMakeFiles/softracker.dir/proto.c.o: CMakeFiles/softracker.dir/flags.make
CMakeFiles/softracker.dir/proto.c.o: ../proto.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/projects/softracker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/softracker.dir/proto.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/softracker.dir/proto.c.o   -c /home/user/projects/softracker/proto.c

CMakeFiles/softracker.dir/proto.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/softracker.dir/proto.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/projects/softracker/proto.c > CMakeFiles/softracker.dir/proto.c.i

CMakeFiles/softracker.dir/proto.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/softracker.dir/proto.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/projects/softracker/proto.c -o CMakeFiles/softracker.dir/proto.c.s

CMakeFiles/softracker.dir/proto.c.o.requires:

.PHONY : CMakeFiles/softracker.dir/proto.c.o.requires

CMakeFiles/softracker.dir/proto.c.o.provides: CMakeFiles/softracker.dir/proto.c.o.requires
	$(MAKE) -f CMakeFiles/softracker.dir/build.make CMakeFiles/softracker.dir/proto.c.o.provides.build
.PHONY : CMakeFiles/softracker.dir/proto.c.o.provides

CMakeFiles/softracker.dir/proto.c.o.provides.build: CMakeFiles/softracker.dir/proto.c.o


CMakeFiles/softracker.dir/cJSON.c.o: CMakeFiles/softracker.dir/flags.make
CMakeFiles/softracker.dir/cJSON.c.o: ../cJSON.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/projects/softracker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/softracker.dir/cJSON.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/softracker.dir/cJSON.c.o   -c /home/user/projects/softracker/cJSON.c

CMakeFiles/softracker.dir/cJSON.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/softracker.dir/cJSON.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/projects/softracker/cJSON.c > CMakeFiles/softracker.dir/cJSON.c.i

CMakeFiles/softracker.dir/cJSON.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/softracker.dir/cJSON.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/projects/softracker/cJSON.c -o CMakeFiles/softracker.dir/cJSON.c.s

CMakeFiles/softracker.dir/cJSON.c.o.requires:

.PHONY : CMakeFiles/softracker.dir/cJSON.c.o.requires

CMakeFiles/softracker.dir/cJSON.c.o.provides: CMakeFiles/softracker.dir/cJSON.c.o.requires
	$(MAKE) -f CMakeFiles/softracker.dir/build.make CMakeFiles/softracker.dir/cJSON.c.o.provides.build
.PHONY : CMakeFiles/softracker.dir/cJSON.c.o.provides

CMakeFiles/softracker.dir/cJSON.c.o.provides.build: CMakeFiles/softracker.dir/cJSON.c.o


# Object files for target softracker
softracker_OBJECTS = \
"CMakeFiles/softracker.dir/main.c.o" \
"CMakeFiles/softracker.dir/cmdparam.c.o" \
"CMakeFiles/softracker.dir/settings.c.o" \
"CMakeFiles/softracker.dir/sockutils.c.o" \
"CMakeFiles/softracker.dir/proto.c.o" \
"CMakeFiles/softracker.dir/cJSON.c.o"

# External object files for target softracker
softracker_EXTERNAL_OBJECTS =

softracker: CMakeFiles/softracker.dir/main.c.o
softracker: CMakeFiles/softracker.dir/cmdparam.c.o
softracker: CMakeFiles/softracker.dir/settings.c.o
softracker: CMakeFiles/softracker.dir/sockutils.c.o
softracker: CMakeFiles/softracker.dir/proto.c.o
softracker: CMakeFiles/softracker.dir/cJSON.c.o
softracker: CMakeFiles/softracker.dir/build.make
softracker: CMakeFiles/softracker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/projects/softracker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable softracker"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/softracker.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/softracker.dir/build: softracker

.PHONY : CMakeFiles/softracker.dir/build

CMakeFiles/softracker.dir/requires: CMakeFiles/softracker.dir/main.c.o.requires
CMakeFiles/softracker.dir/requires: CMakeFiles/softracker.dir/cmdparam.c.o.requires
CMakeFiles/softracker.dir/requires: CMakeFiles/softracker.dir/settings.c.o.requires
CMakeFiles/softracker.dir/requires: CMakeFiles/softracker.dir/sockutils.c.o.requires
CMakeFiles/softracker.dir/requires: CMakeFiles/softracker.dir/proto.c.o.requires
CMakeFiles/softracker.dir/requires: CMakeFiles/softracker.dir/cJSON.c.o.requires

.PHONY : CMakeFiles/softracker.dir/requires

CMakeFiles/softracker.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/softracker.dir/cmake_clean.cmake
.PHONY : CMakeFiles/softracker.dir/clean

CMakeFiles/softracker.dir/depend:
	cd /home/user/projects/softracker/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/projects/softracker /home/user/projects/softracker /home/user/projects/softracker/build /home/user/projects/softracker/build /home/user/projects/softracker/build/CMakeFiles/softracker.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/softracker.dir/depend

