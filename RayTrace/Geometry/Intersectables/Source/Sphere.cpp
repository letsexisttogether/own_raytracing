#include "../Sphere.hpp"

Sphere::Sphere(const Vector3d& origin, const float radius)
	: m_Origin{ origin }, m_Radius{ radius }
{}

std::optional<Vector3d> Sphere::IntersectedWithRay(const Ray& ray, float* parametr) const noexcept
{
	Vector3d original = ray.GetOrigin();
	Vector3d center = this->GetOrigin();
	Vector3d direction = ray.GetDirection();
	float radius = this->GetRadius();

	Vector3d k = original - center;

	float a = direction.Dot(direction);
	float b = 2 * direction.Dot(k);
	float c = k.Dot(k) - radius * radius;
	
	const float discriminant = b * b - 4 * a * c;

	if (discriminant < 0)
	{
		return std::nullopt;
	}
	
	float firstIntersecionPoint = (-b + sqrtf(discriminant)) / (2.f * a);
	float secondIntersecionPoint = (-b - sqrtf(discriminant)) / (2.f * a);

	return { std::min(firstIntersecionPoint, secondIntersecionPoint) };
}

Vector3d Sphere::GetNormal(Vector3d intersectionPoint) const noexcept
{
	return intersectionPoint - this->m_Origin;
}

