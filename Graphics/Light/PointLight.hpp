#pragma once 

#include "Light.hpp"

class PointLight : public Light
{
public:
    PointLight(const Vector3d& position, const Vector3d& color, float intensity);

    Vector3d HandleLight(const Intersection& intersection) const noexcept(false) override;

    bool IsInShadow(const Intersection& intersection, const Scene& scene) const noexcept override;

private:
    const Vector3d m_Position;
};