// tests/test_app.cpp
#include <gtest/gtest.h>
#include "app.h"

TEST(AppTest, AddFunction) {
    App app;
    EXPECT_EQ(app.add(2, 3), 5);  // Test the add function
    EXPECT_EQ(app.add(-1, 1), 0);
    EXPECT_EQ(app.add(-5, -5), -10);
}

