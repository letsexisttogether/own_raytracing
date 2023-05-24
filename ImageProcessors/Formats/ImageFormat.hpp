#pragma once

#include <vector>
#include <cstddef>

class ImageFormat
{
public:
	using ResolutionType = std::uint32_t;

public:
	ResolutionType Width;
	ResolutionType Height;

	std::vector<std::byte> Data;
};	