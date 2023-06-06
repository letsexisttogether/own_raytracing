#pragma once

#include <optional>

#include "Geometry/Primitives/Ray.hpp"

struct Intersection
{
	Vector3d IntersectionPoint;
	Vector3d Normal;
	float Distance = 999999;
};

class Intersectable 
{
public:
	virtual std::optional<Intersection> IntersectedWithRay(const Ray& ray, float* parametr = nullptr) const noexcept = 0;

	virtual bool Intersected(const Ray& ray) const { return false; };

};


inline bool IsNearlyEqual(float a, float b, float epsilon = FLT_EPSILON) {
	return std::abs(a - b) <= epsilon;
}

