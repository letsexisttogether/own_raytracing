#pragma once

#include "Vector3d.hpp"
#include "Plane.hpp"

class Disk
{
public:
	Disk() = delete;
	Disk(const Plane& plane, const float radius);
	
	~Disk() = default;

	inline const Plane& GetPlane() const noexcept { return m_Plane; }
	inline const float GetRadius() const noexcept { return m_Radius; }

private:
	Plane m_Plane;
	float m_Radius;
};