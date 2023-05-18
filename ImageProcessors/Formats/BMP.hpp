#pragma once

#include "ImageFormat.hpp"

class BMP : public ImageFormat
{
public:
    void CheckHeader() const noexcept(false) override;

    void AddPadding() noexcept;
    void RemovePadding() noexcept;

public:
    struct RGBTriple
    {
        uint8_t Blue;
        uint8_t Green;
        uint8_t Red;
    };

public:
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
};