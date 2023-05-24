#include "../BMPWriter.hpp"

#include <fstream>

#include "Formats/BMPHeader.hpp"

BMPWriter::BMPWriter(const ImageFormat& image, const std::filesystem::path& path)
	: Writer(image, path, "BMP32")
{}

void BMPWriter::Write() noexcept
{
	std::ofstream outfile(m_Path, std::ios::binary);

	BMPHeader header;

	outfile.write(reinterpret_cast<const char*>(&header.Format[0]), sizeof(char));
	outfile.write(reinterpret_cast<const char*>(&header.Format[1]), sizeof(char));

	outfile.write(reinterpret_cast<const char*>(&header.FileSize), sizeof(std::uint32_t));

	outfile.write(reinterpret_cast<const char*>(&header.Reserved1), sizeof(std::uint16_t));
	outfile.write(reinterpret_cast<const char*>(&header.Reserved2), sizeof(std::uint16_t));

	outfile.write(reinterpret_cast<const char*>(&header.PixelArrayOffset), sizeof(std::uint32_t));

	outfile.write(reinterpret_cast<const char*>(&header.HeaderSize), sizeof(std::uint32_t));

	outfile.write(reinterpret_cast<const char*>(&m_Image.Width), sizeof(std::uint32_t));
	outfile.write(reinterpret_cast<const char*>(&m_Image.Height), sizeof(std::uint32_t));

	outfile.write(reinterpret_cast<const char*>(&header.Planes), sizeof(std::uint16_t));
	outfile.write(reinterpret_cast<const char*>(&header.BitsPerPixel), sizeof(std::uint16_t));

	outfile.write(reinterpret_cast<const char*>(&header.Compression), sizeof(std::uint32_t));
	outfile.write(reinterpret_cast<const char*>(&header.ImageSize), sizeof(std::uint32_t));
	outfile.write(reinterpret_cast<const char*>(&header.HorizontalResolution), sizeof(std::uint32_t));
	outfile.write(reinterpret_cast<const char*>(&header.VerticalResolution), sizeof(std::uint32_t));
	outfile.write(reinterpret_cast<const char*>(&header.ColorsUsed), sizeof(std::uint32_t));
	outfile.write(reinterpret_cast<const char*>(&header.ImportantColors), sizeof(std::uint32_t));

	WriteDataWithPadding(outfile);

	outfile.close();
}

void BMPWriter::WriteDataWithPadding(std::ofstream& file) noexcept
{
    std::int32_t padding = (4 - m_Image.Width % 4) % 4;
    std::int32_t newWidth = m_Image.Width * 4 + padding;

    for (std::int32_t y = m_Image.Height - 1; y >= 0; y--)
    {
		const ImageFormat::ResolutionType tempY = y * m_Image.Width * 3;
		const ImageFormat::ResolutionType tempWidth = m_Image.Width * 3 + y * m_Image.Width * 3;
        
		for (std::int32_t i = tempY; i < tempWidth; i += 3)
        {

			for (int32_t j = i + 2; j >= i; --j)
			{
				file.write(reinterpret_cast<const char*>(&m_Image.Data[j]), sizeof(std::byte));
			}
            
			const std::uint8_t zero = 0;
			file.write(reinterpret_cast<const char*>(&zero), sizeof(std::byte));
        }
    }
}
