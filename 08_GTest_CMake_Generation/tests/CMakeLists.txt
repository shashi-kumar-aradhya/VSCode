# tests/CMakeLists.txt
if(BUILD_TESTS)
    # Link GoogleTest and the application library
    add_executable(run_tests test_app.cpp)
    target_link_libraries(run_tests GTest::GTest GTest::Main complex_app)

    # Register the tests with CTest
    add_test(NAME run_tests COMMAND run_tests)
endif()

