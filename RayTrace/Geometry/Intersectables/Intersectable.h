#pragma once

#include <optional>
#include "Geometry/Primitives/Ray.hpp"

class Intersectable abstract
{
public:
	virtual std::optional<Vector3d> IntersectedWithRay(const Ray& ray, float* parametr = nullptr) const noexcept = 0;
	virtual Vector3d GetNormal(Vector3d intersectionPoint) const noexcept = 0;
};

