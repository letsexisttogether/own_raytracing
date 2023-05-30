#pragma once

#include <vector>

#include "Camera.h"
#include "Geometry/Intersectables/Intersectable.h"

class Scene
{
public:
	Scene() = delete;
	Scene(const Camera& camera, const Vector3d& lightVector);

	~Scene();

	void AddToScene(Intersectable* figure);
	void AddToScene(const std::vector<Intersectable*>& figures);

	std::optional<Intersection> FindClosestIntersection(const Ray& ray) const noexcept;
	bool CheckAnyIntersection(const Intersection& intersection) const noexcept;

	inline const Camera& GetCamera() const noexcept { return m_Camera; }
	inline const Vector3d& GetLightVector() const noexcept { return m_LightVector; }

private:
	const Camera& m_Camera;
	const Vector3d& m_LightVector;
	std::vector<Intersectable*> m_Figures;
};