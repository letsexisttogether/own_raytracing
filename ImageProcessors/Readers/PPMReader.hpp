#pragma once

#include "Reader.hpp"

class PPMReader : public Reader
{
public:
	PPMReader(std::vector<std::byte>&& bytes);

	~PPMReader() override = default;

	ImageFormat Read() noexcept(false) override;

protected:
	void CheckHeader() const noexcept(false) override;

private:
	struct PPMHeader
	{
		std::string Format; 
		ImageFormat::ResolutionType Width;
		ImageFormat::ResolutionType Height;
		std::uint8_t PixelMaxValue;
	};

private:
	PPMHeader m_Header;
};
