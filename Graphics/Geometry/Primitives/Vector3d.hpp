#pragma once
#include "Point3d.hpp"

class Point3d;

class Vector3d
{
public:
	Vector3d() = delete;
	Vector3d(const Vector3d&) = default;
	Vector3d(Vector3d&&) = default;

	Vector3d(const Point3d& point);

	Vector3d(float x, float y, float z);
	Vector3d(float superCoord);

	~Vector3d() = default;

	inline float GetX() const noexcept { return m_X; }
	inline float GetY() const noexcept { return m_Y; }
	inline float GetZ() const noexcept { return m_Z; }

	float GetLength() const noexcept;

	Vector3d& operator = (const Vector3d&) = default;
	Vector3d& operator = (Vector3d&&) = default;

	Vector3d& operator = (const Point3d& other);

	Vector3d operator + (const Vector3d& vec3d) const noexcept;
	Vector3d operator - (const Vector3d& vec3d) const noexcept;

	Vector3d operator * (const float value) const noexcept;

	float Dot(const Vector3d& vec3d) const noexcept;
	Vector3d Cross(const Vector3d& vec3d) const noexcept;

	Vector3d Normalize() const noexcept(false);

	float GetCosBetween(const Vector3d& vec) const noexcept;

private:
	float m_X;
	float m_Y;
	float m_Z;
};