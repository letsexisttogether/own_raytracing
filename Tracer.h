#pragma once
#include "Geometry/Vector3d.hpp"
#include "IntersectedWithSphere.hpp"
#include "Geometry/Sphere.hpp"
#include "Geometry/Ray.hpp"
#include "Geometry/Plane.hpp"
#include "Screen.h"
#include <iostream>

class RayTracer
{
private:
	Vector3d m_Camera;
	float m_Distance;
	IntersectedWithSphere m_IWS;
public:

	RayTracer() = delete;
	RayTracer(Vector3d Camera, float Distance) : m_Camera(Camera), m_Distance(Distance) {};

	template <int H, int W>
	void Tracing(Screen<H, W>& screen, Sphere& sphere)
	{
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if (m_IWS.IntersectedWithRay(sphere, { m_Camera, { Vector3d(i, j, m_Distance) - m_Camera } })) screen.m_Screen[i][j] = '#';
				else screen.m_Screen[i][j] = ' ';
			}
		}
	}
};