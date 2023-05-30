#pragma once

#include <optional>

#include "Geometry/Primitives/Ray.hpp"

struct Intersection
{
	Point3d IntersectionPoint;
	Vector3d Normal;
};

class Intersectable abstract
{
public:
	virtual std::optional<Intersection> IntersectedWithRay(const Ray& ray, float* parametr = nullptr) const noexcept = 0;
};

