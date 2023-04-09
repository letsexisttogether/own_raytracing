#pragma once

#include "Reader.hpp"
#include "../Formats/BMP.hpp"

class BMPReader : Reader<BMP>
{
public:
	BMPReader(std::vector<std::byte>&& bytes);

	virtual ~BMPReader() override = default;

	virtual void Read() noexcept(false) override;

protected:
	virtual bool ReadHeader() noexcept override;
	virtual bool ReadContent() noexcept override;

protected:
	BMP m_UnformatedStruct;
	std::vector<std::byte> m_Bytes;
};