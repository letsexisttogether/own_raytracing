#pragma once

#include <optional>
#include "Geometry/Primitives/Ray.hpp"

class Intersectable abstract
{
public:
	virtual std::optional<Vector3d> IntersectedWithRay(const Ray& ray, float* parametr = nullptr) const noexcept = 0;
};

