# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Aurelien\Documents\GitHub\project_SE\Code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Aurelien\Documents\GitHub\project_SE\Code\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/projet_.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/projet_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/projet_.dir/flags.make

CMakeFiles/projet_.dir/main.c.obj: CMakeFiles/projet_.dir/flags.make
CMakeFiles/projet_.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Aurelien\Documents\GitHub\project_SE\Code\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/projet_.dir/main.c.obj"
	avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\projet_.dir\main.c.obj   -c C:\Users\Aurelien\Documents\GitHub\project_SE\Code\main.c

CMakeFiles/projet_.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/projet_.dir/main.c.i"
	avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Aurelien\Documents\GitHub\project_SE\Code\main.c > CMakeFiles\projet_.dir\main.c.i

CMakeFiles/projet_.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/projet_.dir/main.c.s"
	avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Aurelien\Documents\GitHub\project_SE\Code\main.c -o CMakeFiles\projet_.dir\main.c.s

# Object files for target projet_
projet__OBJECTS = \
"CMakeFiles/projet_.dir/main.c.obj"

# External object files for target projet_
projet__EXTERNAL_OBJECTS =

../bin/projet_: CMakeFiles/projet_.dir/main.c.obj
../bin/projet_: CMakeFiles/projet_.dir/build.make
../bin/projet_: CMakeFiles/projet_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Aurelien\Documents\GitHub\project_SE\Code\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ..\bin\projet_"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\projet_.dir\link.txt --verbose=$(VERBOSE)
	avr-objcopy -O ihex -R.eeprom C:/Users/Aurelien/Documents/GitHub/project_SE/Code/bin/projet_ C:/Users/Aurelien/Documents/GitHub/project_SE/Code/bin/projet_.hex
	avr-objcopy -O ihex -j .eeprom --set-section-flags=.eeprom="alloc,load" --change-section-lma .eeprom=0 C:/Users/Aurelien/Documents/GitHub/project_SE/Code/bin/projet_ C:/Users/Aurelien/Documents/GitHub/project_SE/Code/bin/projet_.eep
	avr-size C:/Users/Aurelien/Documents/GitHub/project_SE/Code/bin/projet_ --mcu=ATmega128 --format=avr

# Rule to build all files generated by this target.
CMakeFiles/projet_.dir/build: ../bin/projet_

.PHONY : CMakeFiles/projet_.dir/build

CMakeFiles/projet_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\projet_.dir\cmake_clean.cmake
.PHONY : CMakeFiles/projet_.dir/clean

CMakeFiles/projet_.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Aurelien\Documents\GitHub\project_SE\Code C:\Users\Aurelien\Documents\GitHub\project_SE\Code C:\Users\Aurelien\Documents\GitHub\project_SE\Code\cmake-build-debug C:\Users\Aurelien\Documents\GitHub\project_SE\Code\cmake-build-debug C:\Users\Aurelien\Documents\GitHub\project_SE\Code\cmake-build-debug\CMakeFiles\projet_.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/projet_.dir/depend

