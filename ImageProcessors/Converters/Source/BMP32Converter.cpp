#include "../BMP32Converter.hpp"

BMP BMP32Converter::Convert(const PPM& ppm) const noexcept
{
	BMP converted;
	converted.Header[0] = 'B';
	converted.Header[1] = 'M';

	converted.Reserved1 = 0;
	converted.Reserved2 = 0;

	converted.PixelArrayOffset = 54; 
	converted.HeaderSize = 40; 

	converted.Width = ppm.Width;
	converted.Height = ppm.Height;

	converted.Planes = 1;

	converted.BitsPerPixel = 32;

	converted.Compression = 0;
	converted.ImageSize = ppm.Width * ppm.Height * 4;
	/*converted.HorizontalResolution = 0;
	converted.VerticalResolution = 0;*/
	converted.HorizontalResolution = 11811;
	converted.VerticalResolution = 11811;
	converted.ColorsUsed = 0;
	converted.ImportantColors = 0;

	converted.FileSize = 40 + converted.ImageSize;

	for (const std::uint8_t& byte : ppm.Data)
	{
		converted.Data.push_back(byte);
	}

	return converted;
}

BMP BMP32Converter::Convert(const BMP& bmp) const noexcept
{
	return bmp;
}
