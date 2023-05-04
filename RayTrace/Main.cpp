#include <iostream>
#include <fstream>
#include <string>

#include "FileProcessing/Readers/FileReader.hpp"
#include "FileProcessing/Readers/PPMReader.hpp"
#include "FileProcessing/Writers/PPMWriter.hpp"
#include "FileProcessing/Converters/PPMConverter.hpp"
#include "FileProcessing/Readers/BMPReader.hpp"
#include "FileProcessing/Writers/BMPWriter.hpp"

void PrintPPM(const PPM& ppm)
{
    std::cout << "PPM file includes:\n";

    std::cout << "Comments:\n";

    for (const auto& comment : ppm.Comments)
    {
        std::cout << comment << '\n';
    }

    std::cout << "Height: " << ppm.Height << "Width: " << ppm.Width << "Max per color: \n";
}

int main()
{
    FileReader fileReader{ "file.ppm" };

    PPMReader reader{ fileReader.ReadFile() };
    
    reader.Read();

    PPM formatedStruct{ reader.GetFormatedStruct() };

    PPMWriter writer{ formatedStruct, "new_file.ppm" };
    writer.();
    
    std::cout << "The file has been successfully written";

    return 0;
}