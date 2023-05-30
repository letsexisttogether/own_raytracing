#include "../Matrix.hpp"

#include "../Vector3d.hpp"
#include "../Vector4.hpp"

Matrix4::Matrix4()
{
	SetBase();
}

void Matrix4::SetBase()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m_Matrix[i][j] = (i == j);
		}
	}
}

void Matrix4::SetClean()
{
	for (int i = 0; i < 4; i++)
	{
		m_Matrix[i].fill(0.f);
	}
};

Matrix4 Matrix4::operator * (const Matrix4& matrix) const
{
	Matrix4 result;
	result.SetClean();
	for (size_t i = 0; i < 4; i++) 
	{
		for (size_t j = 0; j < 4; j++) 
		{
			for (size_t k = 0; k < 4; k++) 
			{
				result.m_Matrix[i][j] += m_Matrix[i][k] * matrix.m_Matrix[k][j];
			}
		}
	}
	return result;
}

Vector4 Matrix4::operator * (const Vector4& vector) const
{
	Vector4 vector_result{ 0.f };

	for (int i = 0; i < 4; i++)
	{
		float sum = 0.f;
		for (int j = 0; j < 4; j++)
		{
			sum += vector[j] * m_Matrix[i][j];
		}
		vector_result[i] = sum;
	}

	return vector_result;
}
