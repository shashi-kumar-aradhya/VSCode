# CMakeLists.txt (Root)
cmake_minimum_required(VERSION 3.10)

if(WIN32)
    set(CMAKE_C_COMPILER "C:/path/to/gcc.exe")
    message(DEBUG "This is a debug message1")
elseif(APPLE)
    set(CMAKE_C_COMPILER "/usr/bin/clang")
    message(DEBUG "This is a debug message2")
else()
    set(CMAKE_C_COMPILER "/usr/bin/gcc")
    message(DEBUG "This is a debug message3")
endif()

project(HelloWorld)

# Set the C standard
set(CMAKE_C_STANDARD 99)

# Define the output directories for different build types
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/debug/bin)  # Debug executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/release/bin)  # Release executables
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/debug/lib)  # Debug static libraries
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/release/lib)  # Release static libraries
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/debug/lib)  # Debug shared libraries
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/release/lib)  # Release shared libraries
set(CMAKE_OBJECT_PATH_PREFIX ${CMAKE_BINARY_DIR}/obj/)  # Object files directory (same for both build types)

# Include directories for headers
include_directories(include)

# Add subdirectories for the libraries
add_subdirectory(lib/libmath)
add_subdirectory(lib/libstring)

# Add source files
set(SOURCES
    src/main.c
    src/app.c
    src/utils.c
)

# Specify the name of the executable (e.g., hello_world)
add_executable(hello_world ${SOURCES})

# Link libraries
target_link_libraries(hello_world math string_utils)

# Optional: You can also customize the executable name based on build type
# This is helpful if you want separate names for Debug and Release builds
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set_target_properties(hello_world PROPERTIES OUTPUT_NAME "hello_world_debug")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    set_target_properties(hello_world PROPERTIES OUTPUT_NAME "hello_world_release")
endif()

