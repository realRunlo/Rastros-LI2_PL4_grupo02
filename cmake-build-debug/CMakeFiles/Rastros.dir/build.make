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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\braza\OneDrive\Documentos\GitHub\Rastros

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\braza\OneDrive\Documentos\GitHub\Rastros\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Rastros.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Rastros.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Rastros.dir/flags.make

CMakeFiles/Rastros.dir/rastros.c.obj: CMakeFiles/Rastros.dir/flags.make
CMakeFiles/Rastros.dir/rastros.c.obj: ../rastros.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\braza\OneDrive\Documentos\GitHub\Rastros\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Rastros.dir/rastros.c.obj"
	D:\8.6.5\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Rastros.dir\rastros.c.obj   -c C:\Users\braza\OneDrive\Documentos\GitHub\Rastros\rastros.c

CMakeFiles/Rastros.dir/rastros.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Rastros.dir/rastros.c.i"
	D:\8.6.5\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\braza\OneDrive\Documentos\GitHub\Rastros\rastros.c > CMakeFiles\Rastros.dir\rastros.c.i

CMakeFiles/Rastros.dir/rastros.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Rastros.dir/rastros.c.s"
	D:\8.6.5\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\braza\OneDrive\Documentos\GitHub\Rastros\rastros.c -o CMakeFiles\Rastros.dir\rastros.c.s

CMakeFiles/Rastros.dir/camada_dados.c.obj: CMakeFiles/Rastros.dir/flags.make
CMakeFiles/Rastros.dir/camada_dados.c.obj: ../camada_dados.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\braza\OneDrive\Documentos\GitHub\Rastros\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Rastros.dir/camada_dados.c.obj"
	D:\8.6.5\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Rastros.dir\camada_dados.c.obj   -c C:\Users\braza\OneDrive\Documentos\GitHub\Rastros\camada_dados.c

CMakeFiles/Rastros.dir/camada_dados.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Rastros.dir/camada_dados.c.i"
	D:\8.6.5\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\braza\OneDrive\Documentos\GitHub\Rastros\camada_dados.c > CMakeFiles\Rastros.dir\camada_dados.c.i

CMakeFiles/Rastros.dir/camada_dados.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Rastros.dir/camada_dados.c.s"
	D:\8.6.5\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\braza\OneDrive\Documentos\GitHub\Rastros\camada_dados.c -o CMakeFiles\Rastros.dir\camada_dados.c.s

CMakeFiles/Rastros.dir/interface.c.obj: CMakeFiles/Rastros.dir/flags.make
CMakeFiles/Rastros.dir/interface.c.obj: ../interface.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\braza\OneDrive\Documentos\GitHub\Rastros\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Rastros.dir/interface.c.obj"
	D:\8.6.5\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Rastros.dir\interface.c.obj   -c C:\Users\braza\OneDrive\Documentos\GitHub\Rastros\interface.c

CMakeFiles/Rastros.dir/interface.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Rastros.dir/interface.c.i"
	D:\8.6.5\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\braza\OneDrive\Documentos\GitHub\Rastros\interface.c > CMakeFiles\Rastros.dir\interface.c.i

CMakeFiles/Rastros.dir/interface.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Rastros.dir/interface.c.s"
	D:\8.6.5\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\braza\OneDrive\Documentos\GitHub\Rastros\interface.c -o CMakeFiles\Rastros.dir\interface.c.s

CMakeFiles/Rastros.dir/logica.c.obj: CMakeFiles/Rastros.dir/flags.make
CMakeFiles/Rastros.dir/logica.c.obj: ../logica.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\braza\OneDrive\Documentos\GitHub\Rastros\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Rastros.dir/logica.c.obj"
	D:\8.6.5\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Rastros.dir\logica.c.obj   -c C:\Users\braza\OneDrive\Documentos\GitHub\Rastros\logica.c

CMakeFiles/Rastros.dir/logica.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Rastros.dir/logica.c.i"
	D:\8.6.5\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\braza\OneDrive\Documentos\GitHub\Rastros\logica.c > CMakeFiles\Rastros.dir\logica.c.i

CMakeFiles/Rastros.dir/logica.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Rastros.dir/logica.c.s"
	D:\8.6.5\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\braza\OneDrive\Documentos\GitHub\Rastros\logica.c -o CMakeFiles\Rastros.dir\logica.c.s

CMakeFiles/Rastros.dir/lista.c.obj: CMakeFiles/Rastros.dir/flags.make
CMakeFiles/Rastros.dir/lista.c.obj: ../lista.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\braza\OneDrive\Documentos\GitHub\Rastros\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Rastros.dir/lista.c.obj"
	D:\8.6.5\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Rastros.dir\lista.c.obj   -c C:\Users\braza\OneDrive\Documentos\GitHub\Rastros\lista.c

CMakeFiles/Rastros.dir/lista.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Rastros.dir/lista.c.i"
	D:\8.6.5\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\braza\OneDrive\Documentos\GitHub\Rastros\lista.c > CMakeFiles\Rastros.dir\lista.c.i

CMakeFiles/Rastros.dir/lista.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Rastros.dir/lista.c.s"
	D:\8.6.5\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\braza\OneDrive\Documentos\GitHub\Rastros\lista.c -o CMakeFiles\Rastros.dir\lista.c.s

# Object files for target Rastros
Rastros_OBJECTS = \
"CMakeFiles/Rastros.dir/rastros.c.obj" \
"CMakeFiles/Rastros.dir/camada_dados.c.obj" \
"CMakeFiles/Rastros.dir/interface.c.obj" \
"CMakeFiles/Rastros.dir/logica.c.obj" \
"CMakeFiles/Rastros.dir/lista.c.obj"

# External object files for target Rastros
Rastros_EXTERNAL_OBJECTS =

Rastros.exe: CMakeFiles/Rastros.dir/rastros.c.obj
Rastros.exe: CMakeFiles/Rastros.dir/camada_dados.c.obj
Rastros.exe: CMakeFiles/Rastros.dir/interface.c.obj
Rastros.exe: CMakeFiles/Rastros.dir/logica.c.obj
Rastros.exe: CMakeFiles/Rastros.dir/lista.c.obj
Rastros.exe: CMakeFiles/Rastros.dir/build.make
Rastros.exe: CMakeFiles/Rastros.dir/linklibs.rsp
Rastros.exe: CMakeFiles/Rastros.dir/objects1.rsp
Rastros.exe: CMakeFiles/Rastros.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\braza\OneDrive\Documentos\GitHub\Rastros\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable Rastros.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Rastros.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Rastros.dir/build: Rastros.exe

.PHONY : CMakeFiles/Rastros.dir/build

CMakeFiles/Rastros.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Rastros.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Rastros.dir/clean

CMakeFiles/Rastros.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\braza\OneDrive\Documentos\GitHub\Rastros C:\Users\braza\OneDrive\Documentos\GitHub\Rastros C:\Users\braza\OneDrive\Documentos\GitHub\Rastros\cmake-build-debug C:\Users\braza\OneDrive\Documentos\GitHub\Rastros\cmake-build-debug C:\Users\braza\OneDrive\Documentos\GitHub\Rastros\cmake-build-debug\CMakeFiles\Rastros.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Rastros.dir/depend

