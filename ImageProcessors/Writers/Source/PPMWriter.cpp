#include "../PPMWriter.hpp"

#include <fstream>

PPMWriter::PPMWriter(const ImageFormat& image, const std::filesystem::path& path)
	: Writer{ image, path, "P3" }
{}

void PPMWriter::Write() const noexcept(false)
{
    std::ofstream out{ m_Path };

	out.write(GetAllowedFomat().c_str(), 2) << '\n';

	out << m_Image.Width << ' ' << m_Image.Height << ' ' << 255 << '\n';

	const auto& data = m_Image.Data;
	for (std::size_t i = 0; i < data.size() - 2; i += 3)
	{
		out << static_cast<std::uint16_t>(data[i]) << ' '
			<< static_cast<std::uint16_t>(data[i + 1]) << ' '
			<< static_cast<std::uint16_t>(data[i + 2]);

		if (!((i / 3 + 1) % m_Image.Width))
		{
			out << '\n';
		}
		else
		{
			out << "   ";
		}
	}
	
	out.close();
}
