#include <gtest/gtest.h>
#include "app.h"

// Test the addition functionality
TEST(AppTest, AddFunction) {
    App app;
    EXPECT_EQ(app.add(2, 3), 5);  // Normal addition
    EXPECT_EQ(app.add(-1, 1), 0); // Adding negative and positive numbers
    EXPECT_EQ(app.add(-5, -5), -10); // Adding two negative numbers
}

// Test the subtraction functionality
TEST(AppTest, SubtractFunction) {
    App app;
    EXPECT_EQ(app.subtract(5, 3), 2);  // Normal subtraction
    EXPECT_EQ(app.subtract(3, 5), -2); // Subtracting larger number from smaller one
    EXPECT_EQ(app.subtract(0, 0), 0);  // Subtracting zero from zero
    EXPECT_EQ(app.subtract(-1, -1), 0); // Subtracting two negative numbers
}

// Test the multiplication functionality
TEST(AppTest, MultiplyFunction) {
    App app;
    EXPECT_EQ(app.multiply(2, 3), 6);  // Normal multiplication
    EXPECT_EQ(app.multiply(-2, 3), -6); // Multiplying negative number
    EXPECT_EQ(app.multiply(0, 100), 0); // Multiplying by zero
    EXPECT_EQ(app.multiply(-2, -3), 6); // Multiplying two negative numbers
}

// Test the division functionality
TEST(AppTest, DivideFunction) {
    App app;
    EXPECT_EQ(app.divide(6, 2), 3);  // Normal division
    EXPECT_EQ(app.divide(-6, 2), -3); // Division with negative result
    EXPECT_EQ(app.divide(0, 100), 0); // Dividing by a number other than zero
    EXPECT_THROW(app.divide(5, 0), std::invalid_argument); // Dividing by zero (should throw exception)
}

// Test edge case with very large numbers
TEST(AppTest, LargeNumbers) {
    App app;
    EXPECT_EQ(app.add(1000000000, 1000000000), 2000000000); // Adding large numbers
    EXPECT_EQ(app.subtract(1000000000, 500000000), 500000000); // Subtracting large numbers
    EXPECT_EQ(app.multiply(100000, 100000), 10000000000); // Multiplying large numbers
    EXPECT_EQ(app.divide(1000000000, 1000), 1000000); // Dividing large numbers
}

// Test floating-point numbers (if the `App` class supports float/double)
TEST(AppTest, FloatOperations) {
    App app;
    EXPECT_NEAR(app.add(0.1, 0.2), 0.3, 1e-9);  // Floating-point addition
    EXPECT_NEAR(app.subtract(0.5, 0.2), 0.3, 1e-9); // Floating-point subtraction
    EXPECT_NEAR(app.multiply(1.5, 2.0), 3.0, 1e-9); // Floating-point multiplication
    EXPECT_NEAR(app.divide(2.0, 0.5), 4.0, 1e-9);  // Floating-point division
}

// Test with negative numbers
TEST(AppTest, NegativeNumbers) {
    App app;
    EXPECT_EQ(app.add(-10, -5), -15);  // Adding two negative numbers
    EXPECT_EQ(app.subtract(-10, -5), -5); // Subtracting negative numbers
    EXPECT_EQ(app.multiply(-10, -5), 50); // Multiplying two negative numbers
    EXPECT_EQ(app.divide(-10, -2), 5); // Dividing two negative numbers
}

