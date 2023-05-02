#include "../PPMWriter.hpp"

#include <fstream>

PPMWriter::PPMWriter(const PPM& ppm, const std::filesystem::path& path)
    : Writer<PPM>(ppm, path)
{}

void PPMWriter::Write() const noexcept(false)
{
    std::ofstream out{ m_Path };

	out.write(m_FormatedStruct.Format, 2) << "\n";
	
	for (const auto& comment : m_FormatedStruct.Comments)
	{
		out << comment << "\n";
	}

	out << m_FormatedStruct.Width << ' ' << m_FormatedStruct.Height << ' ' << m_FormatedStruct.PixelMaxValue << "\n";
	
	for (std::size_t i = 0; i < m_FormatedStruct.Data.size() - 3; i += 3)
	{
		out << static_cast<std::uint16_t>(m_FormatedStruct.Data[i]) << ' '
			<< static_cast<std::uint16_t>(m_FormatedStruct.Data[i + 1]) << ' '
			<< static_cast<std::uint16_t>(m_FormatedStruct.Data[i + 2]) << "  ";

		if (!((i / 3 + 1) % m_FormatedStruct.Width))
		{
			out << "\n";
		}
	}
	
	out.close();
}
