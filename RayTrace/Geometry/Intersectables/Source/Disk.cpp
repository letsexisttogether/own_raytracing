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

    // ���������� ����� ��������
    Vector3d intersectionPoint = origin + direction * t;

    // ���������� ������� �� point �� ������ �����
    float distance = (intersectionPoint - center).GetLength();

    // ����������, �� �������� ����� �����

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
