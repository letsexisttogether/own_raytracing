file(GLOB_RECURSE CPP_SOURCES *.cpp)

add_library(RenderHandlerFabrics STATIC ${CPP_SOURCES})

target_link_libraries(RenderHandlerFabrics PRIVATE Graphics)
target_link_libraries(RenderHandlerFabrics PRIVATE Tools)

target_include_directories(RenderHandlerFabrics PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(RenderHandlerFabrics PRIVATE ${CMAKE_SOURCE_DIR}/Graphics)
target_include_directories(RenderHandlerFabrics PRIVATE ${CMAKE_SOURCE_DIR}/Tools)
target_include_directories(RenderHandlerFabrics PRIVATE ${CMAKE_SOURCE_DIR}/ImageProcessors)