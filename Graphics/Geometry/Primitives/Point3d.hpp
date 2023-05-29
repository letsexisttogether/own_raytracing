#pragma once
#include "Vector3d.hpp"

class Vector3d;

class Point3d
{
public:
	Point3d() = delete;
	Point3d(const Point3d&) = default;
	Point3d(Point3d&&) = default;

	Point3d(float x, float y, float z);
	Point3d(float superCoord);

	Point3d(const Vector3d& vector);

	~Point3d() = default;

	inline float GetX() const noexcept { return m_X; }
	inline float GetY() const noexcept { return m_Y; }
	inline float GetZ() const noexcept { return m_Z; }


	Point3d& operator = (const Point3d&) = default;
	Point3d& operator = (Point3d&&) = default;

	

	Point3d operator + (const Vector3d& vec3d) const noexcept;
	Point3d operator - (const Vector3d& vec3d) const noexcept;

	//Point3d operator + (const Point3d& vec3d) const noexcept;
	Vector3d operator - (const Point3d& vec3d) const noexcept;

	Vector3d ToVector() const;

private:
	float m_X;
	float m_Y;
	float m_Z;
	float m_Additional = 1.f;
};