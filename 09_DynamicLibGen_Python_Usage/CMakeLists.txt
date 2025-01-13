cmake_minimum_required(VERSION 3.12)

if(WIN32)
    # Set the C compiler to GCC (if using MinGW or another GCC-based toolchain)
    set(CMAKE_C_COMPILER "C:/path/to/gcc.exe")

    # Set the C++ compiler to G++ (for MinGW or similar GCC-based toolchains)
    set(CMAKE_CXX_COMPILER "C:/path/to/g++.exe")

    message(DEBUG "This is a debug message for Windows")
elseif(APPLE)
    # Set the C compiler to Clang
    set(CMAKE_C_COMPILER "/usr/bin/clang")

    # Set the C++ compiler to Clang++
    set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

    message(DEBUG "This is a debug message for macOS")
else()
    # Set the C compiler to GCC (for Linux or other Unix-like systems)
    set(CMAKE_C_COMPILER "/usr/bin/gcc")

    # Set the C++ compiler to G++ (for Linux or other Unix-like systems)
    set(CMAKE_CXX_COMPILER "/usr/bin/g++")

    message(DEBUG "This is a debug message for Linux/Unix")
endif()

project(CythonCppExample)

# Find Python and Cython
find_package(Python3 REQUIRED COMPONENTS Interpreter Development)
find_program(CYTHON_EXECUTABLE cython)

# Ensure Cython is found
if(NOT CYTHON_EXECUTABLE)
    message(FATAL_ERROR "Cython not found. Please install Cython and ensure it is in your PATH.")
endif()

# Generate C file from Cython source
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/math_functions.c
    COMMAND ${CYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/math_functions.pyx
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/math_functions.pyx
    COMMENT "Generating C file from Cython"
)

# Add the C++ file and the generated C file to the sources
set(SOURCES ${CMAKE_CURRENT_BINARY_DIR}/math_functions.c ${CMAKE_CURRENT_SOURCE_DIR}/math_functions.cpp)

# Create the Python extension module
add_library(math_functions MODULE ${SOURCES})

# Link the C++ code to the extension module
target_link_libraries(math_functions PRIVATE ${Python3_LIBRARIES})

# Specify the include directories (e.g., for Python headers and the C++ header)
include_directories(${Python3_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR})

