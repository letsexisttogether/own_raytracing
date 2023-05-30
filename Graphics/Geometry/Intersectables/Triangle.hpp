#pragma once 

#include "Intersectable.h"
#include "Geometry/Primitives/Point3d.hpp"

class Triangle : public Intersectable
{
public:
	Triangle(const Vector3d& v0, const Vector3d& v1, const Vector3d& v2);
	Triangle(const Triangle&) = default;
	Triangle(Triangle&&) = default;

	~Triangle() = default;

	std::optional<Intersection> IntersectedWithRay(const Ray& ray, float* parametr = nullptr) const noexcept override;

	inline const Vector3d& GetV0() const noexcept { return m_V0; }
	inline const Vector3d& GetV1() const noexcept { return m_V1; }
	inline const Vector3d& GetV2() const noexcept { return m_V2; }

	Triangle& operator = (const Triangle&) = delete;
	Triangle& operator = (Triangle&&) = delete;

private:	
	const Point3d m_V0;
	const Point3d m_V1;
	const Point3d m_V2;
};