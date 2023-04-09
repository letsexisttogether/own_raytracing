#pragma once

#include <utility>
#include <vector>
#include <string>

struct PPM
{
	char Format[2];
	
	std::vector<std::string> Comments;
	
	std::uint32_t Width;
	std::uint32_t Height;
	std::uint32_t PixelMaxValue;

	std::vector<std::uint8_t> Data;
};
