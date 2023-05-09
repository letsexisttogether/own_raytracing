#pragma once

#include <filesystem>

template<class _FileType>
class Writer
{
public:
	Writer(const _FileType& formatedStruct, const std::filesystem::path& path)
		: m_FormatedStruct{ formatedStruct }, m_Path{ path }
	{}

	virtual ~Writer() {};

	virtual void Write() const noexcept(false) = 0;

protected:
	_FileType m_FormatedStruct;
	std::filesystem::path m_Path;
};