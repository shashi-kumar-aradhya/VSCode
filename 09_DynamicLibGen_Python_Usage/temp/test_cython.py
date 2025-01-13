# test_cython.py
from math_functions import PyMathFunctions

# Create an instance of the Python wrapper class
math_func = PyMathFunctions()

# Call the functions
result_add = math_func.add(5, 3)
result_subtract = math_func.subtract(10, 4)

print(f"5 + 3 = {result_add}")
print(f"10 - 4 = {result_subtract}")

