#pragma once
#include "Matrix.hpp"
#include "Vector4.hpp"

namespace TF
{
	Matrix4 CreateRotationMatrixX(float radian_angle)
	{
		Matrix4 matrixX;
		matrixX.m_Matrix[1][1] = cos(radian_angle);
		matrixX.m_Matrix[2][1] = sin(radian_angle);
		matrixX.m_Matrix[1][2] = -sin(radian_angle);
		matrixX.m_Matrix[2][2] = cos(radian_angle);
		return matrixX;
	}

	Matrix4 CreateRotationMatrixY(float radian_angle)
	{
		Matrix4 matrixY;
		matrixY.m_Matrix[0][0] = cos(radian_angle);
		matrixY.m_Matrix[2][0] = sin(radian_angle);
		matrixY.m_Matrix[0][2] = -sin(radian_angle);
		matrixY.m_Matrix[2][2] = cos(radian_angle);
		return matrixY;
	}

	Matrix4 CreateRotationMatrixZ(float radian_angle)
	{
		Matrix4 matrixZ;
		matrixZ.m_Matrix[0][0] = cos(radian_angle);
		matrixZ.m_Matrix[1][0] = sin(radian_angle);
		matrixZ.m_Matrix[0][1] = -sin(radian_angle);
		matrixZ.m_Matrix[1][1] = cos(radian_angle);
		return matrixZ;
	}

	Matrix4 CreateRotationMatrix(const Vector3d& angles)
	{
		return CreateRotationMatrixZ(angles.GetZ()) * CreateRotationMatrixY(angles.GetY()) *  CreateRotationMatrixX(angles.GetX());
	}

	Matrix4 CreateScalingMatrix(const Vector3d& scale)
	{
		Matrix4 matrix;
		Vector4 vector = { scale.GetX(), scale.GetY(), scale.GetZ() };
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				matrix.m_Matrix[i][j] *= vector[i];
			}
		}
		return matrix;
	}

	Matrix4 CreateMovingMatrix(const Vector3d& moving_vector)
	{
		Matrix4 matrix;
		Vector4 vector = { moving_vector.GetX(), moving_vector.GetY(), moving_vector.GetZ() };
		for (int i = 0; i < 4 - 1; i++)
		{
			matrix.m_Matrix[i][3] = vector.GetData()[i];
		}
		return matrix;
	}
}