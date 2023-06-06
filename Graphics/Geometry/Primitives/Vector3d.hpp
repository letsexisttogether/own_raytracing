#pragma once

#include <optional>

#include "Point3d.hpp"
#include "Vector4.hpp"

class Point3d;
class Vector4;

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

	float Dot(const Vector3d& vec3d) const noexcept;
	Vector3d Cross(const Vector3d& vec3d) const noexcept;

	Vector3d Normalize() const noexcept(false);
	
	void Clamp(const float minVal, const float maxVal) noexcept;

	float GetCosBetween(const Vector3d& vec) const noexcept;

	Vector3d& operator = (const Vector3d&) = default;
	Vector3d& operator = (Vector3d&&) = default;

	Vector3d& operator = (const Point3d& other);

	Vector3d(const Vector4& other);

	Vector3d operator + (const Vector3d& vec3d) const noexcept;
	Vector3d& operator += (const Vector3d& vec3d) noexcept;

	Vector3d operator - (const Vector3d& vec3d) const noexcept;
	
	Vector3d operator * (const float value) const noexcept;

	Vector3d operator / (const float value) const;
	Vector3d& operator /= (const float value);

	friend Vector3d operator - (const Vector3d& vec3d) noexcept;

private:
	float m_X;
	float m_Y;
	float m_Z;

	mutable std::optional<float> m_Length;
};