#pragma once

#include "Converter.hpp"

class BMP32Converter : public Converter<BMP>
{
public:
	~BMP32Converter() override = default;

	BMP Convert(const PPM& ppm) const noexcept override;
	BMP Convert(const BMP& bmp) const noexcept override;
};