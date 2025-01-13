# setup.py
from setuptools import setup, Extension
from Cython.Build import cythonize

# Define the Cython extension module
ext_modules = [
    Extension(
        "math_functions",                          # Name of the output shared library
        sources=["math_functions.pyx", "math_functions.cpp"],  # Cython file and C++ source file
        language="c++",                             # Use C++ compiler
        include_dirs=["."]                          # Include current directory for header files
    )
]

# Setup the extension module
setup(
    name="MathFunctions",
    ext_modules=cythonize(ext_modules),
)

