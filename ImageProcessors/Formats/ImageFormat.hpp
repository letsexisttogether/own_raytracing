#pragma once

#include <vector>
#include <cstddef>

class ImageFormat
{
public:
	virtual ~ImageFormat() = 0 {}

	inline std::vector<std::vector<std::byte>>& GetData() noexcept { return m_DataMatrix; }
	inline const std::vector<std::vector<std::byte>>& GetData() const noexcept { return m_DataMatrix; }

	virtual void CheckHeader() const noexcept(false) = 0;

protected: 
	std::vector<std::vector<std::byte>> m_DataMatrix{};
};	