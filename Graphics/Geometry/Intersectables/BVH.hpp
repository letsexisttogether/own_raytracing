#pragma once

#include <vector>

#include "AABB3.hpp"
#include "Intersectable.h"
#include "Triangle.hpp"

class AABB3;
class Intersectable;

class BVHTree : public Intersectable
{
	AABB3 m_Box;
	std::vector<Intersectable*> m_Children;
	std::vector<Triangle> m_Triangles;

public:
	BVHTree(std::vector<Triangle>&& triangles, int depth);

	std::optional<Intersection> IntersectedWithRay(const Ray& ray, float* parametr = nullptr) const noexcept override;
	bool Intersected(const Ray& ray) const override;
};

class BVHLeaf : public Intersectable
{
	AABB3 m_Box;
	std::vector<Triangle> m_Triangles;

public:
	BVHLeaf(std::vector<Triangle>&& triangles);

	std::optional<Intersection> IntersectedWithRay(const Ray& ray, float* parametr = nullptr) const noexcept override;
	bool Intersected(const Ray& ray) const override;
};