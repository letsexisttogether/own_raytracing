file(GLOB_RECURSE CPP_SOURCES *.cpp)

add_library(Graphics STATIC ${CPP_SOURCES} "Geometry/Primitives/Matrix.hpp" "Geometry/Primitives/Source/Matrix.cpp")

target_include_directories(Graphics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Graphics PUBLIC ${CMAKE_SOURCE_DIR}/ImageProcessors)