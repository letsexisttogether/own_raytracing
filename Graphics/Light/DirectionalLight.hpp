#pragma once 

#include "Light.hpp"

class DirectionalLight : public Light
{
public:
    DirectionalLight(const Vector3d& direction, const Vector3d& color, float intensity);

    Vector3d HandleLight(const Intersection& intersection) const noexcept(false) override;

private:
    const Vector3d m_Direction;
    Vector3d m_RealColor;

};