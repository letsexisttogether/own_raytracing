#pragma once
#include <iostream>
#include <vector>
#include <exception>

class Screen
{
private:
	uint16_t m_Height;
	uint16_t m_Width;
	std::vector<std::vector<char>> m_Pixels;

public:
	Screen() = delete;
	Screen(const Screen&) = default;

	Screen(uint16_t height, uint16_t width);

	~Screen() = default;

	inline uint16_t GetHeigth() const noexcept { return m_Height; }
	inline uint16_t GetWidth() const noexcept { return m_Width; }

	inline char& GetPixel(uint16_t height, uint16_t width) noexcept(false) { return m_Pixels.at(height).at(width); }

	void Print() const noexcept;
};