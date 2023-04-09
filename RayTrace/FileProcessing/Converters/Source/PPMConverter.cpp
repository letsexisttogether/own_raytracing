#include "../PPMConverter.hpp"

PPM PPMConverter::Convert(const PPM& ppm) const noexcept
{
	return ppm;
}

PPM PPMConverter::Convert(const BMP& bmp) const noexcept
{
	return PPM();
}
