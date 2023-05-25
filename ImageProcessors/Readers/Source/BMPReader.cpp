#include "../BMPReader.hpp"

#include <iostream>
#include <stdexcept>

BMPReader::BMPReader(std::vector<std::byte>&& bytes)
	: Reader(std::move(bytes), "BMP32")
{}

ImageFormat BMPReader::Read() noexcept(false)
{
	m_Header.Format[0] = *(unsigned char*)&m_Bytes[0];
	m_Header.Format[1] = *(unsigned char*)&m_Bytes[1];

	m_Header.FileSize = *(std::uint32_t*)&m_Bytes[2];

	m_Header.Reserved1 = *(std::uint16_t*)&m_Bytes[6];
	m_Header.Reserved2 = *(std::uint16_t*)&m_Bytes[8];

	m_Header.PixelArrayOffset = *(std::uint32_t*)&m_Bytes[10];
	// m_Header.PixelArrayOffset = 54;

	m_Header.HeaderSize = *(std::uint32_t*)&m_Bytes[14]; 
	// m_Header.HeaderSize = 40; 

	m_Header.Width = *(std::uint32_t*)&m_Bytes[18];
	m_Header.Height = *(std::uint32_t*)&m_Bytes[22];

	m_Header.Planes = *(std::uint16_t*)&m_Bytes[26];
	m_Header.BitsPerPixel = *(std::uint16_t*)&m_Bytes[28];

	m_Header.Compression = *(std::uint32_t*)&m_Bytes[30];

	m_Header.ImageSize = *(std::uint32_t*)&m_Bytes[34];
	m_Header.HorizontalResolution = *(std::uint32_t*)&m_Bytes[38];
	m_Header.VerticalResolution = *(std::uint32_t*)&m_Bytes[42];
	m_Header.ColorsUsed = *(std::uint32_t*)&m_Bytes[46];
	m_Header.ImportantColors = *(std::uint32_t*)&m_Bytes[50];

	CheckHeader();

	ImageFormat image = { m_Header.Width, m_Header.Height };
	ReadDataWithoutPadding(image);

	return image;
}

void BMPReader::CheckHeader() const noexcept(false)
{
	BMPHeader header;

	if (m_Header.Format != header.Format)
	{
		throw std::invalid_argument{ "You are trying to open a non-bmp file marked by .bmp extension. " 
			"That is not allowed" };
	}

	if (m_Header.BitsPerPixel != header.BitsPerPixel)
	{
		throw std::invalid_argument{ "You are trying to open BMP" + std::to_string(m_Header.BitsPerPixel) 
			+ ". However, only " + GetAllowedFormat() + " is supported" };
	}

	if (!m_Header.Width || !m_Header.Height)
	{
		throw std::invalid_argument{ "A resolution of an image cannot be 0" };
	}
}

void BMPReader::ReadDataWithoutPadding(ImageFormat& image) noexcept
{
	std::int32_t padding = (4 - (image.Width * sizeof(std::uint8_t) * 4) % 4) % 4;
	std::int32_t newWidth = image.Width * sizeof(std::uint8_t) * 4 + padding;

	for (std::int32_t y = image.Height - 1, rowIndex = 0; y >= 0; --y)
	{
		const ImageFormat::ResolutionType tempY = y * image.Width * 4;
		const ImageFormat::ResolutionType tempWidth = newWidth + y * image.Width * 4;

		for (ImageFormat::ResolutionType i = tempY; i < tempWidth; i += 4)
		{
			const ImageFormat::ResolutionType realIndex = m_Header.PixelArrayOffset + i;

			image.Data.push_back(m_Bytes[realIndex + 2]);
			image.Data.push_back(m_Bytes[realIndex + 1]);
			image.Data.push_back(m_Bytes[realIndex]);
			rowIndex++;

			if (rowIndex == image.Width)
			{
				i += padding;
				rowIndex = 0;
			}
		}
	}
}

extern "C" __declspec(dllexport) Reader* CreateReader(std::vector<std::byte>&& bytes)
{
	return new BMPReader(std::move(bytes));
}

