#pragma once

#include <string>

struct BMPHeader
{
    std::string Format{ "BM" };
    std::uint32_t FileSize;

    std::uint16_t Reserved1{ 0 };
    std::uint16_t Reserved2{ 0 };

    std::uint32_t PixelArrayOffset{ 54 };
    std::uint32_t HeaderSize{ 40 };

    std::uint32_t Width{ 0 };
    std::uint32_t Height{ 0 };

    std::uint16_t Planes{ 1 };
    std::uint16_t BitsPerPixel{ 32 };
    std::uint32_t Compression{ 0 };
    std::uint32_t ImageSize{ 0 };
    std::uint32_t HorizontalResolution{ 0 };
    std::uint32_t VerticalResolution{ 0 };
    std::uint32_t ColorsUsed{ 0 };
    std::uint32_t ImportantColors{ 0 };
};