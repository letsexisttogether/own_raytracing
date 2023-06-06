#include "../BVH.hpp"
#include <iostream>



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

	//std::cout << first.size() << " " << second.size() << std::endl;
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
bool BVHTree::Intersected(const Ray& ray) const { return m_Box.Intersected(ray); }

std::optional<Intersection> BVHTree::IntersectedWithRay(const Ray& ray, float* parametr) const noexcept 
{
	if(!m_Box.Intersected(ray)) return std::nullopt;
	std::optional<Intersection> res = std::nullopt;
	std::optional<Intersection> temp = std::nullopt;
	int k = 0;
	for (auto& child : m_Children)
	{
		/*if (child->Intersected(ray))
		{
			res = child->IntersectedWithRay(ray);
			if (res.has_value()) return res;
		}	*/	
		temp = child->IntersectedWithRay(ray);
		if (temp.has_value())
		{				
			if (!res.has_value() || temp.value().Distance < res.value().Distance) res = temp;
		}		
	}
	return res;
}


BVHLeaf::BVHLeaf(std::vector<Triangle>&& triangles) : m_Triangles(std::move(triangles)) {
	for (auto& triangle : m_Triangles)
		m_Scene.AddToScene(new Triangle(triangle));

	/*counter += m_Triangles.size();
	std::cout << counter << std::endl;*/
	if (m_Triangles.size() > 0)
	{
		m_Box = m_Triangles.front().BuildBox();
		for (auto& triangle : m_Triangles)
			m_Box += triangle.BuildBox();
	}
}

bool BVHLeaf::Intersected(const Ray& ray) const { return m_Box.Intersected(ray); }

std::optional<Intersection> BVHLeaf::IntersectedWithRay(const Ray& ray, float* parametr) const noexcept 
{
	return m_Scene.FindClosestIntersection(ray);
}