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
	converted.HorizontalResolution = 0;
	converted.VerticalResolution = 0;
	/*converted.HorizontalResolution = 11811;
	converted.VerticalResolution = 11811;*/
	converted.ColorsUsed = 0;
	converted.ImportantColors = 0;

	converted.FileSize = converted.PixelArrayOffset + converted.ImageSize;


	for (const auto& byteArray : ppm.GetData())
	{
		for (const std::byte& byte : byteArray)
		{
			converted.Data.push_back(static_cast<std::uint8_t>(byte));
		}
	}

	converted.AddPadding();

	/*long size = 4 * converted.Height * converted.Width;
	for (long i = 0; i < size; i++)
	{
		converted.Data.push_back(ppm.Data[i]);
	}*/	

	return converted;
}

BMP BMP32Converter::Convert(const BMP& bmp) const noexcept
{
	BMP bmp_new = bmp;

	bmp_new.AddPadding();
	return bmp_new;
}
