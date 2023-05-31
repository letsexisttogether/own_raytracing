#include "../Screen.h"

#include <cmath>

Screen::Screen(const Resolution height, const Resolution width, const float distance, const Camera& camera)
	: m_Height{ height }, m_Width{ width }, m_Distance(distance)
{
	const float length = (camera.GetDirection().Normalize() * distance).GetLength();
	m_PixelSize = (2.f * tanf(camera.GetFOV() / 2.f) * length) / height;
}
