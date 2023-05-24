# Readers
set(ReadersSource Readers/Source)
add_library(Reader.BMP SHARED ${ReadersSource}/BMPReader.cpp)
add_library(Reader.PPM SHARED ${ReadersSource}/PPMReader.cpp)



# Writers
set(WritersSource Writers/Source)
add_library(Writer.BMP SHARED ${WritersSource}/BMPWriter.cpp)
add_library(Writer.PPM SHARED ${WritersSource}/PPMWriter.cpp)