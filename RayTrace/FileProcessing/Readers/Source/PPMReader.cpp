#include "../PPMReader.hpp"

PPMReader::PPMReader(std::vector<std::byte>&& bytes)
	: Reader<PPM>(std::move(bytes))
{}

void PPMReader::Read() noexcept(false)
{
}

bool PPMReader::ReadHeader() noexcept
{
	return false;
}

bool PPMReader::ReadContent() noexcept
{
	return false;
}
