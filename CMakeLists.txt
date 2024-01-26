cmake_minimum_required(VERSION 3.5)

project(sobel LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
set(SOURCES
    src/main.cpp
)

# Main executable
add_executable(main ${SOURCES})

add_subdirectory(src/image)

# Find and link OpenCV
find_package(OpenCV REQUIRED)
target_link_libraries(main ${OpenCV_LIBS} image)

# Add the test subdirectory
add_subdirectory(test)
