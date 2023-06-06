#include "../DirectionalLight.hpp"

#include "Render/Scene.h"

DirectionalLight::DirectionalLight(const Vector3d& direction, const Vector3d& color, float intensity)
    : Light{ color, intensity }, m_Direction{ direction }, m_RealColor{ m_Color * m_Intensity }
{}

Vector3d DirectionalLight::HandleLight(const Intersection& intersection) const noexcept(false)
{
    const Vector3d& normal = intersection.Normal;

    const float diffuseFactor = normal.Dot(m_Direction);

    if (diffuseFactor < 0.0f)
    {
        return Vector3d{ 0.f };
    }

    return m_RealColor * diffuseFactor;
}

bool DirectionalLight::IsInShadow(const Intersection& intersection, const Scene& scene) const noexcept
{
    Ray shadowRay(intersection.IntersectionPoint, -m_Direction);

    return scene.CheckAnyIntersection(shadowRay, intersection);
}