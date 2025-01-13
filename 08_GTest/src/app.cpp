// src/app.cpp
#include "app.h"

// Function to add two integers
int App::add(int a, int b) {
    return a + b;
}

// Function to subtract two integers
int App::subtract(int a, int b) {
    return a - b;
}

// Function to multiply two integers
int App::multiply(int a, int b) {
    return a * b;
}

// Function to divide two integers
// Throws an exception if attempting to divide by zero
double App::divide(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero is not allowed");
    }
    return static_cast<double>(a) / b;
}
