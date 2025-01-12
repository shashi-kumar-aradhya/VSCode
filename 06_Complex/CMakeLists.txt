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

project(ComplexProject VERSION 1.0)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output directories for different build types
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/debug/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/release/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/debug/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/release/lib)

# Include directories for headers
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add subdirectories for external libraries (e.g., GoogleTest)
#add_subdirectory(lib)

# Define source files for your application
set(SOURCES
    src/app.cpp
    src/main.cpp
)

# Add the executable
add_executable(complex_app ${SOURCES})

# Link libraries (if you have any)
# target_link_libraries(complex_app some_library)

# Create a static library for your application code
#add_library(complex_lib STATIC ${SOURCES})

# Enable testing if needed
option(BUILD_TESTS "Build tests" ON)
#if(BUILD_TESTS)
#    enable_testing()
#    add_subdirectory(tests)
#endif()

# Enable testing
enable_testing()

# Check if GTest is installed
find_package(GTest REQUIRED)

# Link GoogleTest with the application
if(BUILD_TESTS)
    # Define test sources
    #add_executable(run_tests tests/test_app.cpp)
    add_executable(run_tests tests/test_app.cpp ${SOURCES})

    # Link GoogleTest and application code
    target_link_libraries(run_tests GTest::GTest GTest::Main)

    # Register the test
    add_test(NAME run_tests COMMAND run_tests)
endif()
