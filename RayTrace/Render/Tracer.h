#pragma once
#include <iostream>
#include "Geometry/Vector3d.hpp"
#include "Geometry/Sphere.hpp"
#include "IntersectedWithSphere.hpp"
#include "IntersectedWithPlane.hpp"
#include "IntersectedWithDisk.hpp"
#include "Screen.h"

class RayTracer
{
private:
	//Vector3d m_Camera;
	Camera m_Camera;
	Screen m_Screen;
	Vector3d m_LightVector;
	
	float m_Distance; //не потрібно, є у класі екрану, потім виправити конструктор

	/*IntersectedWithSphere m_IWS;
	IntersectedWithPlane m_IWP;
	IntersectedWithDisk m_IWD;*/

public:
	RayTracer() = delete;
	RayTracer(const Screen& screen, const Camera& camera,
		const Vector3d& lightSrc, const float distance);

	char LightTracing(float dotResult);

	//void Tracing(const Sphere& sphere) noexcept(false);

	//void Tracing(const Plane& plane) noexcept(false);

	//void Tracing(const Disk& disk) noexcept(false);

	void Tracing(const Intersectable& intersectable) noexcept(false);

};
