#pragma once

#pragma once

#include "Converter.hpp"

class PPMConverter : public Converter<PPM>
{
public:
	~PPMConverter() override = default;

	PPM Convert(const PPM& ppm) const noexcept override;
	PPM Convert(const BMP32& bmp) const noexcept override;
};