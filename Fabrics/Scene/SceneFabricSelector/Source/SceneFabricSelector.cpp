#include "../SceneFabricSelector.hpp"

#include <stdexcept>

SceneFabricSelector::SceneFabricSelector(const SceneFabricsMap& sceneFabrics)
	: m_Fabrics{ sceneFabrics }
{}

SceneFabricSelector::SceneFabricSelector(SceneFabricsMap&& sceneFabrics)
	: m_Fabrics{ std::move(sceneFabrics) }
{}

SceneFabric* SceneFabricSelector::GetFabric(const std::string& fabricAssosiation) const noexcept(false)
{
	const auto& iter = m_Fabrics.find(fabricAssosiation);

	if (iter == m_Fabrics.end())
	{
		throw std::invalid_argument{ "There is no any fabrics associated with such a string" };
	}

	return iter->second;
}
