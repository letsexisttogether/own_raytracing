#pragma once
#include <vector>
#include "Render/Tracer.h"

class Scene
{
private:
	RayTracer m_RayTracer;
	std::vector<Intersectable*> m_Figures;
public:
	Scene() = delete;
	Scene(RayTracer& tracer);
	void AddToScene(Intersectable* figure);
	void Trace();
private:
	int FindClosestFigure();
};