#pragma once

#include "Light.hpp"

class AmbientLight : public Light
{
public:
    AmbientLight(const Vector3d& color, float intensity);

    Vector3d HandleLight(const Intersection& intersection) const noexcept(false) override;

private:
    Vector3d m_HandleResult;
};