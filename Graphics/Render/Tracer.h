#pragma once

#include <iostream>
#include <memory>

#include "RenderHandler/RenderHandler.hpp"
#include "Scene.h"
#include "../Geometry/Intersectables/BVH.hpp"

class RayTracer
{
public:
	RayTracer() = default;
	RayTracer(const RayTracer&) = default;
	RayTracer(RayTracer&&) = default;

	~RayTracer() = default;

	inline const std::vector<std::vector<Vector3d>>& GetPixels() const noexcept { return m_Pixels; }

	void Trace(const Scene& scene) noexcept(false);
	// void Trace(const BVHTree& tree, const Camera& camera, const Vector3d& lightvector) noexcept(false);

private:
	std::vector<std::vector<Vector3d>> m_Pixels;
};



