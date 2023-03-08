#pragma once

#include "Ray.hpp"
#include "Intersectable.h"

class Sphere : public Intersectable
{
public:
	Sphere() = delete;
	Sphere(const Vector3d& origin, const float radius);

	~Sphere() = default;

	inline const Vector3d& GetOrigin() const noexcept { return m_Origin; }

	inline float GetRadius() const noexcept { return m_Radius; }

	bool IntersectedWithRay(Ray& ray, float* parametr = nullptr) const override;

private:
	Vector3d m_Origin;
	float m_Radius;
};