#pragma once

#include <filesystem>

#include "Formats/ImageFormat.hpp"

class Writer
{
public:
	Writer(const ImageFormat& formatedStruct, const std::filesystem::path& path, const std::string& allowedFormat)
		: m_Image{ formatedStruct }, m_Path{ path }, m_AllowedFormat{ allowedFormat }
	{}

	virtual ~Writer() = 0 {};

	virtual void Write() noexcept = 0;

	const std::string& GetAllowedFormat() const noexcept { return m_AllowedFormat; }

protected:
	const ImageFormat& m_Image;
	std::filesystem::path m_Path;

private:
	const std::string m_AllowedFormat;
};