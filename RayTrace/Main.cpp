#include <iostream>

#include <fstream>
#include <string>

#include "FileReader/FileReader.hpp"

#include "Converters/PPMConverter.hpp"
#include "Converters/BMP32Converter.hpp"
#include "Readers/BMPReader.hpp"
#include "Readers/PPMReader.hpp"
#include "Writers/PPMWriter.hpp"
#include "Writers/BMPWriter.hpp"

int32_t main(int argc, const char* argv[])
{
    FileReader reader1{ "shapes.bmp" };
    FileReader reader{ "new_test.ppm" };
    
    BMPReader bmpReader{ std::move(reader1.ReadFile()) };
    bmpReader.Read();
    const BMP bmp{ bmpReader.GetFormatedStruct() };

    PPMReader ppmReader{ std::move(reader.ReadFile()) };
    ppmReader.Read();
    const PPM ppm{ ppmReader.GetFormatedStruct() };

    /*PPMConverter converter{};
    const PPM ppm = converter.Convert(bmp);*/

    BMP32Converter converter{};
    const BMP bmp2 = converter.Convert(ppm); 

    /*PPMWriter ppmWriter{ ppm, "new_test.ppm"};
    ppmWriter.Write();*/

    BMPWriter bmpWriter{ bmp2, "ppm_to_bmp.bmp" };
    bmpWriter.Write();

    return EXIT_SUCCESS;
}