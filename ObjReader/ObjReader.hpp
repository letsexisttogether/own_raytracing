#pragma once

#include <vector>
#include <cstddef>
#include <sstream>

#include "Geometry/Intersectables/Triangle.hpp"

class ObjReader
{
public:
	ObjReader() = default;

	~ObjReader() = default;

	std::vector<Intersectable*>& Read(const std::vector<std::byte>& bytes) noexcept(false);

private:
	void Parse(std::istringstream& lineStream) noexcept(false);
	
	void ExtractVertices(std::istringstream& lineStream) noexcept(false);
	void ExtractIndices(std::istringstream& lineStream) noexcept(false);

private:
	std::vector<Point3d> m_Vertices;
	std::vector<Intersectable*> m_Intersectables;
};