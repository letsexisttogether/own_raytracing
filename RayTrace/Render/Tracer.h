#pragma once
#include <iostream>
#include "Geometry/Vector3d.hpp"
#include "Geometry/Sphere.hpp"
#include "IntersectedWithSphere.hpp"
#include "IntersectedWithPlane.hpp"
#include "IntersectedWithDisk.hpp"
#include "Screen.h"

class RayTracer
{
private:
	Vector3d m_Camera;
	Vector3d m_LightSource;
	Screen m_Screen;
	float m_Distance;
	IntersectedWithSphere m_IWS;
	IntersectedWithPlane m_IWP;
	IntersectedWithDisk m_IWD;

public:
	RayTracer() = delete;
	RayTracer(Screen screen, Vector3d Camera, Vector3d LightSrc, float Distance) 
		: m_Screen{ screen }, m_Camera(Camera), m_LightSource(LightSrc * -1.f), m_Distance(Distance) {};

	char LightTracing(float DotResult)
	{
		// std::cout << DotResult << std::endl;
		if (DotResult < 0) return ' ';
		else if (DotResult >= 0 && DotResult < 0.2) return '.';
		else if (DotResult >= 0.2 && DotResult < 0.5) return '*';
		else if (DotResult >= 0.5 && DotResult < 0.8) return 'O';
		else if (DotResult >= 0.8) return '#';
	}

	void Tracing(Sphere& sphere)
	{
		for (int i = 0; i < m_Screen.GetHeigth(); i++)
		{
			for (int j = 0; j < m_Screen.GetWidth(); j++)
			{				 
				Vector3d thrownVector = { Vector3d(j, i, m_Distance) - m_Camera };
				if (m_IWS.IntersectedWithRay(sphere, { m_Camera, thrownVector.Normalize() }))
					m_Screen.GetPixel(i, j) = LightTracing(m_LightSource.Dot(thrownVector.Normalize() * -1.f));
				else m_Screen.GetPixel(i, j) = ' ';
			}
		}		
	}

	void Tracing(Plane& plane)
	{
		for (int i = 0; i < m_Screen.GetHeigth(); i++)
		{
			for (int j = 0; j < m_Screen.GetWidth(); j++)
			{
				Vector3d thrownVector = { Vector3d(j, i, m_Distance) - m_Camera };
				thrownVector.Normalize();

				if (m_IWP.IntersectedWithRay(plane, { m_Camera, thrownVector }))
					m_Screen.GetPixel(i, j) = LightTracing(m_LightSource.Dot(thrownVector * -1.f));
				else m_Screen.GetPixel(i, j) = ' ';
			}
		}
	}

	void Tracing(Disk& disk)
	{
		for (int i = 0; i < m_Screen.GetHeigth(); i++)
		{
			for (int j = 0; j < m_Screen.GetWidth(); j++)
			{
				Vector3d thrownVector = { Vector3d(j, i, m_Distance) - m_Camera };
				thrownVector.Normalize();

				if (m_IWD.IntersectedWithRay(disk, { m_Camera, thrownVector }))
					m_Screen.GetPixel(i, j) = LightTracing(m_LightSource.Dot(thrownVector * -1.f));
				else m_Screen.GetPixel(i, j) = ' ';
			}
		}
	}
};
