#include "../SceneSelector.hpp"

#include <stdexcept>

SceneSelector::SceneSelector(const std::string& sceneName, const ScenesMap& scenePrototypes)
	: m_SceneName{ sceneName }, m_Scenes{ scenePrototypes }
{}

SceneSelector::SceneSelector(std::string&& sceneName, ScenesMap&& scenePrototypes)
	: m_SceneName{ std::move(sceneName) }, m_Scenes{ std::move(scenePrototypes) }
{}

const Scene& SceneSelector::GetScene() noexcept(false)
{
	const auto& iter = m_Scenes.find(m_SceneName);

	if (iter == m_Scenes.end())
	{
		throw std::invalid_argument{ "There is no any scene with such a name" };
	}

	return iter->second->GetScene();
}
