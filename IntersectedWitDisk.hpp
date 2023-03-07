#pragma once

#include "Geometry/Ray.hpp"
#include "Geometry/Disk.hpp"
#include "IntersectedWithPlane.hpp"
#include <cmath>


class IntersectedWithDisk
{
public:

    bool IntersectedWithRay(const Disk& disk, const Ray& ray)
    {
        float t; 

        if (!I_WP.IntersectedWithRay(disk.GetPlane(), ray, &t))
            return false;

        Vector3d normal = disk.GetPlane().GetNormal();
        Vector3d direction = ray.GetDirection();
        Vector3d origin = ray.GetOrigin();
        Vector3d center = disk.GetPlane().GetOrigin();
        float radius = disk.GetRadius();

        // Обчислюємо точку перетину
        Vector3d point = origin + direction * t;

        // Обчислюємо відстань від point до центру диска
        float distance = (point - center).GetLength();

        // Перевіряємо, чи належить точка диску
        return distance <= radius;
    }

private:
    IntersectedWithPlane I_WP;
};
