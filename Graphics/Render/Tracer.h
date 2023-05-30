#pragma once

#include <iostream>
#include <memory>

#include "RenderHandler/RenderHandler.hpp"
#include "Scene.h"

class RayTracer
{
public:
	RayTracer() = delete;
	RayTracer(const RayTracer&) = default;
	RayTracer(RayTracer&&) = default;

	RayTracer(RenderHandler* renderHandler);

	~RayTracer();

	inline const RenderHandler& GetRenderHandler() const noexcept { return *m_Handler; }

	void Trace(const Scene& scene) noexcept(false);

private:
	RenderHandler* m_Handler;
};



