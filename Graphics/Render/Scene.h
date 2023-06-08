#pragma once

#include <vector>

#include "Screen.h"
#include "Geometry/Intersectables/Intersectable.h"
#include "Light/Light.hpp"

class Scene
{
public:
	Scene() = delete;
	Scene(const Scene&) = default;
	Scene(Scene&& scene) noexcept;

	Scene(const Screen& screen, std::vector<Light*>&& lights);

	~Scene();

	void AddToScene(Intersectable* figure);
	void AddToScene(const std::vector<Intersectable*>& figures);

	std::optional<Intersection> FindClosestIntersection(const Ray& ray) const noexcept;
	bool CheckAnyIntersection(const Ray& ray, const Intersection& intersection) const noexcept;

	inline const Screen& GetScreen() const noexcept { return m_Screen; }
	inline const std::vector<Light*>& GetLights() const noexcept { return m_Lights; }

private:
	Screen m_Screen;
	std::vector<Light*> m_Lights;
	std::vector<Intersectable*> m_Figures;
};