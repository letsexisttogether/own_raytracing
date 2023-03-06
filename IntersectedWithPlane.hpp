#include "Geometry\Source\Ray.hpp"
#include "Geometry\Source\Plane.hpp"
#include <cmath>

class IntersectedWithPlane
{
public:

    bool IntersectedWithRay(const Plane& plane, const Ray& ray)
    {
        Vector3d normal = plane.GetNormal();
        Vector3d direction = ray.GetDirection();
        Vector3d origin = ray.GetOrigin();
        Vector3d center = plane.GetOrigin();

        // Перевірка на пендендикулярність векторів
        float dot = normal.Dot(direction);
        if (fabs(dot) < 0.0001f) return false;

        // знаходимо параметр t та визначаємо, де перетинається пряма з площиною
        return normal.Dot(origin - center) / dot >= 0;
    }
};
