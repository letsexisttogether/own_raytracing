file(GLOB_RECURSE CPP_SOURCES *.cpp)

add_library(Tools STATIC ${CPP_SOURCES})

target_include_directories(Tools PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})