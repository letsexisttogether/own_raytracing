#pragma once

#include "Plane.hpp"

class Disk : public Intersectable
{
public:
	Disk() = delete;
	Disk(const Plane& plane, const float radius);
	
	~Disk() = default;

	inline const Plane& GetPlane() const noexcept { return m_Plane; }
	inline const float GetRadius() const noexcept { return m_Radius; }

	std::optional<Intersection> IntersectedWithRay(const Ray& ray, float* parametr = nullptr) const noexcept override;

	virtual Vector3d GetNormal(Vector3d intersectionPoint) const noexcept;

private:
	Plane m_Plane;
	float m_Radius;
};