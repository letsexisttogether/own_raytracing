#pragma once

#include "Vector3d.hpp"
#include "Point3d.hpp"

class Ray
{
public:
	Ray() = delete;
	Ray(const Point3d& origin, const Vector3d& direction);

	~Ray() = default;

	inline const Point3d& GetOrigin() const noexcept { return m_Origin; }

	inline const Vector3d& GetDirection() const noexcept { return m_Direction; }

private:
	Point3d m_Origin;
	Vector3d m_Direction;
};