#pragma once
#include "Geometry/Primitives/Vector3d.hpp"
#include "Geometry/Primitives/Point3d.hpp"
#include "Geometry/Primitives/Matrix.hpp"

class Camera
{
public:
	Camera() = delete;
	Camera(const Vector3d& Location, const Vector3d& Direction, const float FOV) 
		: m_Location(Location), m_Direction(Direction), m_FOV(FOV) 
	{} 

	inline Vector3d GetLocation() const noexcept { return m_Location; }

	inline Vector3d GetDirection() const noexcept { return m_Direction; }

	inline float GetFOV() const noexcept { return m_FOV; }

	void TransformLocation(const Matrix4& matrix) noexcept
	{
		TransformVector(m_Location, matrix);
	}
	void TransformDirection(const Matrix4& matrix) noexcept
	{
		TransformVector(m_Direction, matrix);
	}

private:
	void TransformVector(Vector3d& vector, const Matrix4& matrix)
	{
		vector = Vector4{ vector } * matrix;
	}

private:
	Vector3d m_Location;
	Vector3d m_Direction;
	float m_FOV;
};


