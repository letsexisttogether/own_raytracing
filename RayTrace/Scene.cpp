#include "Scene.h"
#include <iostream>

Scene::Scene(RayTracer& tracer) : m_RayTracer(tracer) {}

std::optional<Intersection> Scene::IntersectedWithRay(const Ray& ray, float* parametr) const noexcept
{
	float length = 99999.f;
	std::optional<Intersection> result = std::nullopt;
	for (auto f : m_Figures)
	{
		std::optional<Intersection> temp = f->IntersectedWithRay(ray, parametr);
		if (temp.has_value())
		{
			Vector3d distance = temp.value().IntersectionPoint - ray.GetOrigin();
			if (distance.GetLength() < length)
			{
				length = distance.GetLength();
				result = temp;
			}
		}
	}
	return result;
}

void Scene::AddToScene(Intersectable* figure)
{
	m_Figures.push_back(figure);
}

//void Scene::Trace()
//{
//	m_RayTracer.Tracing(*m_Figures[FindClosestFigure()]);
//}
//
//void Scene::PrintScreen()
//{
//	m_RayTracer.GetScreen().Print();
//}
//
//int Scene::FindClosestFigure()
//{
//	float length = 99999.f;
//	int current = 0;
//	for (int i = 0; i < m_Figures.size(); i++)
//	{
//		/*float new_distance = (m_RayTracer.GetCamera().GetLocation() - m_Figures[i]->GetOrigin()).GetLength();
//		if (new_distance < distance) current = i;*/
//		std::optional<Vector3d> result = m_RayTracer.Tracing(*m_Figures[i]);
//		float new_length;
//		if (result.has_value()) new_length = result.value().GetLength();
//		else new_length = 99999.f;
//		std::cout << new_length << std::endl;
//		if (new_length < length)
//		{
//			current = i;
//			length = new_length;
//		}
//	}
//	return current;
//}
