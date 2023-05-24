#pragma once

struct PPMHeader
{
	std::string Format{ "PM" };
	ImageFormat::ResolutionType Width{ 0 };
	ImageFormat::ResolutionType Height{ 0 };
	std::uint8_t PixelMaxValue{ 255 };
};