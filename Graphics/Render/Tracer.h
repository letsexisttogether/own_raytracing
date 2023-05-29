#pragma once

#include <iostream>
#include <memory>

#include "Geometry/Intersectables/Intersectable.h"
#include "RenderHandler/RenderHandler.hpp"
#include "Camera.h"


class RayTracer
{
public:
	RayTracer() = delete;
	RayTracer(const RayTracer&) = default;
	RayTracer(RayTracer&&) = default;

	RayTracer(RenderHandler* renderHandler, const Camera& camera, const Vector3d& lightSrc);

	~RayTracer();

	inline const Camera& GetCamera() const noexcept { return m_Camera; }
	inline const RenderHandler& GetRenderHandler() const noexcept { return *m_Handler; }

	void Trace(const Intersectable& intersectable) noexcept(false);

private:
	RenderHandler* m_Handler;
	Camera m_Camera;
	Vector3d m_LightVector;
};



