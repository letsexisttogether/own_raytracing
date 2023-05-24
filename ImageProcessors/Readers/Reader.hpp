#pragma once

#include <vector>
#include <string>
#include <cstddef>

#include "Formats/ImageFormat.hpp"

class Reader
{
public:
	Reader(std::vector<std::byte>&& bytes, const std::string& allowedFomat)
		: m_Bytes{ std::move(bytes) }, m_AllowedFormat{ allowedFomat }
	{}

	virtual ~Reader() = 0 {}

	virtual ImageFormat Read() noexcept(false) = 0;

	inline const std::string& GetAllowedFormat() const noexcept { return m_AllowedFormat; }

protected:
	virtual void CheckHeader() const noexcept(false) = 0;

protected:
	std::vector<std::byte> m_Bytes;

private:
	const std::string m_AllowedFormat;
};