#pragma once

#include "Reader.hpp"
#include "Formats/PPM.hpp"

class PPMReader : public Reader<PPM>
{
public:
	PPMReader(std::vector<std::byte>&& bytes);

	virtual ~PPMReader() override = default;

	virtual void Read() noexcept(false) override;
};
