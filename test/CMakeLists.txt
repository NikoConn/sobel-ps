# Download and configure Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

# Test files
set(TEST_SOURCES
    operations_test.cpp
)

# Test executable
add_executable(tests ${TEST_SOURCES})

target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/src)

# Link Google Test to the test executable
target_link_libraries(tests gtest gtest_main image)

# Add a test target
add_test(NAME SobelTest COMMAND tests)

