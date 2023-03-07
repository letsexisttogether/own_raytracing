#pragma once

#include "Ray.hpp"

class Sphere
{
public:
	Sphere() = delete;
	Sphere(const Vector3d& origin, const float radius);

	~Sphere() = default;

	inline const Vector3d& GetOrigin() const noexcept { return m_Origin; }

	inline float GetRadius() const noexcept { return m_Radius; }

private:
	Vector3d m_Origin;
	float m_Radius;
};