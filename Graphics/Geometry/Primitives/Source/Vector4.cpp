#include "../Vector4.hpp"

Vector4::Vector4(float x, float y, float z) : m_Data{x, y, z, 1.f}
{
	
}

Vector4::Vector4(const Vector3d& other) : m_Data{ other.GetX(), other.GetY(), other.GetZ(), 1.f}
{
}

Vector4 Vector4::operator * (const Matrix4& matrix)
{
	Vector4 vector = { this->GetX(), this->GetY(), this->GetZ() };
	Vector4 vector_result = { 0.f, 0.f, 0.f };
	for (int i = 0; i < 4; i++)
	{
		float sum = 0.f;
		for (int j = 0; j < 4; j++)
		{
			sum += vector.m_Data[j] * matrix.m_Matrix[i][j];
		}
		vector_result.m_Data[i] = sum;
	}
	return vector_result;
}