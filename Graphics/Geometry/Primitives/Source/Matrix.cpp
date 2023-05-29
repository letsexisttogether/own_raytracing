#include "../Matrix.hpp"

Matrix::Matrix()
{
	SetBase();
}

void Matrix::SetBase()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i != j) m_Matrix[i][j] = 0;
			else m_Matrix[i][j] = 1;
		}
	}
}


Vector3d Matrix::GetTransformedVector(const Vector3d& vector)
{
	std::array<float, 4> vector_matrix = { vector.GetX(), vector.GetY(), vector.GetZ(), 1.f };
	std::array<float, 4> vector_result;
	for (int i = 0; i < 4; i++)
	{
		float sum = 0.f;
		for (int j = 0; j < 4; j++)
		{
			sum += vector_matrix[j] * m_Matrix[i][j];
		}
		vector_result[i] = sum;
	}
	return { vector_result[0], vector_result[1] ,vector_result[2] };
}


void Matrix::AddMoving(const Vector3d& moving_vector)
{
	std::array<float, 3> vector_matrix = { moving_vector.GetX(), moving_vector.GetY(), moving_vector.GetZ() };
	for (int i = 0; i < 4 - 1; i++)
	{
		m_Matrix[i][3] = vector_matrix[i];
	}
	/*m_Matrix[0][3] = moving_vector.GetX();
	m_Matrix[1][3] = moving_vector.GetY();
	m_Matrix[2][3] = moving_vector.GetZ();*/
}


void Matrix::AddScale(const Vector3d& scale)
{
	std::array<float, 4> vector_matrix = { scale.GetX(), scale.GetY(), scale.GetZ(), 1.f };
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m_Matrix[i][j] *= vector_matrix[i];
		}
	}
}


void Matrix::AddRotation(const Vector3d& angles)
{
	Matrix matrixX;
	Matrix matrixY;
	Matrix matrixZ;

	matrixX.m_Matrix[1][1] = cos(angles.GetX());
	matrixX.m_Matrix[2][1] = sin(angles.GetX());
	matrixX.m_Matrix[1][2] = -sin(angles.GetX());
	matrixX.m_Matrix[2][2] = cos(angles.GetX());

	matrixY.m_Matrix[0][0] = cos(angles.GetY());
	matrixY.m_Matrix[2][0] = sin(angles.GetY());
	matrixY.m_Matrix[0][2] = -sin(angles.GetY());
	matrixY.m_Matrix[2][2] = cos(angles.GetY());

	matrixZ.m_Matrix[0][0] = cos(angles.GetZ());
	matrixZ.m_Matrix[1][0] = sin(angles.GetZ());
	matrixZ.m_Matrix[0][1] = -sin(angles.GetZ());
	matrixZ.m_Matrix[1][1] = cos(angles.GetZ());

	*this = matrixX * matrixY * matrixZ * *this;
}

Matrix Matrix::operator * (const Matrix& matrix)
{
	Matrix result;
	result.SetClean();
	for (size_t i = 0; i < 4; i++) {
		for (size_t j = 0; j < 4; j++) {
			for (size_t k = 0; k < 4; k++) {
				result.m_Matrix[i][j] += m_Matrix[i][k] * matrix.m_Matrix[k][j];
			}
		}
	}
	return result;
}