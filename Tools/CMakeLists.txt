file(GLOB_RECURSE CPP_SOURCES *.cpp)

add_library(Tools STATIC ${CPP_SOURCES})
