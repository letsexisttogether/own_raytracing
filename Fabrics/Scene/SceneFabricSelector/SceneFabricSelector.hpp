#pragma once

#include "../Base/SceneLoader.hpp"
#include "../Base/SceneSelector.hpp"

class SceneFabricSelector
{
public:
	using SceneFabricsPair = std::pair<std::string, SceneFabric*>;
	using SceneFabricsMap = std::unordered_map<std::string, SceneFabric*>;

public: 
	SceneFabricSelector(const SceneFabricsMap& sceneFabrics);
	SceneFabricSelector(SceneFabricsMap&& sceneFabrics);

	SceneFabric* GetFabric(const std::string& fabricAssosiation) const noexcept(false);

	~SceneFabricSelector() = default;

private:
	const SceneFabricsMap m_Fabrics;
};