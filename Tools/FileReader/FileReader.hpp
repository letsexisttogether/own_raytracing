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

	std::vector<std::byte> ReadFile() const noexcept(false);

	inline const std::filesystem::path& GetFilePath() const noexcept { return m_FilePath; }

	FileReader& operator = (const FileReader&) = default;
	FileReader& operator = (FileReader&&) = default;

private:
	void CheckFile() const noexcept(false);

private:
	std::filesystem::path m_FilePath;
};