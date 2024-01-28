cmake_minimum_required(VERSION 3.5)

project(sobel LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
set(SOURCES
    src/main.cpp
)

# Main executable
add_executable(sobel ${SOURCES})

add_subdirectory(external-libs/image-ps)

# Find and link OpenCV
find_package(OpenCV REQUIRED)
target_link_libraries(sobel ${OpenCV_LIBS} image)
