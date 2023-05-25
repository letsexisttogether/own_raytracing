file(GLOB_RECURSE CPP_SOURCES *.cpp)

add_library(Fabrics STATIC ${CPP_SOURCES})
	
target_include_directories(Fabrics PRIVATE ${CMAKE_SOURCE_DIR}/ImageProcessors)