#pragma once
#include <iostream>
#include "Geometry/Intersectables/Sphere.hpp"
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

	//void Tracing(const Sphere& sphere) noexcept(false);

	//void Tracing(const Plane& plane) noexcept(false);

	//void Tracing(const Disk& disk) noexcept(false);

	void Tracing(const Intersectable& intersectable) noexcept(false);

};
