file(GLOB_RECURSE CPP_SOURCES *.cpp)

add_library(SceneFabrics STATIC ${CPP_SOURCES})

target_link_libraries(SceneFabrics PRIVATE Graphics)
target_link_libraries(SceneFabrics PRIVATE ObjReader)
target_link_libraries(SceneFabrics PRIVATE Tools)

target_include_directories(SceneFabrics PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(SceneFabrics PRIVATE ${CMAKE_SOURCE_DIR}/Graphics)
target_include_directories(SceneFabrics PRIVATE ${CMAKE_SOURCE_DIR}/ObjReader)
target_include_directories(SceneFabrics PRIVATE ${CMAKE_SOURCE_DIR}/Tools)