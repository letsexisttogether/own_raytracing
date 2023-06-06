file(GLOB_RECURSE CPP_SOURCES *.cpp)

add_library(Graphics STATIC ${CPP_SOURCES} "Geometry/Intersectables/AABB3.hpp" "Geometry/Intersectables/Source/AABB3.cpp" "Geometry/Intersectables/BVH.hpp" "Geometry/Intersectables/Source/BVH.cpp")

target_include_directories(Graphics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Graphics PUBLIC ${CMAKE_SOURCE_DIR}/ImageProcessors)