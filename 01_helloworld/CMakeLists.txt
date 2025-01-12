# CMakeLists.txt
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

# Set the project name
project(HelloWorld)

# Include the directory where the header files are located
include_directories(include)

# Add the source files from the 'src' folder
set(SOURCES
    src/main.c
    src/foo.c
)

# Create an executable from the source files
add_executable(hello_world ${SOURCES})
