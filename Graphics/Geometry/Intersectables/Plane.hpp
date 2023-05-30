#pragma once

#include "Intersectable.h"

class Plane : public Intersectable
{
public:
	Plane() = delete;
	Plane(const Point3d& origin, const Vector3d& normal);

	~Plane() = default;

	inline const Point3d& GetOrigin() const noexcept { return m_Origin; }
	inline const Vector3d& GetNormal() const noexcept { return m_Normal; }

	std::optional<Intersection> IntersectedWithRay(const Ray& ray, float* parametr = nullptr) const noexcept override;

	virtual Vector3d GetNormal(Point3d intersectionPoint) const noexcept;

private:
	Point3d m_Origin;
	Vector3d m_Normal;
};