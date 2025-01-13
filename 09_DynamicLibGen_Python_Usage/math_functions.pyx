# math_functions.pyx

# Set the language level explicitly
cython: language_level=3

# Declare the C++ class using Cython and the header file
c++ extern from "math_functions.h":
    cdef cppclass MathFunctions:
        MathFunctions()
        int add(int, int)
        int subtract(int, int)

# Create a Python wrapper class around the C++ class
cdef class PyMathFunctions:
    cdef MathFunctions* cpp_math

    def __cinit__(self):
        self.cpp_math = MathFunctions()

    def add(self, a, b):
        return self.cpp_math.add(a, b)

    def subtract(self, a, b):
        return self.cpp_math.subtract(a, b)

