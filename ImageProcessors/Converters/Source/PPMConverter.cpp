#include "../PPMConverter.hpp"

PPM PPMConverter::Convert(const PPM& ppm) const noexcept
{
	return ppm;
}

PPM PPMConverter::Convert(const BMP& bmp) const noexcept
{
    PPM ppm;

    std::memcpy(ppm.Format, "P3", 2);

    ppm.Width = bmp.Width;
    ppm.Height = bmp.Height;

    ppm.PixelMaxValue = 255;

    for (const std::uint8_t byte : bmp.Data)
    {
        ppm.Data.push_back(byte);
    }

    return ppm;
}
