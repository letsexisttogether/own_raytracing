#include "../Tracer.h"

RayTracer::RayTracer(const Screen& screen, const Camera& camera, const Vector3d& lightSrc)
	: m_Screen{ screen }, m_Camera(camera), m_LightVector(lightSrc * -1.f)
{}

char RayTracer::LightTracing(float dotResult)
{
	if (dotResult < 0) return ' ';
	else if (dotResult >= 0 && dotResult < 0.2) return '.';
	else if (dotResult >= 0.2 && dotResult < 0.5) return '*';
	else if (dotResult >= 0.5 && dotResult < 0.8) return 'O';
	else if (dotResult >= 0.8) return '#';
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

			Vector3d thrownVector = { Vector3d(absoluteCoordinateI, absoluteCoordinateJ, m_Screen.GetDistance()) - m_Camera.GetLocation()};

			Ray thrownRay{ m_Camera.GetLocation(), thrownVector.Normalize()};

			//const bool doesIntersect = (intersectable.IntersectedWithRay(thrownRay).has_value());
			std::optional<Vector3d> doesIntersect = intersectable.IntersectedWithRay(thrownRay);

			//m_Screen.GetPixel(i, j) = ((doesIntersect) ? ('#') : (' '));
			if (doesIntersect.has_value())
			{
				Vector3d normal = intersectable.GetNormal(doesIntersect.value()).Normalize();
				m_Screen.GetPixel(i, j) = LightTracing(normal.Dot(m_LightVector));
			}
			else m_Screen.GetPixel(i, j) = ' ';
		}
	}
	m_Screen.Print();
}

