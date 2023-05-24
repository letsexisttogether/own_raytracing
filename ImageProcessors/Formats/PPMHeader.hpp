#pragma once

struct PPMHeader
{
	std::string Format{ "P3" };
	ImageFormat::ResolutionType Width{ 0 };
	ImageFormat::ResolutionType Height{ 0 };
	std::uint16_t PixelMaxValue{ 255 };
};