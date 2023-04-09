#include "../BMPReader.hpp"

BMPReader::BMPReader(std::vector<std::byte>&& bytes)
	: Reader<BMP>(std::move(bytes))
{}

void BMPReader::Read() noexcept(false)
{
}

bool BMPReader::ReadHeader() noexcept
{
	return false;
}

bool BMPReader::ReadContent() noexcept
{
	return false;
}
