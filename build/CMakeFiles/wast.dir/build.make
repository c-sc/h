# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /media/ntfs/cyb/eos-contracts/contracts/h

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/ntfs/cyb/eos-contracts/contracts/h/build

# Utility rule file for wast.

# Include the progress variables for this target.
include CMakeFiles/wast.dir/progress.make

CMakeFiles/wast:
	/media/ntfs/cyb/eos-contracts/eosfactory/teos/build/teos/teos build contract /media/ntfs/cyb/eos-contracts/contracts/h/src

wast: CMakeFiles/wast
wast: CMakeFiles/wast.dir/build.make

.PHONY : wast

# Rule to build all files generated by this target.
CMakeFiles/wast.dir/build: wast

.PHONY : CMakeFiles/wast.dir/build

CMakeFiles/wast.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/wast.dir/cmake_clean.cmake
.PHONY : CMakeFiles/wast.dir/clean

CMakeFiles/wast.dir/depend:
	cd /media/ntfs/cyb/eos-contracts/contracts/h/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/ntfs/cyb/eos-contracts/contracts/h /media/ntfs/cyb/eos-contracts/contracts/h /media/ntfs/cyb/eos-contracts/contracts/h/build /media/ntfs/cyb/eos-contracts/contracts/h/build /media/ntfs/cyb/eos-contracts/contracts/h/build/CMakeFiles/wast.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/wast.dir/depend

