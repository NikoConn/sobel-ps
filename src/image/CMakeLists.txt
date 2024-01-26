set(IMAGE_SOURCES
    mat.cpp
    operations.cpp
)

set(IMAGE_HEADERS
    mat.h
    operations.h
)

add_library(image ${IMAGE_SOURCES} ${IMAGE_HEADERS})

target_include_directories(image PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link OpenMP
find_package(OpenMP REQUIRED)
target_link_libraries(image PUBLIC OpenMP::OpenMP_CXX)

# Link opencv
find_package(OpenCV REQUIRED)
target_link_libraries(image PUBLIC ${OpenCV_LIBS})
