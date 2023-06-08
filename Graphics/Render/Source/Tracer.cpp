#include "../Tracer.h"

#include "Render/Scene.h"

void RayTracer::Trace(const Scene& scene) noexcept(false)
{
    const Screen& screen = scene.GetScreen();
    const Camera& camera = screen.GetCamera();

    const Screen::Resolution height = screen.GetHeigth();
    const Screen::Resolution width = screen.GetWidth();

    m_Pixels.reserve(height);
    m_Pixels.resize(height, std::vector<Vector3d>());
    for (auto& vec : m_Pixels)
    {
        vec.reserve(width);
        vec.resize(width, Vector3d(0.f));
    }

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
                const Vector3d normal{ intersection.value().Normal.Normalize() };


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

                //m_Pixels[i][j]= blendedColor;
                m_Pixels[i].push_back(blendedColor);
            }
            else m_Pixels[i].push_back({ 0.f });
        }
    }
}
