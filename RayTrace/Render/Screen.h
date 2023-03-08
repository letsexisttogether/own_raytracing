#pragma once
#include <iostream>
#include <vector>
#include <exception>

class Screen
{
private:
	std::vector<std::vector<char>> m_Pixels;
	uint16_t m_Height;
	uint16_t m_Width;

public:
	Screen() = delete;
	Screen(const Screen& screen) = default;

	Screen(uint16_t height, uint16_t width)
		: m_Height{ height }, m_Width{ width }
	{}

	~Screen() = default;

	inline uint16_t GetHeigth() const noexcept { return m_Height; }
	inline uint16_t GetWidth() const noexcept { return m_Width; }

	char& GetPixel(uint16_t height, uint16_t width) noexcept(false)
	{
		return m_Pixels.at(height).at(width);
	}

	void Print() const noexcept
	{
		for (int i = m_Height - 1; i >= 0; i--)
		{
			for (int j = m_Width - 1; j >= 0; j--)
			{
				std::cout << m_Pixels[i][j];
			}
			std::cout << '\n';
		}
	};
};