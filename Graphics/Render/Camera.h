#pragma once
#include "Geometry/Primitives/Vector3d.hpp"
#include "Geometry/Primitives/Point3d.hpp"

class Camera
{
private:
	Point3d m_Location;
	Vector3d m_Direction;
	float m_FOV;
public:
	Camera() = delete;
	Camera(Point3d Location, Vector3d Direction, float FOV) : m_Location(Location), m_Direction(Direction), m_FOV(FOV) {} //point

	inline Point3d GetLocation() const noexcept { return m_Location; } //point

	inline Vector3d GetDirection() const noexcept { return m_Direction; }

	inline float GetFOV() const noexcept { return m_FOV; }
};
