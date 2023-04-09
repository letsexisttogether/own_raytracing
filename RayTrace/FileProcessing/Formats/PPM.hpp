#pragma once

#include <utility>
#include <vector>
#include <string>

struct PPM
{
	char Format[2];
	
	std::vector<std::string> Comments;
	
	std::size_t Width;
	std::size_t Height;
	std::uint8_t PixelMaxValue;

	std::vector<std::uint8_t> Data;
};
