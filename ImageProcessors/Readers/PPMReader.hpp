#pragma once

#include "Reader.hpp"
#include "Formats/PPMHeader.hpp"

class __declspec(dllexport) PPMReader : public Reader
{
public:
	PPMReader(std::vector<std::byte>&& bytes);

	~PPMReader() override = default;

	ImageFormat Read() noexcept(false) override;

protected:
	void CheckHeader() const noexcept(false) override;	

private:
	PPMHeader m_Header;
};
