#include "Geometry/Sphere.hpp"
#include "Geometry/Ray.hpp"

class IntersectedWithSphere
{
public:
	// Алгоритм, що був представлений на парі
	bool IntersectedWithRay(const Sphere& sphere, const Ray& ray)
	{
		Vector3d original = ray.GetOrigin();
		Vector3d center = sphere.GetOrigin();
		Vector3d direction = ray.GetDirection();
		float radius = sphere.GetRadius();

		Vector3d k = original - center;

		float a = direction.Dot(direction);
		float b = 2 * direction.Dot(k);
		float c = k.Dot(k) - radius * radius;

		return (b * b - 4 * a * c) >= 0;
	}
};
