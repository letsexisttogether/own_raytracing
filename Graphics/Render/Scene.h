#pragma once

#include <vector>

#include "Camera.h"
#include "Geometry/Intersectables/Intersectable.h"
#include "Light/Light.hpp"

class Scene
{
public:
	Scene() = delete;
	Scene(const Camera& camera, const std::vector<Light*>& lights);

	~Scene();

	void AddToScene(Intersectable* figure);
	void AddToScene(const std::vector<Intersectable*>& figures);

	std::optional<Intersection> FindClosestIntersection(const Ray& ray) const noexcept;
	// bool CheckAnyIntersection(const Intersection& intersection) const noexcept;

	inline const Camera& GetCamera() const noexcept { return m_Camera; }
	inline const std::vector<Light*>& GetLights() const noexcept { return m_Lights; }

private:
	const Camera& m_Camera;
	std::vector<Light*> m_Lights;
	std::vector<Intersectable*> m_Figures;
};