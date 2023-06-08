#pragma once 

#include <unordered_map>

#include "SceneFabric.hpp"

class SceneSelector : public SceneFabric
{
public:
	using ScenesMap = std::unordered_map<std::string, SceneFabric*>;

public:
	SceneSelector(const std::string& sceneName, const ScenesMap& scenePrototypes);
	SceneSelector(std::string&& sceneName, ScenesMap&& scenePrototypes);

	~SceneSelector() = default;

	virtual const Scene& GetScene() noexcept(false) override;

private:
	const std::string m_SceneName;
	ScenesMap m_Scenes;
};