#pragma once

#include "Intersectable.h"

class Sphere : public Intersectable
{
public:
	Sphere() = delete;
	Sphere(const Point3d& origin, const float radius);

	~Sphere() = default;

	inline const Point3d& GetOrigin() const noexcept { return m_Origin; }
	inline float GetRadius() const noexcept { return m_Radius; } 

	std::optional<Intersection> IntersectedWithRay(const Ray& ray, float* parametr = nullptr) const noexcept override;

	virtual Vector3d GetNormal(Vector3d intersectionPoint) const noexcept;

private:
	Point3d m_Origin;
	float m_Radius;
};