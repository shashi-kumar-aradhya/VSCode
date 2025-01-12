# CMakeLists.txt for libstring
add_library(string_utils STATIC string_utils.c)

# Specify the include directory for the string utilities library
target_include_directories(string_utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

