# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/goldenf2/Downloads/clion-2021.1.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/goldenf2/Downloads/clion-2021.1.2/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/goldenf2/OneDrive/Documents/Faculdade/2021.1/Classificação e Pesquisa de Dados/TrabFinal/CPD-TRAB-FINAL"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/goldenf2/OneDrive/Documents/Faculdade/2021.1/Classificação e Pesquisa de Dados/TrabFinal/CPD-TRAB-FINAL/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/CPD_TRAB_FINAL.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/CPD_TRAB_FINAL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CPD_TRAB_FINAL.dir/flags.make

CMakeFiles/CPD_TRAB_FINAL.dir/main.cpp.o: CMakeFiles/CPD_TRAB_FINAL.dir/flags.make
CMakeFiles/CPD_TRAB_FINAL.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/goldenf2/OneDrive/Documents/Faculdade/2021.1/Classificação e Pesquisa de Dados/TrabFinal/CPD-TRAB-FINAL/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CPD_TRAB_FINAL.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CPD_TRAB_FINAL.dir/main.cpp.o -c "/home/goldenf2/OneDrive/Documents/Faculdade/2021.1/Classificação e Pesquisa de Dados/TrabFinal/CPD-TRAB-FINAL/main.cpp"

CMakeFiles/CPD_TRAB_FINAL.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPD_TRAB_FINAL.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/goldenf2/OneDrive/Documents/Faculdade/2021.1/Classificação e Pesquisa de Dados/TrabFinal/CPD-TRAB-FINAL/main.cpp" > CMakeFiles/CPD_TRAB_FINAL.dir/main.cpp.i

CMakeFiles/CPD_TRAB_FINAL.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPD_TRAB_FINAL.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/goldenf2/OneDrive/Documents/Faculdade/2021.1/Classificação e Pesquisa de Dados/TrabFinal/CPD-TRAB-FINAL/main.cpp" -o CMakeFiles/CPD_TRAB_FINAL.dir/main.cpp.s

CMakeFiles/CPD_TRAB_FINAL.dir/definitions.cpp.o: CMakeFiles/CPD_TRAB_FINAL.dir/flags.make
CMakeFiles/CPD_TRAB_FINAL.dir/definitions.cpp.o: ../definitions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/goldenf2/OneDrive/Documents/Faculdade/2021.1/Classificação e Pesquisa de Dados/TrabFinal/CPD-TRAB-FINAL/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CPD_TRAB_FINAL.dir/definitions.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CPD_TRAB_FINAL.dir/definitions.cpp.o -c "/home/goldenf2/OneDrive/Documents/Faculdade/2021.1/Classificação e Pesquisa de Dados/TrabFinal/CPD-TRAB-FINAL/definitions.cpp"

CMakeFiles/CPD_TRAB_FINAL.dir/definitions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPD_TRAB_FINAL.dir/definitions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/goldenf2/OneDrive/Documents/Faculdade/2021.1/Classificação e Pesquisa de Dados/TrabFinal/CPD-TRAB-FINAL/definitions.cpp" > CMakeFiles/CPD_TRAB_FINAL.dir/definitions.cpp.i

CMakeFiles/CPD_TRAB_FINAL.dir/definitions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPD_TRAB_FINAL.dir/definitions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/goldenf2/OneDrive/Documents/Faculdade/2021.1/Classificação e Pesquisa de Dados/TrabFinal/CPD-TRAB-FINAL/definitions.cpp" -o CMakeFiles/CPD_TRAB_FINAL.dir/definitions.cpp.s

CMakeFiles/CPD_TRAB_FINAL.dir/hashoff.cpp.o: CMakeFiles/CPD_TRAB_FINAL.dir/flags.make
CMakeFiles/CPD_TRAB_FINAL.dir/hashoff.cpp.o: ../hashoff.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/goldenf2/OneDrive/Documents/Faculdade/2021.1/Classificação e Pesquisa de Dados/TrabFinal/CPD-TRAB-FINAL/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CPD_TRAB_FINAL.dir/hashoff.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CPD_TRAB_FINAL.dir/hashoff.cpp.o -c "/home/goldenf2/OneDrive/Documents/Faculdade/2021.1/Classificação e Pesquisa de Dados/TrabFinal/CPD-TRAB-FINAL/hashoff.cpp"

CMakeFiles/CPD_TRAB_FINAL.dir/hashoff.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPD_TRAB_FINAL.dir/hashoff.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/goldenf2/OneDrive/Documents/Faculdade/2021.1/Classificação e Pesquisa de Dados/TrabFinal/CPD-TRAB-FINAL/hashoff.cpp" > CMakeFiles/CPD_TRAB_FINAL.dir/hashoff.cpp.i

CMakeFiles/CPD_TRAB_FINAL.dir/hashoff.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPD_TRAB_FINAL.dir/hashoff.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/goldenf2/OneDrive/Documents/Faculdade/2021.1/Classificação e Pesquisa de Dados/TrabFinal/CPD-TRAB-FINAL/hashoff.cpp" -o CMakeFiles/CPD_TRAB_FINAL.dir/hashoff.cpp.s

# Object files for target CPD_TRAB_FINAL
CPD_TRAB_FINAL_OBJECTS = \
"CMakeFiles/CPD_TRAB_FINAL.dir/main.cpp.o" \
"CMakeFiles/CPD_TRAB_FINAL.dir/definitions.cpp.o" \
"CMakeFiles/CPD_TRAB_FINAL.dir/hashoff.cpp.o"

# External object files for target CPD_TRAB_FINAL
CPD_TRAB_FINAL_EXTERNAL_OBJECTS =

CPD_TRAB_FINAL: CMakeFiles/CPD_TRAB_FINAL.dir/main.cpp.o
CPD_TRAB_FINAL: CMakeFiles/CPD_TRAB_FINAL.dir/definitions.cpp.o
CPD_TRAB_FINAL: CMakeFiles/CPD_TRAB_FINAL.dir/hashoff.cpp.o
CPD_TRAB_FINAL: CMakeFiles/CPD_TRAB_FINAL.dir/build.make
CPD_TRAB_FINAL: CMakeFiles/CPD_TRAB_FINAL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/goldenf2/OneDrive/Documents/Faculdade/2021.1/Classificação e Pesquisa de Dados/TrabFinal/CPD-TRAB-FINAL/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable CPD_TRAB_FINAL"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CPD_TRAB_FINAL.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CPD_TRAB_FINAL.dir/build: CPD_TRAB_FINAL
.PHONY : CMakeFiles/CPD_TRAB_FINAL.dir/build

CMakeFiles/CPD_TRAB_FINAL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CPD_TRAB_FINAL.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CPD_TRAB_FINAL.dir/clean

CMakeFiles/CPD_TRAB_FINAL.dir/depend:
	cd "/home/goldenf2/OneDrive/Documents/Faculdade/2021.1/Classificação e Pesquisa de Dados/TrabFinal/CPD-TRAB-FINAL/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/goldenf2/OneDrive/Documents/Faculdade/2021.1/Classificação e Pesquisa de Dados/TrabFinal/CPD-TRAB-FINAL" "/home/goldenf2/OneDrive/Documents/Faculdade/2021.1/Classificação e Pesquisa de Dados/TrabFinal/CPD-TRAB-FINAL" "/home/goldenf2/OneDrive/Documents/Faculdade/2021.1/Classificação e Pesquisa de Dados/TrabFinal/CPD-TRAB-FINAL/cmake-build-debug" "/home/goldenf2/OneDrive/Documents/Faculdade/2021.1/Classificação e Pesquisa de Dados/TrabFinal/CPD-TRAB-FINAL/cmake-build-debug" "/home/goldenf2/OneDrive/Documents/Faculdade/2021.1/Classificação e Pesquisa de Dados/TrabFinal/CPD-TRAB-FINAL/cmake-build-debug/CMakeFiles/CPD_TRAB_FINAL.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/CPD_TRAB_FINAL.dir/depend

