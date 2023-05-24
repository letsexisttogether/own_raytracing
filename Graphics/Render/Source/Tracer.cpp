#include "../Tracer.h"

RayTracer::RayTracer(const Screen& screen, const Camera& camera, const Vector3d& lightSrc)
	: m_Screen{ screen }, m_Camera(camera), m_LightVector(lightSrc * -1.f)
{}

char RayTracer::LightTracing(float dotResult)
{
	if (dotResult <= 0) return ' ';
	else if (dotResult > 0 && dotResult <= 0.2) return '.';
	else if (dotResult > 0.2 && dotResult <= 0.5) return '*';
	else if (dotResult > 0.5 && dotResult <= 0.8) return 'O';
	else if (dotResult > 0.8) return '#';
}

void RayTracer::Tracing(const Intersectable& intersectable) noexcept(false)
{
	for (int i = 0; i < m_Screen.GetHeigth(); i++)
	{
		for (int j = 0; j < m_Screen.GetWidth(); j++)
		{
			float relativeCoordinatei = i - m_Screen.GetHeigth() / 2.f;
			float relativeCoordinatej = j - m_Screen.GetWidth() / 2.f;

			float absoluteCoordinateI = (relativeCoordinatei * m_Screen.GetPixelSize()) + (m_Screen.GetPixelSize() / 2.f);
			float absoluteCoordinateJ = (relativeCoordinatej * m_Screen.GetPixelSize()) + (m_Screen.GetPixelSize() / 2.f);

			Vector3d thrownVector = { Vector3d{ absoluteCoordinateJ, absoluteCoordinateI, m_Screen.GetDistance() } - m_Camera.GetLocation() };

			Ray thrownRay{ m_Camera.GetLocation(), thrownVector.Normalize() };

			std::optional<Intersection> intersection = intersectable.IntersectedWithRay(thrownRay);

			if (intersection.has_value())
			{
				Vector3d normal = intersection.value().Normal.Normalize();
				char symbol = LightTracing(normal.Dot(m_LightVector));
				m_Screen.GetPixel(i, j) = symbol;
			}
			else
			{
				m_Screen.GetPixel(i, j) = ' ';
			}
		}
	}
}

