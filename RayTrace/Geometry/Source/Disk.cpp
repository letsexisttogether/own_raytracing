#include "../Disk.hpp"

Disk::Disk(const Plane& plane, const float radius)
	: m_Plane{ plane }, m_Radius{ radius }
{}

bool Disk::IntersectedWithRay(Ray& ray, float* parametr) const
{
    float t;

    /*if (!I_WP.IntersectedWithRay(disk.GetPlane(), ray, &t))
        return false;*/
    if (!this->GetPlane().IntersectedWithRay(ray, &t))
        return false;

    Vector3d normal = this->GetPlane().GetNormal();
    Vector3d direction = ray.GetDirection();
    Vector3d origin = ray.GetOrigin();
    Vector3d center = this->GetPlane().GetOrigin();
    float radius = this->GetRadius();

    // Обчислюємо точку перетину
    Vector3d point = origin + direction * t;

    // Обчислюємо відстань від point до центру диска
    float distance = (point - center).GetLength();

    // Перевіряємо, чи належить точка диску
    return distance <= radius;
}
