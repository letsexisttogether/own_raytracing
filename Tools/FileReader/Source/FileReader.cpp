#include "../FileReader.hpp"

#include <iostream>
#include <fstream>
#include <stdexcept>

FileReader::FileReader(const std::filesystem::path& path)
	: m_FilePath{ path }
{
	CheckFile();
}

std::vector<std::byte> FileReader::ReadFile() const noexcept
{
	std::vector<std::byte> fileContent{};

	std::ifstream infile(m_FilePath, std::ios::binary);

	infile.seekg(0, std::ios::end);
	auto fileSize = infile.tellg();
	infile.seekg(0, std::ios::beg);

	fileContent.resize(fileSize);

	infile.read(reinterpret_cast<char*>(fileContent.data()), fileSize);

	infile.close();

	return fileContent;
}

void FileReader::CheckFile() const noexcept(false)
{
	if (!std::filesystem::exists(m_FilePath))
	{
		throw std::invalid_argument{ "The file does not exist" };
	}
}
