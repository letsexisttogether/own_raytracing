#pragma once
#include <cmath>
#include <array>

class Vector3d;
class Vector4;

class Matrix4
{
private:
	
public:
	std::array<std::array<float, 4>, 4> m_Matrix;

	Matrix4();

	Matrix4 operator * (const Matrix4& matrix) const;

	Vector4 operator * (const Vector4& matrix) const;

	void SetBase();
	void SetClean();
};