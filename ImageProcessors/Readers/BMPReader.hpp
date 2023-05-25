#pragma once

#include "Reader.hpp"
#include "Formats/BMPHeader.hpp"

class __declspec(dllexport) BMPReader : public Reader
{
public:
	BMPReader(std::vector<std::byte>&& bytes);

	~BMPReader() override = default;

	virtual ImageFormat Read() noexcept(false) override;

protected:
	void CheckHeader() const noexcept(false) override;

private:
	void ReadDataWithoutPadding(ImageFormat& image) noexcept;

private:
    BMPHeader m_Header;
};