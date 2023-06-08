file(GLOB_RECURSE CPP_SOURCES *.cpp)

add_library(ObjReader STATIC ${CPP_SOURCES})

target_include_directories(ObjReader PRIVATE ${CMAKE_SOURCE_DIR}/Graphics)
