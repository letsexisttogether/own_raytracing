#include "../Sphere.hpp"

Sphere::Sphere(const Vector3d& origin, const float radius)
	: m_Origin{ origin }, m_Radius{ radius }
{}

bool Sphere::IntersectedWithRay(Ray& ray, float* parametr) const
{
	Vector3d original = ray.GetOrigin();
	Vector3d center = this->GetOrigin();
	Vector3d direction = ray.GetDirection();
	float radius = this->GetRadius();

	Vector3d k = original - center;

	float a = direction.Dot(direction);
	float b = 2 * direction.Dot(k);
	float c = k.Dot(k) - radius * radius;

	return (b * b - 4 * a * c) >= 0;
}

