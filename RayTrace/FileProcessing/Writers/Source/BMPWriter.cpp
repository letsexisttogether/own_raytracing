#include "../BMPWriter.hpp"

BMPWriter::BMPWriter(const BMP& bmp, const std::filesystem::path& path)
	: Writer<BMP>(bmp, path)
{}

void BMPWriter::Write() const noexcept(false)
{
}
