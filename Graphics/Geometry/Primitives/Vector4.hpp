#pragma once
#include <array>

#include "Vector3d.hpp"

class Vector3d;
class Matrix4;

class Vector4
{
public:
	Vector4() = delete;
	Vector4(const Vector4&) = default;
	Vector4(Vector4&&) = default;

	Vector4(const float superCoord);
	Vector4(float x, float y, float z);

	Vector4(const Vector3d& other);

	~Vector4() = default;

	inline const std::array<float, 4>& GetData() const noexcept { return m_Data; }
	inline float GetX() const noexcept { return m_Data[0]; }
	inline float GetY() const noexcept { return m_Data[1]; }
	inline float GetZ() const noexcept { return m_Data[2]; }
	inline float GetAdditional() const noexcept { return m_Data[3]; }

	Vector4& operator = (const Vector4&) = default;
	Vector4& operator = (Vector4&&) = default;

	float& operator[] (const std::size_t index);
	float operator[] (const std::size_t index) const;

	Vector4 operator *(const Matrix4& matrix);

private:
	std::array<float, 4> m_Data;	
};