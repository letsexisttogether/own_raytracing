#pragma once
#include <cmath>
#include <array>
#include "Vector3d.hpp"
#include "Vector4.hpp"

class Vector3d;
class Vector4;

class Matrix4
{
private:
	
public:
	std::array<std::array<float, 4>, 4> m_Matrix;

	Matrix4();

	Matrix4 operator * (const Matrix4& matrix);

	Vector4 operator * (const Vector4& matrix);

	void SetBase();

	void SetClean()
	{
		for (int i = 0; i < 4; i++)
			m_Matrix[i].fill(0.f);
	};

	/*Vector3d GetTransformedVector(const Vector3d& vector);

	void AddRotation(const Vector3d& angles);
	void AddMoving(const Vector3d& moving_vector);
	void AddScale(const Vector3d& scale);*/
	//void AddScale(float scale);
};