#include "../PointLight.hpp"

PointLight::PointLight(const Vector3d& position, const Vector3d& color, float intensity)
    : Light{ color, intensity }, m_Position(position)
{}

Vector3d PointLight::HandleLight(const Intersection& intersection) const noexcept(false)
{
    const Vector3d& point = intersection.IntersectionPoint;
    const Vector3d& normal = intersection.Normal;

    const Vector3d lightDirection{ (m_Position - point).Normalize() };

    const float diffuseFactor = normal.Dot(lightDirection);
    
    if (diffuseFactor < 0.f)
    {
        return Vector3d{ 0.f };
    }

    const float distance = (m_Position - point).GetLength();

    const float intensity = (m_Intensity / (distance * distance)) * diffuseFactor;

    return m_Color * intensity;
}