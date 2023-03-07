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

        // ���������� ����� ��������
        Vector3d point = origin + direction * t;

        // ���������� ������� �� point �� ������ �����
        float distance = (point - center).GetLength();

        // ����������, �� �������� ����� �����
        return distance <= radius;
    }

private:
    IntersectedWithPlane I_WP;
};
