#include "../Tracer.h"

RayTracer::RayTracer(const Screen& screen, const Vector3d& camera,
	const Vector3d& lightSrc, const float distance)
	: m_Screen{ screen }, m_Camera(camera),
	m_LightSource(lightSrc * -1.f), m_Distance{ distance }
{}

char RayTracer::LightTracing(float dotResult)
{
	if (dotResult < 0) return ' ';
	else if (dotResult >= 0 && dotResult < 0.2) return '.';
	else if (dotResult >= 0.2 && dotResult < 0.5) return '*';
	else if (dotResult >= 0.5 && dotResult < 0.8) return 'O';
	else if (dotResult >= 0.8) return '#';
}

void RayTracer::Tracing(const Sphere& sphere) noexcept(false)
{
	for (int i = 0; i < m_Screen.GetHeigth(); i++)
	{
		for (int j = 0; j < m_Screen.GetWidth(); j++)
		{
			Vector3d thrownVector = { Vector3d(j, i, m_Distance) - m_Camera };

			const bool doesIntersect = m_IWS.IntersectedWithRay(sphere, { m_Camera, thrownVector });


			if (doesIntersect)
			{
				m_Screen.GetPixel(i, j) = ((doesIntersect) ? ('#') : (' '));

				std::cout << 'W';
			}

		}
	}

	m_Screen.Print();
}

void RayTracer::Tracing(const Plane& plane) noexcept(false)
{
	for (int i = 0; i < m_Screen.GetHeigth(); i++)
	{
		for (int j = 0; j < m_Screen.GetWidth(); j++)
		{
			Vector3d thrownVector = { Vector3d(j, i, m_Distance) - m_Camera };

			const bool doesIntersect = m_IWP.IntersectedWithRay(plane, { m_Camera, thrownVector });

			m_Screen.GetPixel(i, j) = ((doesIntersect) ? ('#') : (' '));
		}
	}

	m_Screen.Print();
}

void RayTracer::Tracing(const Disk& disk) noexcept(false)
{
	for (int i = 0; i < m_Screen.GetHeigth(); i++)
	{
		for (int j = 0; j < m_Screen.GetWidth(); j++)
		{
			Vector3d thrownVector = { Vector3d(j, i, m_Distance) - m_Camera };

			const bool doesIntersect = m_IWD.IntersectedWithRay(disk, { m_Camera, thrownVector });

			m_Screen.GetPixel(i, j) = ((doesIntersect) ? ('#') : (' '));
		}
	}

	m_Screen.Print();
}

