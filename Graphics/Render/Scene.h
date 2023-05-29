#pragma once

#include <vector>

#include "Render/Tracer.h"

class Scene : public Intersectable
{
public:
	Scene() = delete;
	Scene(const RayTracer& tracer);

	~Scene();
	
	virtual std::optional<Intersection> IntersectedWithRay(const Ray& ray, float* parametr = nullptr) const noexcept override;
	
	void AddToScene(Intersectable* figure);

private:
	RayTracer m_RayTracer;
	std::vector<Intersectable*> m_Figures;
};