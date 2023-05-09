#pragma once

#include "Reader.hpp"
#include "Formats/BMP.hpp"

class BMPReader : public Reader<BMP>
{
public:
	BMPReader(std::vector<std::byte>&& bytes) noexcept;

	virtual ~BMPReader() override = default;

	virtual void Read() noexcept(false) override;
};