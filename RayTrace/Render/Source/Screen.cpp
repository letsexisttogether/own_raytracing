#include "../Screen.h"

Screen::Screen(uint16_t height, uint16_t width)
	: m_Height{ height }, m_Width{ width }, 
	m_Pixels{ m_Height, std::vector<char>(m_Width, ' ') }
{}

void Screen::Print() const noexcept
{
	for (int i = m_Height - 1; i >= 0; i--)
	{
		for (int j = m_Width - 1; j >= 0; j--)
		{
			std::cout << m_Pixels[i][j];
		}
		std::cout << std::endl;
	}
};