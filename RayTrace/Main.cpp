#include <iostream>
#include <fstream>
#include <string>

#include "FileProcessing/Readers/FileReader.hpp"

// Пример программы без фабрики.
// 
// FileReader reader{ "file_name.ppm" };
// std::unique_ptr<Reader> reader{ new PPMReader{ reader.ReadFile() } };
// reader.ReadeHeader();
// reader.ReadeContent();
// PPM ppm = reader->GetPPM();
// std::unique_ptr<Converter> converter{ new BMP32Converter{} };
// std::unique_ptr<Writer> writer{ new BMP32Converter{ "file_name_2", converter.Convert(ppm) } };

int main()
{
    FileReader reader{ "file.ppm" };

    const auto result = reader.ReadFile();

    for (const auto byte : result)
    {
        const char smb = static_cast<char>(byte);
        std::cout << smb;
    }

    std::cout << "Some commit";

    std::cout << "\nThe size is " << result.size() << std::endl;

    return 0;
}