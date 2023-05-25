#pragma once

#include "Writer.hpp"

class __declspec(dllexport) BMPWriter : public Writer
{
public:
	BMPWriter(const ImageFormat& bmp, const std::filesystem::path& path);

	~BMPWriter() override = default;

	void Write() noexcept override;

private:
	void WriteDataWithPadding(std::ofstream& file) noexcept;
};