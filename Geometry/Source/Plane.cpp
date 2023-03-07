#include "../Plane.hpp"



Plane::Plane(const Vector3d& origin, const Vector3d& normal)
	: m_Origin{ origin }, m_Normal{ normal }
{}