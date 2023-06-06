#pragma once
#include "Intersectable.h"
#include "Triangle.hpp"
#include "../Primitives/Vector3d.hpp"
#include <vector>
#include <algorithm>
#include <memory>

class Vector3d;
//
//class CheckIntersectable
//{
//	virtual bool Intersected(const Ray& ray) const = 0;
//};

class Triangle;

class AABB3 : public Intersectable
{
private:
	Vector3d m_Min;
	Vector3d m_Max;
public:

	AABB3();

	AABB3(const Vector3d& min, const Vector3d& max);

	bool Intersected(const Ray& ray) const override;

	const Vector3d& GetMin() { return m_Min; };

	const Vector3d& GetMax() { return m_Max; };

	//std::vector<AABB3> Divide();
	AABB3 Divide();

	Vector3d GetSize() { return m_Max - m_Min; }

	Vector3d GetDividingVector(); 
	
	void operator += (const AABB3& box);

	bool Contains(const Vector3d& point);	

	bool Contains(const Triangle& triangle);

	virtual std::optional<Intersection> IntersectedWithRay(const Ray& ray, float* parametr = nullptr) const noexcept { return std::nullopt; }
};