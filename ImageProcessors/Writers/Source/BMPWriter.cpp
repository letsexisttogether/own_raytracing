#include "../BMPWriter.hpp"

#include <fstream>

BMPWriter::BMPWriter(const BMP& bmp, const std::filesystem::path& path)
	: Writer<BMP>(bmp, path)
{}

void BMPWriter::Write() const noexcept(false)
{
	BMP bmp_new = this->m_FormatedStruct;

	bmp_new.addPadding();
	std::ofstream outfile(m_Path, std::ios::binary);

	outfile.write(reinterpret_cast<const char*>(&m_FormatedStruct.Header[0]), sizeof(char));
	outfile.write(reinterpret_cast<const char*>(&m_FormatedStruct.Header[1]), sizeof(char));

	outfile.write(reinterpret_cast<const char*>(&m_FormatedStruct.FileSize), sizeof(std::uint32_t));

	outfile.write(reinterpret_cast<const char*>(&m_FormatedStruct.Reserved1), sizeof(std::uint16_t));
	outfile.write(reinterpret_cast<const char*>(&m_FormatedStruct.Reserved2), sizeof(std::uint16_t));

	outfile.write(reinterpret_cast<const char*>(&m_FormatedStruct.PixelArrayOffset), sizeof(std::uint32_t));

	outfile.write(reinterpret_cast<const char*>(&m_FormatedStruct.HeaderSize), sizeof(std::uint32_t));

	outfile.write(reinterpret_cast<const char*>(&m_FormatedStruct.Width), sizeof(std::uint32_t));
	outfile.write(reinterpret_cast<const char*>(&m_FormatedStruct.Height), sizeof(std::uint32_t));

	outfile.write(reinterpret_cast<const char*>(&m_FormatedStruct.Planes), sizeof(std::uint16_t));
	outfile.write(reinterpret_cast<const char*>(&m_FormatedStruct.BitsPerPixel), sizeof(std::uint16_t));

	outfile.write(reinterpret_cast<const char*>(&m_FormatedStruct.Compression), sizeof(std::uint32_t));
	outfile.write(reinterpret_cast<const char*>(&m_FormatedStruct.ImageSize), sizeof(std::uint32_t));
	outfile.write(reinterpret_cast<const char*>(&m_FormatedStruct.HorizontalResolution), sizeof(std::uint32_t));
	outfile.write(reinterpret_cast<const char*>(&m_FormatedStruct.VerticalResolution), sizeof(std::uint32_t));
	outfile.write(reinterpret_cast<const char*>(&m_FormatedStruct.ColorsUsed), sizeof(std::uint32_t));
	outfile.write(reinterpret_cast<const char*>(&m_FormatedStruct.ImportantColors), sizeof(std::uint32_t));


	outfile.write(reinterpret_cast<const char*>(bmp_new.Data.data()), sizeof(std::byte) * bmp_new.Data.size());

	outfile.close();
}