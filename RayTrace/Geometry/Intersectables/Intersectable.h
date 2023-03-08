#pragma once

#include "Geometry/Primitives/Ray.hpp"

class Intersectable abstract
{
public:
	virtual bool IntersectedWithRay(Ray& ray, float* parametr = nullptr) const =  0;
};