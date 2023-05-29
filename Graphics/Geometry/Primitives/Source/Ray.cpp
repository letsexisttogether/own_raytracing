#include "../Ray.hpp"

Ray::Ray(const Point3d& origin, const Vector3d& direction)
	: m_Origin{ origin }, m_Direction{ direction }
{}
