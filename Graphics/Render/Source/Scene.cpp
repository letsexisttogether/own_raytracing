#include "../Scene.h"

#include <iostream>

Scene::Scene(const RayTracer& tracer) 
	: m_RayTracer{ tracer } 
{}

Scene::~Scene()
{
	for (auto& ptr : m_Figures)
	{
		delete ptr;
	}
}

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

void Scene::AddToScene(const std::vector<Intersectable*>& figures)
{
	for (const auto figure : figures)
	{
		AddToScene(figure);
	}
}

