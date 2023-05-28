file(GLOB_RECURSE CPP_SOURCES *.cpp)

add_library(Geometry STATIC ${CPP_SOURCES})

target_include_directories(Geometry PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})