#include <iostream>

#include <fstream>
#include <string>

#include "FileReader/FileReader.hpp"

#include "Readers/PPMReader.hpp"
#include "Readers/BMPReader.hpp"

#include "Writers/PPMWriter.hpp"
#include "Writers/BMPWriter.hpp"

int32_t main(int argc, const char* argv[])
{   
    try
    {
        FileReader bytesReader{ "sample_bmp.bmp" };

        Reader* imageReader = new BMPReader{ std::move(bytesReader.ReadFile()) };

        const ImageFormat image = imageReader->Read();

        Writer* imageWrite = new BMPWriter{ image, "some_new_experience.ppm" };
        imageWrite->Write();
    }
    catch (const std::exception& exp)
    {
        std::cerr << exp.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}