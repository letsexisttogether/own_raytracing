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
            const float relativeCoordinatei = (i - height / 2.f) + camera.GetDirection().GetY();
            const float relativeCoordinatej = (j - width / 2.f) + camera.GetDirection().GetX();

            const float absoluteCoordinateI = (relativeCoordinatei * screen.GetPixelSize()) + (screen.GetPixelSize() / 2.f);
            const float absoluteCoordinateJ = (relativeCoordinatej * screen.GetPixelSize()) + (screen.GetPixelSize() / 2.f);

            const Vector3d thrownVector{ Vector3d{ absoluteCoordinateJ, absoluteCoordinateI, screen.GetDistance() * camera.GetDirection().GetZ() } - camera.GetLocation() };

            const Ray thrownRay{ camera.GetLocation(), thrownVector.Normalize() };

            std::optional<Intersection> intersection{ scene.FindClosestIntersection(thrownRay) };

            Vector3d blendedColor{ 0.f };

            if (intersection.has_value())
            {
                auto& value = intersection.value();

                value.Normal = value.Normal.Normalize();

                for (const auto light : scene.GetLights())
                {
                    if (!light->IsInShadow(value, scene))
                    {
                        blendedColor += light->HandleLight(intersection.value());
                    }
                }

                blendedColor /= static_cast<float>(scene.GetLights().size());
                blendedColor.Clamp(0.f, 255.f);
            }
            
            m_Handler->HandlePixel(i, j, blendedColor);
        }
    }
}
