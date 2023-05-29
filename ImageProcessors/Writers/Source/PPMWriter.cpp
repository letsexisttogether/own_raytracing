#include "../PPMWriter.hpp"

#include <fstream>

#include "Formats/PPMHeader.hpp"

PPMWriter::PPMWriter(const std::filesystem::path& path)
	: Writer{ path, "PPM" }
{}

void PPMWriter::Write(const ImageFormat& image) const noexcept
{
    std::ofstream out{ m_Path };

	PPMHeader header;

	out.write(header.Format.c_str(), 2) << '\n';

	out << image.Width << ' ' << image.Height << ' ' << header.PixelMaxValue << '\n';

	const auto& data = image.Data;
	for (std::size_t i = 0; i < data.size() - 2; i += 3)
	{
		out << static_cast<std::uint16_t>(data[i]) << ' '
			<< static_cast<std::uint16_t>(data[i + 1]) << ' '
			<< static_cast<std::uint16_t>(data[i + 2]);

		if (!((i / 3 + 1) % image.Width))
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

extern "C" __declspec(dllexport) Writer* CreateWriter(const std::filesystem::path& path)
{
	return new PPMWriter{ path };
}
 