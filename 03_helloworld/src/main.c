#include <stdio.h>
#include "app.h"
#include "utils.h"
#include "math.h"
#include "string_utils.h"
int main() {
    printf("Hello, World from CMake!\n");
    
    // Call function from app.c
    app_function();

    // Call utility function
    util_function();

    // Call function from libmath
    double result = add(3.5, 2.5);
    printf("Math result: %f\n", result);

    // Call string utility
    char* reversed = reverse_string("CMake");
    printf("Reversed string: %s\n", reversed);
    
    return 0;
}

