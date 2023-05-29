#pragma once

#include "Writer.hpp"

class __declspec(dllexport) BMPWriter : public Writer
{
public:
	BMPWriter(const std::filesystem::path& path);

	~BMPWriter() override = default;

	void Write(const ImageFormat& image) const noexcept override;

private:
	void WriteDataWithPadding(const ImageFormat& image, std::ofstream& file) const noexcept;
};