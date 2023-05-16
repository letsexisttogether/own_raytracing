#pragma once

// Потом переделаешь, здесь многое не нужно
struct BMP
{
    char Header[2]; 
    std::uint32_t FileSize;

    std::uint16_t Reserved1;
    std::uint16_t Reserved2;

    std::uint32_t PixelArrayOffset;
    std::uint32_t HeaderSize;

    std::uint32_t Width;
    std::uint32_t Height;

    std::uint16_t Planes;
    std::uint16_t BitsPerPixel;
    std::uint32_t Compression;
    std::uint32_t ImageSize;
    std::uint32_t HorizontalResolution;
    std::uint32_t VerticalResolution;
    std::uint32_t ColorsUsed;
    std::uint32_t ImportantColors;

    std::vector<std::uint8_t> Data;

    struct RGBTriple {
        uint8_t blue;
        uint8_t green;
        uint8_t red;
    };

    void removePadding() {
        int padding = (4 - (Width * sizeof(std::uint8_t) * 4) % 4) % 4;
        int newWidth = Width * sizeof(std::uint8_t) * 4 + padding;
        long numPixels = Data.size();

        std::vector<std::uint8_t> newPixels;
        newPixels.reserve(numPixels);

        int rowIndex = 0;
        for (long i = 0; i < numPixels; i+=4) {
            newPixels.push_back(Data[i + 2]);
            newPixels.push_back(Data[i + 1]);
            newPixels.push_back(Data[i]);
            /*newPixels.push_back(Data[i]);
            newPixels.push_back(Data[i + 1]);
            newPixels.push_back(Data[i + 2]);*/
            rowIndex++;

            if (rowIndex == Width) {
                // Досягнуто кінця рядка, пропускаємо вирівнювальні байти
                i += padding;
                rowIndex = 0;
            }
        }

        Data = std::move(newPixels);
    }

    void addPadding() {
        int padding = (4 - Width % 4) % 4;
        int newWidth = Width * 4 + padding;
        long numPixels = Data.size();
        int numRows = Height;

        int newNumPixels = numRows * newWidth;

        std::vector<std::uint8_t> newPixels;
        newPixels.reserve(newNumPixels);

        for (int row = 0; row < Height; ++row) {
            int originalIndex = row * Width * 3;
            int newIndex = row * newWidth;

            for (int i = 0; i < Width * 3; i += 3) 
            {
                /*newPixels.push_back(Data[originalIndex++]);
                newPixels.push_back(Data[originalIndex++]);
                newPixels.push_back(Data[originalIndex++]);*/
                newPixels.push_back(Data[originalIndex + 2]);
                newPixels.push_back(Data[originalIndex + 1]);
                newPixels.push_back(Data[originalIndex]);
                originalIndex += 3;
                newPixels.push_back(static_cast <std::uint8_t>(0));
            }

            for (int i = 0; i < padding; ++i) {
                newPixels.push_back(static_cast <std::uint8_t>(0));
                newPixels.push_back(static_cast <std::uint8_t>(0));
                newPixels.push_back(static_cast <std::uint8_t>(0));
                newPixels.push_back(static_cast <std::uint8_t>(0));
            }
        }

        /*for (long i = 0; i < numPixels; i += 3) {
            newPixels.push_back(Data[i]);
            newPixels.push_back(Data[i + 1]);
            newPixels.push_back(Data[i + 2]);
            newPixels.push_back(static_cast <std::uint8_t>(0));            
        }*/

        Data = std::move(newPixels);
    }
};