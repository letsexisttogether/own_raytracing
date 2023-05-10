#pragma once
#include <iostream>
#include "Geometry/Intersectables/Sphere.hpp"
#include "Geometry/Intersectables/Plane.hpp"
#include "Geometry/Intersectables/Disk.hpp"
#include "Screen.h"


class RayTracer
{
private:
	Camera m_Camera;
	Screen m_Screen;
	Vector3d m_LightVector;
	
public:
	RayTracer() = delete;
	RayTracer(const Screen& screen, const Camera& camera, const Vector3d& lightSrc);

	char LightTracing(float dotResult);

	inline const Camera& GetCamera() noexcept { return m_Camera; }
	inline const Screen& GetScreen() noexcept { return m_Screen; }

	void Tracing(const Intersectable& intersectable) noexcept(false);

};



