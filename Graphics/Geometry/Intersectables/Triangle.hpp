#pragma once 

#include "Intersectable.h"

class Triangle : Intersectable
{
public:
	Triangle(const Vector3d& v0, const Vector3d& v1, const Vector3d& v2);
	Triangle(const Triangle&) = default;
	Triangle(Triangle&&) = default;

	~Triangle() = default;

	std::optional<Intersection> IntersectedWithRay(const Ray& ray, float* parametr = nullptr) const noexcept override;

	inline const Vector3d& GetV0() const noexcept { return m_v0 };
	inline const Vector3d& GetV1() const noexcept { return m_v1 };
	inline const Vector3d& GetV2() const noexcept { return m_v2 };

	Triangle& operator = (const Triangle&) = delete;
	Triangle& operator = (Triangle&&) = delete;
private:	
	const Vector3d m_V0;
	const Vector3d m_V1;
	const Vector3d m_V2;
};