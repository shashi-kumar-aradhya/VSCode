For NORMAL
=========================================
cmake ..
make


For debug
=========================================
cmake -DCMAKE_BUILD_TYPE=Debug ..
make


For release
=========================================
cmake -DCMAKE_BUILD_TYPE=Release ..
make


# Debug-specific flags
set(CMAKE_C_FLAGS_DEBUG "-g -Wall")

# Release-specific flags
set(CMAKE_C_FLAGS_RELEASE "-O3 -Wall")


Explanation of Changes:
=========================================
CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG and CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE: 
These control where the compiled executables go for the debug and release builds, respectively. 
The debug/ folder is used for debug builds and release/ for release builds.

CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG and CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE: 
These control where static libraries (.a) are stored for each build type.
CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG and CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE: 
These control where shared libraries (.so) are placed for each build type.
CMAKE_OBJECT_PATH_PREFIX: 
This sets the object files to go into the obj/ directory for both build types.


sudo apt-get update
sudo apt-get install libgtest-dev

cd /usr/src/googletest
sudo cmake .
sudo make
sudo make install

or

sudo cp lib\libgtest.a /usr/lib
sudo cp lib\libgtest_main.a /usr/lib
