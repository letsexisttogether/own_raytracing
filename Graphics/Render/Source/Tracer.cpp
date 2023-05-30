#include "../Tracer.h"

RayTracer::RayTracer(RenderHandler* renderHandler, const Camera& camera, const Vector3d& lightSrc)
	: m_Handler{ renderHandler }, m_Camera(camera), m_LightVector(lightSrc * -1.f)
{}

RayTracer::~RayTracer()
{
	// delete m_Handler;
}

void RayTracer::Trace(const Intersectable& intersectable) noexcept(false)
{
    const Screen& screen = m_Handler->GetScreen();

    const Screen::Resolution height = screen.GetHeigth();
    const Screen::Resolution width = screen.GetWidth();

    for (Screen::Resolution i = 0; i < height; i++)
    {
        for (Screen::Resolution j = 0; j < width; j++)
        {
            const float relativeCoordinatei = i - height / 2.f;
            const float relativeCoordinatej = j - width / 2.f;

            const float absoluteCoordinateI = (relativeCoordinatei * screen.GetPixelSize()) + (screen.GetPixelSize() / 2.f);
            const float absoluteCoordinateJ = (relativeCoordinatej * screen.GetPixelSize()) + (screen.GetPixelSize() / 2.f);

            const Vector3d thrownVector{ Vector3d{ absoluteCoordinateJ, absoluteCoordinateI, screen.GetDistance() } - m_Camera.GetLocation() };

            const Ray thrownRay{ m_Camera.GetLocation(), thrownVector.Normalize() };

            std::optional<Intersection> intersection{ intersectable.IntersectedWithRay(thrownRay) };

            if (intersection.has_value())
            {
                const Vector3d normal{ intersection.value().Normal.Normalize() };
                m_Handler->HandlePixel(i, j, normal.Dot(m_LightVector));
            }
            else
            {
                m_Handler->HandlePixel(i, j, 0.f);
            }
        }
    }
}
