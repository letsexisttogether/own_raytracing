#include "Scene.h"

Scene::Scene(RayTracer& tracer) : m_RayTracer(tracer) {}

void Scene::AddToScene(Intersectable* figure)
{
	m_Figures.push_back(figure);
}

void Scene::Trace()
{
	m_RayTracer.Tracing(*m_Figures[FindClosestFigure()]);
}

int Scene::FindClosestFigure()
{
	float distance = 0.f;
	int current = 0;
	for (int i = 0; i < m_Figures.size(); i++)
	{
		float new_distance = (m_RayTracer.GetCamera().GetLocation() - m_Figures[i]->GetOrigin()).GetLength();
		if (new_distance < distance) current = i;
	}
	return current;
}
