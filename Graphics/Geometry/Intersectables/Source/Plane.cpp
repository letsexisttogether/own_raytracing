#include "../Plane.hpp"

#include <cmath>



Plane::Plane(const Vector3d& origin, const Vector3d& normal)
	: m_Origin{ origin }, m_Normal{ normal }
{}

std::optional<Intersection> Plane::IntersectedWithRay(const Ray & ray, float* parametr) const noexcept
{
    if (!parametr)
    {
        float tempVal = 3.f;
        parametr = &tempVal;
    }

    Vector3d normal = this->GetNormal();
    Vector3d direction = ray.GetDirection();
    Vector3d origin = ray.GetOrigin();
    Vector3d center = this->GetOrigin();

    // �������� �� ����������������� �������
    float dot = normal.Dot(direction);
    if (fabs(dot) < 0.0001f) return std::nullopt;

    // ��������� parametr �� ���������, �� ������������ ����� � ��������
    *parametr = normal.Dot(center - origin) / dot;
    if (*parametr < 0.f) return std::nullopt;

    return std::optional<Intersection>({ origin + (direction * (*parametr)), m_Normal });
}

Vector3d Plane::GetNormal(Vector3d intersectionPoint) const noexcept
{
    return this->m_Normal;
}

