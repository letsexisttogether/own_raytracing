#include "../Scene.h"

#include <iostream>

Scene::Scene(Scene&& scene)
	: m_Screen{ std::move(m_Screen) },
		m_Lights{ std::move(scene.m_Lights) }, m_Figures{ std::move(scene.m_Figures) }
{}

Scene::Scene(const Screen& screen, std::vector<Light*>&& lights)
	: m_Screen{ screen }, m_Lights{ std::move(lights) }
{}

Scene::~Scene()
{
	for (auto& ptr : m_Figures)
	{
		delete ptr;
	}

	for (auto& ptr : m_Lights)
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

bool Scene::CheckAnyIntersection(const Ray& ray, const Intersection& intersection) const noexcept
{
	for (auto figure : m_Figures)
	{
		if (auto new_intersection = figure->IntersectedWithRay(ray))
		{
			if ((new_intersection.value().IntersectionPoint - intersection.IntersectionPoint).GetLength() > 0.001)
			{
				return true;
			}
		}
	}

	return false;
}


