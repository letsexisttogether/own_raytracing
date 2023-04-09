#pragma once

#include "Converter.hpp"

class BMP32Converter : public Converter<BMP32>
{
public:
	~BMP32Converter() override = default;

	BMP32 Convert(const PPM& ppm) const noexcept override;
	BMP32 Convert(const BMP32& bmp) const noexcept override;
};