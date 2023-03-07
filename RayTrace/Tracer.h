#pragma once
#include "Geometry/Vector3d.hpp"
#include "IntersectedWithSphere.hpp"
#include "Geometry/Sphere.hpp"
#include "Geometry/Ray.hpp"
#include "Screen.h"
#include <iostream>

class RayTracer
{
private:
	Vector3d m_Camera;
	Vector3d m_LightSource;
	float m_Distance;
	IntersectedWithSphere m_IWS;
public:

	RayTracer() = delete;
	RayTracer(Vector3d Camera, Vector3d LightSrc, float Distance) : m_Camera(Camera), m_LightSource(LightSrc * -1.f), m_Distance(Distance) {};

	char LightTracing(float DotResult)
	{
		std::cout << DotResult << std::endl;
		if (DotResult < 0) return ' ';
		else if (DotResult >= 0 && DotResult < 0.2) return '.';
		else if (DotResult >= 0.2 && DotResult < 0.5) return '*';
		else if (DotResult >= 0.5 && DotResult < 0.8) return 'O';
		else if (DotResult >= 0.8) return '#';
	}

	template <int H, int W>
	void Tracing(Screen<H, W>& screen, Sphere& sphere)
	{
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{				 
				Vector3d thrownVector = { Vector3d(i, j, m_Distance) - m_Camera };				
				thrownVector.Normalize();

				if (m_IWS.IntersectedWithRay(sphere, { m_Camera, thrownVector }))
					screen.m_Screen[i][j] = LightTracing(m_LightSource.Dot(thrownVector * -1.f));
				else screen.m_Screen[i][j] = ' ';
			}
		}		
	}
};
