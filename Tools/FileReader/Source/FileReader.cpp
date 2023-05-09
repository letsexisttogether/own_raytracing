#include "../FileReader.hpp"

#include <iostream>
#include <fstream>

FileReader::FileReader(const std::filesystem::path& path)
	: m_FilePath{ path }
{}

std::vector<std::byte> FileReader::ReadFile() const noexcept
{
	std::vector<std::byte> fileContent{};

	if (!CheckFile())
	{
		return fileContent;
	}


	std::ifstream infile(m_FilePath, std::ios::binary);

	infile.seekg(0, std::ios::end);
	auto fileSize = infile.tellg();
	infile.seekg(0, std::ios::beg);

	fileContent.resize(fileSize);

	infile.read(reinterpret_cast<char*>(fileContent.data()), fileSize);

	infile.close();

	return fileContent;
}

bool FileReader::CheckFile() const noexcept
{
	if (!std::filesystem::exists(m_FilePath))
	{
		std::cerr << "Path " << m_FilePath << " does not exist." << std::endl;
		return false;
	}

	return true;
}
