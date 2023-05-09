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

    for (std::size_t i = 0; i < bmp.Data.size(); i += 3)
    {
        ppm.Data.push_back(static_cast<std::uint8_t>(bmp.Data[i]));
        ppm.Data.push_back(static_cast<std::uint8_t>(bmp.Data[i + 1]));
        ppm.Data.push_back(static_cast<std::uint8_t>(bmp.Data[i + 2]));
    }

    return ppm;
}
