# lib/CMakeLists.txt
include(FetchContent)

# Fetch Google Test from GitHub
FetchContent_Declare(
    gtest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0  # Use a specific release version
)

FetchContent_MakeAvailable(gtest)

# Link GoogleTest and GoogleMock libraries to your tests

