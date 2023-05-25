set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/plugins)

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

include_directories(${CMAKE_CURRENT_SOURCE_DIR})