#pragma once

#include "Reader.hpp"
#include "../Formats/PPM.hpp"

class PPMReader : Reader<PPM>
{
public:
	PPMReader(std::vector<std::byte>&& bytes);

	virtual ~PPMReader() override = default;

	virtual void Read() noexcept(false) override;

protected:
	virtual bool ReadHeader() noexcept override;
	virtual bool ReadContent() noexcept override;

protected:
	PPM m_UnformatedStruct;
	std::vector<std::byte> m_Bytes;
};