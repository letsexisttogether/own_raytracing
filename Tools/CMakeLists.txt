target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE CPP_SOURCES *.cpp)

add_library(Tools STATIC ${CPP_SOURCES})

# set_target_properties(Tools PROPERTIES
#     ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/libraries"
# )
