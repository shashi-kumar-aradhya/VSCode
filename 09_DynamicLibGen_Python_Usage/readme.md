Explanation of CMakeLists.txt:

    Find CMake and Python:
        find_package(Python3 REQUIRED COMPONENTS Interpreter Development) ensures that CMake can locate Python and its development headers.
        find_package(Cython REQUIRED) locates the Cython package (it must be installed).

    Cython Compilation:
        cython_add_module(math_functions MODULE math_functions.pyx) tells CMake to convert the math_functions.pyx file into a Python C extension (math_functions.cpython-<version>-<platform>.so).

    Link C++ Code:
        target_link_libraries(math_functions PRIVATE ${SOURCE_DIR}/math_functions.cpp) links the compiled C++ code with the Python extension. This ensures that the C++ logic is included in the shared object created by Cython.

    Optional Python Includes and Libraries:
        You can uncomment the include_directories() and target_link_libraries() lines to explicitly specify Python's include and library paths if necessary.


python3 setup.py build_ext --inplace        
python3 test_cython.py
