// include/app.h
#pragma once

#include <stdexcept> // for std::invalid_argument

class App{
public:
    int add(int a, int b);
    int subtract(int a, int b);
    int multiply(int a, int b);
    double divide(int a, int b);
};
