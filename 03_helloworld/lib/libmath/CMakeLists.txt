# CMakeLists.txt for libmath
add_library(math STATIC math.c)

# Specify the include directory for the math library
target_include_directories(math PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

