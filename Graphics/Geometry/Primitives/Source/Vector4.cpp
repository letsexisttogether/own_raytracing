#include "../Vector4.hpp"
#include "../Matrix.hpp"

Vector4::Vector4(const float superCoord)
	: m_Data{ superCoord, superCoord, superCoord, superCoord }
{}

Vector4::Vector4(float x, float y, float z)
	: m_Data{ x, y, z, 1.f }
{}

Vector4::Vector4(const Vector3d& other) 
	: m_Data{ other.GetX(), other.GetY(), other.GetZ(), 1.f}
{}

float& Vector4::operator[] (const std::size_t index)
{
	return m_Data.at(index);
}

float Vector4::operator[] (const std::size_t index) const
{
	return m_Data.at(index);
}

Vector4 Vector4::operator * (const Matrix4& matrix)
{
	return matrix * (*this);
}