#pragma once
#include "AABB3.hpp"
#include "Intersectable.h"
#include "Triangle.hpp"
#include "../../Render/Scene.h"
#include <vector>

//static int counter = 0;

class AABB3;
class Intersectable;

class BVHTree : public Intersectable
{
	AABB3 m_Box;
	std::vector<Intersectable*> m_Children;
	std::vector<Triangle> m_Triangles;
public:
	BVHTree(std::vector<Triangle>&& triangles, int depth);
	bool Intersected(const Ray& ray) const override;

	std::optional<Intersection> IntersectedWithRay(const Ray& ray, float* parametr = nullptr) const noexcept override;
};

class BVHLeaf : public Intersectable
{
	AABB3 m_Box;
	std::vector<Triangle> m_Triangles;
	Scene m_Scene;
public:
	BVHLeaf(std::vector<Triangle>&& triangles);

	bool Intersected(const Ray& ray) const override;

	std::optional<Intersection> IntersectedWithRay(const Ray& ray, float* parametr = nullptr) const noexcept override;
};