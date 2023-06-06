#include "../AmbientLight.hpp"

AmbientLight::AmbientLight(const Vector3d& color, float intensity)
	: Light{ color, intensity }, m_HandleResult{ m_Color * m_Intensity }
{}

Vector3d AmbientLight::HandleLight(const Intersection& intersection) const noexcept(false)
{
	return m_HandleResult;
}