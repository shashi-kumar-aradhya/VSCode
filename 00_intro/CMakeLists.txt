# This is required in all CMakeLists Selecting a nice minimum version and range
cmake_minimum_required(VERSION 3.15...3.25)


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

# We can call the project anything we want Listing the language(s) avoids the C
# + CXX default
project(MyExample00 LANGUAGES C)

# We need an executable target
add_executable(simple_example simple.c)
