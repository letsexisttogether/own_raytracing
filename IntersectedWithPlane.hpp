#pragma once

#include "Geometry\Ray.hpp"
#include "Geometry\Plane.hpp"
#include <cmath>

class IntersectedWithPlane
{
public:

    bool IntersectedWithRay(const Plane& plane, const Ray& ray, float *t) 
    {
        if (!t)
        {
            float tempVal = 3.f;
            t = &tempVal;
        }

        Vector3d normal = plane.GetNormal();
        Vector3d direction = ray.GetDirection();
        Vector3d origin = ray.GetOrigin();
        Vector3d center = plane.GetOrigin();

        // ѕерев≥рка на пендендикул€рн≥сть вектор≥в
        float dot = normal.Dot(direction);
        if (fabs(dot) < 0.0001f) return false;

        // знаходимо параметр t та визначаЇмо, де перетинаЇтьс€ пр€ма з площиною
        *t = normal.Dot(origin - center) / dot;

        return *t >= 0;
    }
};