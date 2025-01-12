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

# Include directories
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

# Create the executable
add_executable(hello_world ${SOURCES})

# Link libraries
target_link_libraries(hello_world math string_utils)

