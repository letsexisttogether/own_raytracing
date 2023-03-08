#include "../Disk.hpp"

Disk::Disk(const Plane& plane, const float radius)
	: m_Plane{ plane }, m_Radius{ radius }
{}

std::optional<Vector3d> Disk::IntersectedWithRay(const Ray& ray, float* parametr = nullptr) const noexcept
{
    float t;

    /*if (!I_WP.IntersectedWithRay(disk.GetPlane(), ray, &t))
        return false;*/
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
        return { intersectionPoint };
    }
    return std::nullopt;
}
