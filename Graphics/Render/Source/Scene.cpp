#include "../Scene.h"

#include <iostream>

Scene::Scene(const Camera& camera, const Vector3d& lightVector)
	: m_Camera{ camera }, m_LightVector{ lightVector }
{}

Scene::~Scene()
{
	for (auto& ptr : m_Figures)
	{
		delete ptr;
	}
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

std::optional<Intersection> Scene::FindClosestIntersection(const Ray& ray) const noexcept
{
	float length = 99999.f;
	std::optional<Intersection> result = std::nullopt;
	for (auto figure : m_Figures)
	{
		std::optional<Intersection> temp = figure->IntersectedWithRay(ray);
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

bool Scene::CheckAnyIntersection(const Intersection& intersection) const noexcept
{
	const Ray rayToLight{ intersection.IntersectionPoint, m_LightVector};

	for (auto figure : m_Figures)
	{
		if (auto new_intersection = figure->IntersectedWithRay(rayToLight))
		{
			if ((new_intersection.value().IntersectionPoint - intersection.IntersectionPoint).GetLength() > 0.001)
			{
				return true;
			}
		}
	}

	return false;
}



