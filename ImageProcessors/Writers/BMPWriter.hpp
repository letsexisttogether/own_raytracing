#pragma once

#include "Writer.hpp"
#include "Formats/BMP.hpp"

class BMPWriter : public Writer<BMP>
{
public:
	BMPWriter(const BMP& bmp, const std::filesystem::path& path);

	virtual ~BMPWriter() {};

	virtual void Write() const noexcept(false) override;
};