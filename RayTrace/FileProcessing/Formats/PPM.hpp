#pragma once

#include <utility>
#include <vector>
#include <string>

struct PPM
{
	char Format[2];
	
	std::vector<std::string> Comments;
	
	std::uint8_t Width;
	std::uint8_t Height;
	std::uint8_t PixelMaxValue;

	std::vector<std::uint8_t> Data;
};
