#include "../AABB3.hpp"


AABB3::AABB3() : m_Min(0.f), m_Max(0.f)
{}

AABB3::AABB3(const Vector3d& min, const Vector3d& max) : m_Max(max), m_Min(min)
{}

void AABB3::operator += (const AABB3& box)
{
	m_Min = { std::min(m_Min.GetX(), box.m_Min.GetX()),  std::min(m_Min.GetY(), box.m_Min.GetY()),  std::min(m_Min.GetZ(), box.m_Min.GetZ()) };
	m_Max = { std::max(m_Max.GetX(), box.m_Max.GetX()),  std::max(m_Max.GetY(), box.m_Max.GetY()),  std::max(m_Max.GetZ(), box.m_Max.GetZ()) };
}


bool AABB3::Intersected(const Ray& ray) const
{
	float txmin = (m_Min.GetX() - ray.GetOrigin().GetX()) / ray.GetDirection().GetX();
	float txmax = (m_Max.GetX() - ray.GetOrigin().GetX()) / ray.GetDirection().GetX();
	float xmax = std::max(txmin, txmax);
	float xmin = std::min(txmin, txmax);

	float tymin = (m_Min.GetY() - ray.GetOrigin().GetY()) / ray.GetDirection().GetY();
	float tymax = (m_Max.GetY() - ray.GetOrigin().GetY()) / ray.GetDirection().GetY();
	float ymax = std::max(tymin, tymax);
	float ymin = std::min(tymin, tymax);

	if (xmin > ymax || ymin > xmax) return false;

	xmin = std::min(xmin, ymin);
	xmax = std::max(xmax, ymax);

	float tzmin = (m_Min.GetZ() - ray.GetOrigin().GetZ()) / ray.GetDirection().GetZ();
	float tzmax = (m_Max.GetZ() - ray.GetOrigin().GetZ()) / ray.GetDirection().GetZ();
	float zmax = std::max(tzmin, tzmax);
	float zmin = std::min(tzmin, tzmax);

	if (zmin > xmax || xmin > zmax) return false;

	return true;

}

Vector3d AABB3::GetDividingVector()
{
	Vector3d vec_size = GetSize();
	float biggest = std::max(std::max(vec_size.GetX(), vec_size.GetY()), vec_size.GetZ());
	Vector3d result = { 0.f };
	if (IsNearlyEqual(vec_size.GetX(), biggest)) result = { biggest / 2.f, 0.f, 0.f };
	else if (IsNearlyEqual(vec_size.GetY(), biggest)) result = { 0.f, biggest / 2.f, 0.f };
	else result = { 0.f, 0.f, biggest / 2.f };
	return result;
}


bool AABB3::Contains(const Triangle& triangle)
{
	/*return Contains(triangle.GetV0()) || Contains(triangle.GetV1()) || Contains(triangle.GetV2());*/
	return Contains(triangle.GetCenter());
}


//std::vector<AABB3> AABB3::Divide()
//{
//	auto dividing = GetDividingVector();
//	return { {m_Min, m_Max - dividing}, {m_Min + dividing, m_Max} };
//}


AABB3 AABB3::Divide()
{
	auto dividing = GetDividingVector();
	return {m_Min, m_Max - dividing};
}

bool AABB3::Contains(const Vector3d& point)
{
	return point.GetX() <= m_Max.GetX() && point.GetX() >= m_Min.GetX() && point.GetY() <= m_Max.GetY() && point.GetY() >= m_Min.GetY()
		&& point.GetZ() <= m_Max.GetZ() && point.GetZ() >= m_Min.GetZ();
}