#include <iostream>
#include <fstream>
#include <string>

#include "FileProcessing/Readers/FileReader.hpp"

int main()
{
    FileReader reader{ "file.ppm" };

    const auto result = reader.ReadFile();

    for (const auto byte : result)
    {
        const char smb = static_cast<char>(byte);
        std::cout << smb;
    }

    std::cout << "\nThe size is " << result.size() << std::endl;

    std::cin.get();

    return 0;
}