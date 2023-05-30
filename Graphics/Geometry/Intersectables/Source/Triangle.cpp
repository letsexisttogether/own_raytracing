#include "../Triangle.hpp"

Triangle::Triangle(const Point3d& v0, const Point3d& v1, const Point3d& v2)
	: m_V0{ v0 }, m_V1(v1), m_V2(v2)
{}

std::optional<Intersection> Triangle::IntersectedWithRay(const Ray & ray, float* parametr) const noexcept
{
	return std::nullopt;
}
