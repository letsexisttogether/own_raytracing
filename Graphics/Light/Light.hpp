#pragma once 

#include "Geometry/Primitives/Vector3d.hpp"

class Light
{
public:
	Light(const Vector3d& color, const float intensity)
		: m_Color{ color }, m_Intensity { intensity }
	{}

	virtual ~Light() = 0;


	// Повертає значення кольору
	virtual Vector3d& HandleLight(const Intersection& intersection) const = 0;

private: 
	Vector3d m_Color;
	const float m_Intensity;
};