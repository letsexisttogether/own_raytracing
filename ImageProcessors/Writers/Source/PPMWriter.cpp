#include "../PPMWriter.hpp"

#include <fstream>

PPMWriter::PPMWriter(const PPM& ppm, const std::filesystem::path& path)
    : Writer<PPM>(ppm, path)
{}

void PPMWriter::Write() const noexcept(false)
{
    std::ofstream out{ m_Path };

	out.write(m_FormatedStruct.Format, 2) << '\n';
	
	for (const auto& comment : m_FormatedStruct.Comments)
	{
		out << '#' << comment << '\n';
	}

	out << m_FormatedStruct.Width << ' ' << m_FormatedStruct.Height << ' ' << m_FormatedStruct.PixelMaxValue << '\n';

	const auto& data = m_FormatedStruct.GetData();
	for (std::size_t i = 0; i < data.size(); ++i)
	{
		const auto& currentDataArray = data[i];
		for (std::size_t j = 0; j < currentDataArray.size() - 2; j += 3)
		{
			out << static_cast<std::uint16_t>(currentDataArray[j]) << ' '
				<< static_cast<std::uint16_t>(currentDataArray[j + 1]) << ' '
				<< static_cast<std::uint16_t>(currentDataArray[j + 2]);

			if (!((j / 3 + 1) % m_FormatedStruct.Width))
			{
				out << '\n';
			}
			else
			{
				out << "   ";
			}
		}
	}
	
	out.close();
}
