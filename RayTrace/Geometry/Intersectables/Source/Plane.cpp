#include "../Plane.hpp"
#include <cmath>



Plane::Plane(const Vector3d& origin, const Vector3d& normal)
	: m_Origin{ origin }, m_Normal{ normal }
{}

std::optional<Vector3d> Plane::IntersectedWithRay(const Ray & ray, float* parametr) const noexcept
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

    // ѕерев≥рка на пендендикул€рн≥сть вектор≥в
    float dot = normal.Dot(direction);
    if (fabs(dot) < 0.0001f) return std::nullopt;

    // знаходимо parametr та визначаЇмо, де перетинаЇтьс€ пр€ма з площиною
    *parametr = normal.Dot(center - origin) / dot;
    if (*parametr < 0.f) return std::nullopt;

    return { origin + (direction * (*parametr)) };
}

