#include "../Point3d.hpp"

Point3d::Point3d(const Vector3d& vector)
{
	this->m_X = vector.GetX();
	this->m_Y = vector.GetY();
	this->m_Z = vector.GetZ();
}

Point3d::Point3d(float x, float y, float z)
	: m_X{ x }, m_Y{ y }, m_Z{ z }
{}

Point3d::Point3d(float superCoord)
	: m_X{ superCoord }, m_Y{ superCoord }, m_Z{ superCoord }
{}


Point3d Point3d::operator+(const Vector3d& vec3d) const noexcept
{
	return { this->m_X + vec3d.GetX(), this->m_Y + vec3d.GetY(), this->m_Z + vec3d.GetZ() };
}


Point3d Point3d::operator-(const Vector3d& vec3d) const noexcept
{
	return { this->m_X - vec3d.GetX(), this->m_Y - vec3d.GetY(), this->m_Z - vec3d.GetZ() };
}

Vector3d Point3d::operator-(const Point3d& vec3d) const noexcept
{
	return { this->m_X - vec3d.GetX(), this->m_Y - vec3d.GetY(), this->m_Z - vec3d.GetZ() };
}


Vector3d Point3d::ToVector() const
{
	return { this->m_X, this->m_Y, this->m_Z };
}