#include "../Sphere.hpp"

Sphere::Sphere(const Point3d& origin, const float radius)
	: m_Origin{ origin }, m_Radius{ radius }
{}

std::optional<Intersection> Sphere::IntersectedWithRay(const Ray& ray, float* parametr) const noexcept
{
	if (!parametr)
	{
		float tempVal = 3.f;
		parametr = &tempVal;
	}

	Vector3d original = ray.GetOrigin();
	Point3d center = this->GetOrigin();
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

	Vector3d point1 = original + direction * (firstIntersecionPoint);
	Vector3d point2 = original + direction * (secondIntersecionPoint);
	
	float distance1 = (point1 - ray.GetOrigin()).GetLength();
	float distance2 = (point2 - ray.GetOrigin()).GetLength();
	
	if (distance1 < distance2)
	{
		return std::optional<Intersection>({ point1, point1 - m_Origin });
	}
	
	return std::optional<Intersection>({ point2, point2 - m_Origin });

}

Vector3d Sphere::GetNormal(Vector3d intersectionPoint) const noexcept
{
	return intersectionPoint - this->m_Origin;
}

