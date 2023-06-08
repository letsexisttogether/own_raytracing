#pragma once

#include "../Base/ReaderFabric.hpp"
#include "../Base/WriterFabric.hpp"

#include <unordered_map>

class FabricSelector
{
public:
	FabricSelector(const std::filesystem::path& pluginsPath);

	~FabricSelector();

	void FindDlls() noexcept;

	ReaderFabric& GetReaderFabric(const std::string& format) const noexcept(false);
	WriterFabric& GetWriterFabric(const std::string& format) const noexcept(false);

private: 
	const std::filesystem::path m_PluginsPath;

	std::unordered_map<std::string, ReaderFabric*> m_Readers;
	std::unordered_map<std::string, WriterFabric*> m_Writers;
};