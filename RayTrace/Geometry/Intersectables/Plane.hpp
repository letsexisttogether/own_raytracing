#pragma once

#include "Intersectable.h"
#include "Geometry/Primitives/Ray.hpp"

class Plane : public Intersectable
{
public:
	Plane() = delete;
	Plane(const Vector3d& origin, const Vector3d& normal);

	~Plane() = default;

	inline const Vector3d& GetOrigin() const noexcept { return m_Origin; }
	inline const Vector3d& GetNormal() const noexcept { return m_Normal; }

	bool IntersectedWithRay(Ray& ray, float* parametr = nullptr) const override;

private:
	Vector3d m_Origin;
	Vector3d m_Normal;
};