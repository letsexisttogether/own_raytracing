file(GLOB_RECURSE CPP_SOURCES *.cpp)

add_library(ImageFabrics STATIC ${CPP_SOURCES})
	
target_include_directories(ImageFabrics PUBLIC ${CMAKE_SOURCE_DIR}/ImageProcessors)
target_include_directories(ImageFabrics PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})