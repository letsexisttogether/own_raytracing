#pragma once

#include "../Formats/PPM.hpp"
#include "../Formats/BMP.hpp"

template<class _FileType>
class Converter
{
public:
	virtual ~Converter() {}

	virtual _FileType Convert(const PPM& ppm) const noexcept = 0;
	virtual _FileType Convert(const BMP& bmp) const noexcept = 0;
};