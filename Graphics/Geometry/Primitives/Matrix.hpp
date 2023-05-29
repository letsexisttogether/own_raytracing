#pragma once
#include <cmath>
#include <array>
#include "Vector3d.hpp"

class Matrix
{
private:
	
public:
	std::array<std::array<float, 4>, 4> m_Matrix;
	Matrix();

	Matrix operator * (const Matrix& matrix);

	void SetBase();

	void SetClean()
	{
		for (int i = 0; i < 4; i++)
			m_Matrix[i].fill(0.f);
	}

	Vector3d GetTransformedVector(const Vector3d& vector);

	void AddRotation(const Vector3d& angles);
	void AddMoving(const Vector3d& moving_vector);
	void AddScale(const Vector3d& scale);
	//void AddScale(float scale);
};