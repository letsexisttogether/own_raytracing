#include "../PPMWriter.hpp"

PPMWriter::PPMWriter(const PPM& ppm, const std::filesystem::path& path)
    : Writer<PPM>(ppm, path)
{}

void PPMWriter::Write() const noexcept(false)
{
    
}
