#pragma once 

#include <filesystem>
#include <string>
#include <vector>
#include <cstddef>

class FileReader
{
public:
	FileReader() = delete;
	FileReader(const FileReader&) = default;
	FileReader(FileReader&&) = default;

	FileReader(const std::filesystem::path& path);

	~FileReader() = default;

	std::vector<std::byte> ReadFile() const noexcept;

	FileReader& operator = (const FileReader&) = default;
	FileReader& operator = (FileReader&&) = default;

private:
	bool CheckFile() const noexcept;

private:
	std::filesystem::path m_FilePath;
};