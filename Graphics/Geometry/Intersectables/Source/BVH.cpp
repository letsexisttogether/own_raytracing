#include "../BVH.hpp"

BVHTree::BVHTree(std::vector<Triangle>&& triangles, int depth) : m_Triangles(std::move(triangles))
{
	m_Box = m_Triangles.front().BuildBox();
	for (auto& triangle : m_Triangles)
		m_Box += triangle.BuildBox();

	auto new_boxes = m_Box.Divide();
	std::vector<Triangle> first;
	std::vector<Triangle> second;
	for (auto& triangle : m_Triangles)
	{
		if (new_boxes.Contains(triangle)) first.push_back(triangle);
		else second.push_back(triangle);
	}

	m_Triangles.clear();

	if (first.size() > 10 && depth <= 10)
	{
		m_Children.push_back(new BVHTree(std::move(first), depth + 1));
	}
	else if(first.size() != 0) m_Children.push_back(new BVHLeaf(std::move(first)));

	if (second.size() > 10 && depth <= 10)
	{
		m_Children.push_back(new BVHTree(std::move(second), depth + 1));
	}
	else if (second.size() != 0) m_Children.push_back(new BVHLeaf(std::move(second)));
}


std::optional<Intersection> BVHTree::IntersectedWithRay(const Ray& ray, float* parametr) const noexcept 
{
	std::optional<Intersection> res = std::nullopt;
	std::optional<Intersection> temp = std::nullopt;

	for (auto& child : m_Children)
	{
		if (child->Intersected(ray))
		{
			temp = child->IntersectedWithRay(ray);
			if (temp.has_value() && (!res.has_value() || temp.value().Distance < res.value().Distance))
			{
				res = temp;
			}
		}		
	}
	return res;
}

bool BVHTree::Intersected(const Ray& ray) const { return m_Box.Intersected(ray); }



BVHLeaf::BVHLeaf(std::vector<Triangle>&& triangles) : m_Triangles(std::move(triangles)) 
{
	if (!m_Triangles.empty())
	{
		m_Box = m_Triangles.front().BuildBox();
		for (auto& triangle : m_Triangles)
		{
			m_Box += triangle.BuildBox();
		}
	}
}

std::optional<Intersection> BVHLeaf::IntersectedWithRay(const Ray& ray, float* parametr) const noexcept 
{
	float length = 99999.f;
	std::optional<Intersection> result = std::nullopt;
	for (const auto& figure : m_Triangles)
	{
		std::optional<Intersection> temp = figure.IntersectedWithRay(ray);
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

bool BVHLeaf::Intersected(const Ray& ray) const { return m_Box.Intersected(ray); }