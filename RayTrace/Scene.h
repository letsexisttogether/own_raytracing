#pragma once
#include <vector>
#include "Render/Tracer.h"

class Scene : public Intersectable
{
private:
	RayTracer m_RayTracer;
	std::vector<Intersectable*> m_Figures;

public:
	Scene() = delete;
	Scene(RayTracer& tracer);
	
	virtual std::optional<Intersection> IntersectedWithRay(const Ray& ray, float* parametr = nullptr) const noexcept override;
	
	void AddToScene(Intersectable* figure);
};