#pragma once 

#include "Geometry/Primitives/Vector3d.hpp"
#include "Geometry/Intersectables/Intersectable.h"

class Light
{
public:
	Light(const Vector3d& color, const float intensity)
		: m_Color{ color }, m_Intensity { intensity }
	{}

	// Повертає значення кольору для точки перетину
	virtual Vector3d HandleLight(const Intersection& intersection) const noexcept(false) = 0;

	inline const Vector3d& GetColor() const noexcept { return m_Color; }
	inline const float& GetIntensity() const noexcept { return m_Intensity; }

protected: 
	Vector3d m_Color;
	float m_Intensity;
};