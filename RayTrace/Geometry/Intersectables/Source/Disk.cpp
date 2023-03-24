#include "../Disk.hpp"

Disk::Disk(const Plane& plane, const float radius)
	: m_Plane{ plane }, m_Radius{ radius }
{}

std::optional<Intersection> Disk::IntersectedWithRay(const Ray& ray, float* parametr) const noexcept
{
    float t;

    if (!this->GetPlane().IntersectedWithRay(ray, &t)) return std::nullopt;

    Vector3d normal = this->GetPlane().GetNormal();
    Vector3d direction = ray.GetDirection();
    Vector3d origin = ray.GetOrigin();
    Vector3d center = this->GetPlane().GetOrigin();
    float radius = this->GetRadius();

    // Обчислюємо точку перетину
    Vector3d intersectionPoint = origin + direction * t;

    // Обчислюємо відстань від point до центру диска
    float distance = (intersectionPoint - center).GetLength();

    // Перевіряємо, чи належить точка диску

    if (distance <= radius)
    {
        //return { intersectionPoint, this->GetPlane().GetNormal()};
        return std::optional<Intersection>({ intersectionPoint, this->GetPlane().GetNormal() });
    }
    return std::nullopt;
}

Vector3d Disk::GetNormal(Vector3d intersectionPoint) const noexcept
{
    return this->GetPlane().GetOrigin();
}
