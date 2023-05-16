#include "../BMPReader.hpp"
#include <iostream>

BMPReader::BMPReader(std::vector<std::byte>&& bytes) noexcept
	: Reader<BMP>(std::move(bytes))
{}

void BMPReader::Read() noexcept(false)
{
	m_UnformattedStruct.Header[0] = *(unsigned char*)&m_Bytes[0];
	m_UnformattedStruct.Header[1] = *(unsigned char*)&m_Bytes[1];

	//m_UnformattedStruct.FileSize = *(std::uint32_t*)&m_Bytes[2]; //changed at the end	

	m_UnformattedStruct.Reserved1 = *(std::uint16_t*)&m_Bytes[6];
	m_UnformattedStruct.Reserved2 = *(std::uint16_t*)&m_Bytes[8];

	//m_UnformattedStruct.PixelArrayOffset = *(std::uint32_t*)&m_Bytes[10]; //changed
	m_UnformattedStruct.PixelArrayOffset = 54; //changed to 54

	m_UnformattedStruct.HeaderSize = *(std::uint32_t*)&m_Bytes[14]; //changed
	m_UnformattedStruct.HeaderSize = 40; //changed

	m_UnformattedStruct.Width = *(std::uint32_t*)&m_Bytes[18];
	m_UnformattedStruct.Height = *(std::uint32_t*)&m_Bytes[22];

	m_UnformattedStruct.Planes = *(std::uint16_t*)&m_Bytes[26];
	//m_UnformattedStruct.BitsPerPixel = *(std::uint16_t*)&m_Bytes[28]; // =24
	m_UnformattedStruct.BitsPerPixel = 32; // =24

	//m_UnformattedStruct.Compression = *(std::uint32_t*)&m_Bytes[30];
	m_UnformattedStruct.Compression = 0;
	m_UnformattedStruct.ImageSize = *(std::uint32_t*)&m_Bytes[34];
	m_UnformattedStruct.HorizontalResolution = *(std::uint32_t*)&m_Bytes[38];
	m_UnformattedStruct.VerticalResolution = *(std::uint32_t*)&m_Bytes[42];
	m_UnformattedStruct.ColorsUsed = *(std::uint32_t*)&m_Bytes[46];
	m_UnformattedStruct.ImportantColors = *(std::uint32_t*)&m_Bytes[50];


	for (auto byte = m_Bytes.begin() + m_UnformattedStruct.PixelArrayOffset; byte != m_Bytes.end(); ++byte)
	{
		m_UnformattedStruct.Data.push_back(static_cast<std::uint8_t>(*byte));
	}

	m_UnformattedStruct.removePadding();

	m_UnformattedStruct.FileSize = 40 + m_UnformattedStruct.ImageSize; //changed


}