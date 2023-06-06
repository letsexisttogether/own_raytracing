#pragma once

#include <iostream>
#include <memory>

#include "RenderHandler/RenderHandler.hpp"
#include "Scene.h"
#include "../Geometry/Intersectables/BVH.hpp"

class RayTracer
{
public:
	RayTracer() = delete;
	RayTracer(const RayTracer&) = default;
	RayTracer(RayTracer&&) = default;

	RayTracer(RenderHandler* renderHandler);

	~RayTracer();

	inline const RenderHandler& GetRenderHandler() const noexcept { return *m_Handler; }

	void Trace(const Scene& scene, const Camera& camera, const Vector3d& lightvector) noexcept(false);
	void Trace(const BVHTree& tree, const Camera& camera, const Vector3d& lightvector) noexcept(false);

private:
	RenderHandler* m_Handler;
};



