set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Plugins)

# Readers
set(ReadersSource Readers/Source)
add_library(Reader.BMP SHARED ${ReadersSource}/BMPReader.cpp)
add_library(Reader.PPM SHARED ${ReadersSource}/PPMReader.cpp)

# Set the output directory for the Reader.BMP and Reader.PPM DLLs
set_target_properties(Reader.BMP PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/Readers
)
set_target_properties(Reader.PPM PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/Readers
)

# Writers
set(WritersSource Writers/Source)
add_library(Writer.BMP SHARED ${WritersSource}/BMPWriter.cpp)
add_library(Writer.PPM SHARED ${WritersSource}/PPMWriter.cpp)

# Set the output directory for the Writer.BMP and Writer.PPM DLLs
set_target_properties(Writer.BMP PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/Writers
)
set_target_properties(Writer.PPM PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/Writers
)

# Set include directories for Reader.BMP and Reader.PPM
target_include_directories(Reader.BMP PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Reader.PPM PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Set include directories for Writer.BMP and Writer.PPM
target_include_directories(Writer.BMP PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Writer.PPM PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Build targets
add_custom_target(BuildPPM DEPENDS Reader.PPM Writer.PPM)
add_custom_target(BuildBMP DEPENDS Reader.BMP Writer.BMP)