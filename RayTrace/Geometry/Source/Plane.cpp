#include "../Plane.hpp"
#include <cmath>



Plane::Plane(const Vector3d& origin, const Vector3d& normal)
	: m_Origin{ origin }, m_Normal{ normal }
{}

bool Plane::IntersectedWithRay(Ray& ray, float* parametr) const
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
    if (fabs(dot) < 0.0001f) return false;

    // знаходимо параметр t та визначаЇмо, де перетинаЇтьс€ пр€ма з площиною
    *parametr = normal.Dot(center - origin) / dot;

    return *parametr >= 0;
}
