#pragma once

#include <utility>
#include <string>

#include "ImageFormat.hpp"

class PPM : ImageFormat 
{
public:
	void CheckHeader() const noexcept(false) override;

public:
	char Format[2];
	
	std::vector<std::string> Comments;
	
	std::uint32_t Width;
	std::uint32_t Height;
	std::uint32_t PixelMaxValue;

	std::vector<std::uint8_t> Data;
};
