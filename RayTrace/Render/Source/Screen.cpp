#include "../Screen.h"
#include <cmath>

//Screen::Screen(uint16_t height, uint16_t width)
//	: m_Height{ height }, m_Width{ width }, 
//	m_Pixels{ m_Height, std::vector<char>(m_Width, ' ') }
//{}
Screen::Screen(uint16_t height, uint16_t width, float distance, const Camera& camera)
	: m_Height{ height }, m_Width{ width }, 
	m_Pixels{ m_Height, std::vector<char>(m_Width, ' ') }, m_Distance(distance)
{
	float length = (camera.GetDirection() * distance).GetLength();
	m_PixelSize = (2.f * tanf(camera.GetFOV() / 2.f) * length) / height;
}

//void Screen::Print() const noexcept
//{
//	for (int i = m_Height - 1; i >= 0; i--)
//	{
//		for (int j = m_Width - 1; j >= 0; j--)
//		{
//			std::cout << m_Pixels[i][j];
//		}
//		std::cout << '\n';
//	}
//
//	std::cout << std::endl;
//};

void Screen::Print() const noexcept
{
	for (int i = m_Height - 1; i >= 0; i--)
	{
		for (int j = 0; j < m_Width; j++)
		{
			std::cout << m_Pixels[i][j];
		}
		std::cout << '\n';
	}

	std::cout << std::endl;
};