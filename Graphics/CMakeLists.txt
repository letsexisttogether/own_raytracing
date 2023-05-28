file(GLOB_RECURSE CPP_SOURCES *.cpp)

add_library(Graphics STATIC ${CPP_SOURCES})

target_include_directories(Graphics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})