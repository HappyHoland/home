# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\lucas\Documents\Tecnologia e Informacao\2022.1\LP1\lp1-lista1-cpp_basico-HappyHoland\histograma"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\lucas\Documents\Tecnologia e Informacao\2022.1\LP1\lp1-lista1-cpp_basico-HappyHoland\histograma\build"

# Include any dependencies generated for this target.
include CMakeFiles/tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tests.dir/flags.make

CMakeFiles/tests.dir/tests/main.cpp.obj: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/tests/main.cpp.obj: CMakeFiles/tests.dir/includes_CXX.rsp
CMakeFiles/tests.dir/tests/main.cpp.obj: ../tests/main.cpp
CMakeFiles/tests.dir/tests/main.cpp.obj: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\lucas\Documents\Tecnologia e Informacao\2022.1\LP1\lp1-lista1-cpp_basico-HappyHoland\histograma\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tests.dir/tests/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests.dir/tests/main.cpp.obj -MF CMakeFiles\tests.dir\tests\main.cpp.obj.d -o CMakeFiles\tests.dir\tests\main.cpp.obj -c "C:\Users\lucas\Documents\Tecnologia e Informacao\2022.1\LP1\lp1-lista1-cpp_basico-HappyHoland\histograma\tests\main.cpp"

CMakeFiles/tests.dir/tests/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/tests/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\lucas\Documents\Tecnologia e Informacao\2022.1\LP1\lp1-lista1-cpp_basico-HappyHoland\histograma\tests\main.cpp" > CMakeFiles\tests.dir\tests\main.cpp.i

CMakeFiles/tests.dir/tests/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/tests/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\lucas\Documents\Tecnologia e Informacao\2022.1\LP1\lp1-lista1-cpp_basico-HappyHoland\histograma\tests\main.cpp" -o CMakeFiles\tests.dir\tests\main.cpp.s

CMakeFiles/tests.dir/src/function.cpp.obj: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/src/function.cpp.obj: CMakeFiles/tests.dir/includes_CXX.rsp
CMakeFiles/tests.dir/src/function.cpp.obj: ../src/function.cpp
CMakeFiles/tests.dir/src/function.cpp.obj: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\lucas\Documents\Tecnologia e Informacao\2022.1\LP1\lp1-lista1-cpp_basico-HappyHoland\histograma\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tests.dir/src/function.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests.dir/src/function.cpp.obj -MF CMakeFiles\tests.dir\src\function.cpp.obj.d -o CMakeFiles\tests.dir\src\function.cpp.obj -c "C:\Users\lucas\Documents\Tecnologia e Informacao\2022.1\LP1\lp1-lista1-cpp_basico-HappyHoland\histograma\src\function.cpp"

CMakeFiles/tests.dir/src/function.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/src/function.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\lucas\Documents\Tecnologia e Informacao\2022.1\LP1\lp1-lista1-cpp_basico-HappyHoland\histograma\src\function.cpp" > CMakeFiles\tests.dir\src\function.cpp.i

CMakeFiles/tests.dir/src/function.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/src/function.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\lucas\Documents\Tecnologia e Informacao\2022.1\LP1\lp1-lista1-cpp_basico-HappyHoland\histograma\src\function.cpp" -o CMakeFiles\tests.dir\src\function.cpp.s

CMakeFiles/tests.dir/d7c6866b28e7416a783e26c643625e07/2022.1/LP1/lp1-lista1-cpp_basico-HappyHoland/test_manager/src/test_manager.cpp.obj: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/d7c6866b28e7416a783e26c643625e07/2022.1/LP1/lp1-lista1-cpp_basico-HappyHoland/test_manager/src/test_manager.cpp.obj: CMakeFiles/tests.dir/includes_CXX.rsp
CMakeFiles/tests.dir/d7c6866b28e7416a783e26c643625e07/2022.1/LP1/lp1-lista1-cpp_basico-HappyHoland/test_manager/src/test_manager.cpp.obj: C:/Users/lucas/Documents/Tecnologia\ e\ Informacao/2022.1/LP1/lp1-lista1-cpp_basico-HappyHoland/test_manager/src/test_manager.cpp
CMakeFiles/tests.dir/d7c6866b28e7416a783e26c643625e07/2022.1/LP1/lp1-lista1-cpp_basico-HappyHoland/test_manager/src/test_manager.cpp.obj: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\lucas\Documents\Tecnologia e Informacao\2022.1\LP1\lp1-lista1-cpp_basico-HappyHoland\histograma\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/tests.dir/d7c6866b28e7416a783e26c643625e07/2022.1/LP1/lp1-lista1-cpp_basico-HappyHoland/test_manager/src/test_manager.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests.dir/d7c6866b28e7416a783e26c643625e07/2022.1/LP1/lp1-lista1-cpp_basico-HappyHoland/test_manager/src/test_manager.cpp.obj -MF CMakeFiles\tests.dir\d7c6866b28e7416a783e26c643625e07\2022.1\LP1\lp1-lista1-cpp_basico-HappyHoland\test_manager\src\test_manager.cpp.obj.d -o CMakeFiles\tests.dir\d7c6866b28e7416a783e26c643625e07\2022.1\LP1\lp1-lista1-cpp_basico-HappyHoland\test_manager\src\test_manager.cpp.obj -c "C:\Users\lucas\Documents\Tecnologia e Informacao\2022.1\LP1\lp1-lista1-cpp_basico-HappyHoland\test_manager\src\test_manager.cpp"

CMakeFiles/tests.dir/d7c6866b28e7416a783e26c643625e07/2022.1/LP1/lp1-lista1-cpp_basico-HappyHoland/test_manager/src/test_manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/d7c6866b28e7416a783e26c643625e07/2022.1/LP1/lp1-lista1-cpp_basico-HappyHoland/test_manager/src/test_manager.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\lucas\Documents\Tecnologia e Informacao\2022.1\LP1\lp1-lista1-cpp_basico-HappyHoland\test_manager\src\test_manager.cpp" > CMakeFiles\tests.dir\d7c6866b28e7416a783e26c643625e07\2022.1\LP1\lp1-lista1-cpp_basico-HappyHoland\test_manager\src\test_manager.cpp.i

CMakeFiles/tests.dir/d7c6866b28e7416a783e26c643625e07/2022.1/LP1/lp1-lista1-cpp_basico-HappyHoland/test_manager/src/test_manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/d7c6866b28e7416a783e26c643625e07/2022.1/LP1/lp1-lista1-cpp_basico-HappyHoland/test_manager/src/test_manager.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\lucas\Documents\Tecnologia e Informacao\2022.1\LP1\lp1-lista1-cpp_basico-HappyHoland\test_manager\src\test_manager.cpp" -o CMakeFiles\tests.dir\d7c6866b28e7416a783e26c643625e07\2022.1\LP1\lp1-lista1-cpp_basico-HappyHoland\test_manager\src\test_manager.cpp.s

# Object files for target tests
tests_OBJECTS = \
"CMakeFiles/tests.dir/tests/main.cpp.obj" \
"CMakeFiles/tests.dir/src/function.cpp.obj" \
"CMakeFiles/tests.dir/d7c6866b28e7416a783e26c643625e07/2022.1/LP1/lp1-lista1-cpp_basico-HappyHoland/test_manager/src/test_manager.cpp.obj"

# External object files for target tests
tests_EXTERNAL_OBJECTS =

tests.exe: CMakeFiles/tests.dir/tests/main.cpp.obj
tests.exe: CMakeFiles/tests.dir/src/function.cpp.obj
tests.exe: CMakeFiles/tests.dir/d7c6866b28e7416a783e26c643625e07/2022.1/LP1/lp1-lista1-cpp_basico-HappyHoland/test_manager/src/test_manager.cpp.obj
tests.exe: CMakeFiles/tests.dir/build.make
tests.exe: CMakeFiles/tests.dir/linklibs.rsp
tests.exe: CMakeFiles/tests.dir/objects1.rsp
tests.exe: CMakeFiles/tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\lucas\Documents\Tecnologia e Informacao\2022.1\LP1\lp1-lista1-cpp_basico-HappyHoland\histograma\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable tests.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\tests.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tests.dir/build: tests.exe
.PHONY : CMakeFiles/tests.dir/build

CMakeFiles/tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\tests.dir\cmake_clean.cmake
.PHONY : CMakeFiles/tests.dir/clean

CMakeFiles/tests.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\lucas\Documents\Tecnologia e Informacao\2022.1\LP1\lp1-lista1-cpp_basico-HappyHoland\histograma" "C:\Users\lucas\Documents\Tecnologia e Informacao\2022.1\LP1\lp1-lista1-cpp_basico-HappyHoland\histograma" "C:\Users\lucas\Documents\Tecnologia e Informacao\2022.1\LP1\lp1-lista1-cpp_basico-HappyHoland\histograma\build" "C:\Users\lucas\Documents\Tecnologia e Informacao\2022.1\LP1\lp1-lista1-cpp_basico-HappyHoland\histograma\build" "C:\Users\lucas\Documents\Tecnologia e Informacao\2022.1\LP1\lp1-lista1-cpp_basico-HappyHoland\histograma\build\CMakeFiles\tests.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/tests.dir/depend

