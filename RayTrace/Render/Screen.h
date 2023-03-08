#pragma once
#include <iostream>
#include <exception>

class Screen
{
private:
	char **m_Pixels;
	uint16_t m_Height;
	uint16_t m_Width;

public:
	Screen() = delete;
	Screen(uint16_t height, uint16_t width)
		: m_Height{ height }, m_Width{ width }
	{
		m_Pixels = new char*[m_Height];

		for (uint16_t i = 0; i < m_Height; ++i)
		{
			m_Pixels[i] = new char[m_Width];
		}
	}

	~Screen()
	{
		for (uint16_t i = 0; i < m_Height; ++i)
		{
			delete[] m_Pixels[i];
		}

		delete[] m_Pixels;
	}

	inline uint16_t GetHeigth() const noexcept { return m_Height; }
	inline uint16_t GetWidth() const noexcept { return m_Width; }

	char& GetPixel(uint16_t height, uint16_t width) noexcept(false)
	{
		if (height >= m_Height || width >= m_Width)
		{
			throw std::exception("Such a pixel is out of the screen");
		}

		return m_Pixels[height][width];
	}

public:
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