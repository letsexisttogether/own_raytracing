#pragma once
#include <array>
#include "Vector3d.hpp"
#include "Matrix.hpp"

class Vector3d;
class Matrix4;

class Vector4
{
public:
	Vector4() = delete;
	Vector4(const Vector4&) = default;
	Vector4(Vector4&&) = default;

	Vector4(float x, float y, float z);

	Vector4(const Vector3d& other);

	~Vector4() = default;

	inline std::array<float, 4> GetData() const noexcept { return m_Data; }
	inline float GetX() const noexcept { return m_Data[0]; }
	inline float GetY() const noexcept { return m_Data[1]; }
	inline float GetZ() const noexcept { return m_Data[2]; }
	inline float GetAdditional() const noexcept { return m_Data[3]; }


	Vector4& operator = (const Vector4&) = default;
	Vector4& operator = (Vector4&&) = default;

	Vector4 operator *(const Matrix4& matrix);

	std::array<float, 4> m_Data;
private:
	/*float m_X;
	float m_Y;
	float m_Z;
	float m_Additional;*/
	
};