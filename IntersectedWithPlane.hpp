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

        float dot = normal.Dot(direction);
        if (fabs(dot) < 0.0001f) return false;

        *t = normal.Dot(center - origin) / dot;

        return *t >= 0;
    }
};
