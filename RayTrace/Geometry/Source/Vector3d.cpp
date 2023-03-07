#include "..\Vector3d.hpp"

#include <cmath>


Vector3d::Vector3d(float x, float y, float z)
	: m_X{ x }, m_Y{ y }, m_Z{ z }
{}

Vector3d::Vector3d(float superCoord)
	: m_X{ superCoord }, m_Y{ superCoord }, m_Z{ superCoord }
{}

float Vector3d::GetLength() const noexcept
{
	return static_cast<float>(sqrt(m_X * m_X + m_Y * m_Y + m_Z * m_Z));
}

Vector3d Vector3d::operator + (const Vector3d& vec3d) const noexcept
{
	return Vector3d{ m_X + vec3d.m_X, m_Y + vec3d.m_Y, m_Z + vec3d.m_Z };
}

Vector3d Vector3d::operator - (const Vector3d& vec3d) const noexcept
{
	return Vector3d{ m_X - vec3d.m_X, m_Y - vec3d.m_Y, m_Z - vec3d.m_Z };
}

Vector3d Vector3d::operator * (const float value) const noexcept
{
	return Vector3d{ m_X * value, m_Y * value, m_Z * value };
}

float Vector3d::Dot(const Vector3d& vec3d) const noexcept
{
	return m_X * vec3d.m_X + m_Y * vec3d.m_Y + m_Z * vec3d.m_Z;
}

Vector3d Vector3d::Cross(const Vector3d& vec3d) const noexcept
{
	return Vector3d
	{
		m_Y * vec3d.m_Z - m_Z * vec3d.m_Y,
		m_Z * vec3d.m_X - m_X * vec3d.m_Z,
		m_X * vec3d.m_Y - m_Y * vec3d.m_X
	};
}

float Vector3d::GetCosBetween(const Vector3d& vec) const noexcept
{
	float numerator = Dot(vec);
	float denominator = GetLength() * vec.GetLength();
	return numerator / denominator;
}