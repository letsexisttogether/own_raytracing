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
    FileReader reader1{ "peepo_cry.bmp" };
    /*FileReader reader{ "sample.ppm" };*/
    
    BMPReader bmpReader{ std::move(reader1.ReadFile()) };
    bmpReader.Read();
    const BMP bmp{ bmpReader.GetFormatedStruct() };

    /*PPMReader ppmReader{ std::move(reader.ReadFile()) };
    ppmReader.Read();
    const PPM ppm{ ppmReader.GetFormatedStruct() };*/

    /*PPMConverter converter{};
    const PPM ppm2 = converter.Convert(ppm);*/

    BMP32Converter converter{};
    const BMP bmp2 = converter.Convert(bmp); 

    /*PPMWriter ppmWriter{ ppm2, "sample_new.ppm"};
    ppmWriter.Write();*/

    BMPWriter bmpWriter{ bmp2, "peepo.bmp" };
    bmpWriter.Write();

    return EXIT_SUCCESS;
}