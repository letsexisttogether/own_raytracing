#include "../PPMConverter.hpp"

PPM PPMConverter::Convert(const PPM& ppm) const noexcept
{
	return ppm;
}

PPM PPMConverter::Convert(const BMP32& bmp) const noexcept
{
	return PPM();
}
