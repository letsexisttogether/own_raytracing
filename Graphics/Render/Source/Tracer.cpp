#include "../Tracer.h"

RayTracer::RayTracer(RenderHandler* renderHandler)
	: m_Handler{ renderHandler }
{}

RayTracer::~RayTracer()
{
	// delete m_Handler;
}

void RayTracer::Trace(const Scene& scene) noexcept(false)
{
    const Screen& screen = m_Handler->GetScreen();
    const Camera& camera = scene.GetCamera();

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

            const Vector3d thrownVector{ Vector3d{ absoluteCoordinateJ, absoluteCoordinateI, screen.GetDistance() } - camera.GetLocation() };

            const Ray thrownRay{ camera.GetLocation(), thrownVector.Normalize() };

            std::optional<Intersection> intersection{ scene.FindClosestIntersection(thrownRay) };

            if (intersection.has_value()  && !scene.CheckAnyIntersection(intersection.value()))
            {
                const Vector3d normal{ intersection.value().Normal.Normalize() };

                m_Handler->HandlePixel(i, j, normal.Dot(scene.GetLightVector()));
            }
            else
            {
                m_Handler->HandlePixel(i, j, 0.f);
            }
        }
    }
}
