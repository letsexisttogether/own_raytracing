file(GLOB_RECURSE CPP_SOURCES *.cpp)

add_library(Render STATIC ${CPP_SOURCES})

target_link_libraries(Render Geometry)

target_include_directories(Render PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})