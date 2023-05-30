#pragma once

class Vector4
{
public:
	Vector4() = delete;
	Vector4(const Vector4&) = default;
	Vector4(Vector4&&) = default;

	Vector4(float x, float y, float z);

	~Vector4() = default;

	inline float GetX() const noexcept { return m_X; }
	inline float GetY() const noexcept { return m_Y; }
	inline float GetZ() const noexcept { return m_Z; }
	inline float GetAdditional() const noexcept { return m_Additional; }


	Vector4& operator = (const Vector4&) = default;
	Vector4& operator = (Vector4&&) = default;

private:
	float m_X;
	float m_Y;
	float m_Z;
	float m_Additional;
};