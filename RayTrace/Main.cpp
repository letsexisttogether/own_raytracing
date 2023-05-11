#include <iostream>

#include <fstream>
#include <string>

#include "FileReader/FileReader.hpp"

#include "Converters/PPMConverter.hpp"
#include "Readers/BMPReader.hpp"
#include "Writers/PPMWriter.hpp"

int32_t main(int argc, const char* argv[])
{
    FileReader reader{ "shapes.bmp" };
    
    BMPReader bmpReader{ std::move(reader.ReadFile()) };
    bmpReader.Read();
    const BMP bmp{ bmpReader.GetFormatedStruct() };

    PPMConverter converter{};
    const PPM ppm = converter.Convert(bmp);

    PPMWriter ppmWriter{ ppm, "new_file.ppm"};
    ppmWriter.Write();

    return EXIT_SUCCESS;
}