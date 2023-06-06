#pragma once

#include "Light.hpp"

class AmbientLight : public Light
{
public:
    AmbientLight(const Vector3d& color, float intensity);

    Vector3d HandleLight(const Intersection& intersection) const noexcept(false) override;

    bool IsInShadow(const Intersection& intersection, const Scene& scene) const noexcept override;

private:
    Vector3d m_HandleResult;
};