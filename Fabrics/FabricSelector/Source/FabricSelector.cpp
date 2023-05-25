#include "../FabricSelector.hpp"

#include <stdexcept>

FabricSelector::FabricSelector(const std::filesystem::path& pluginsPath)
	: m_PluginsPath{ pluginsPath }
{}

FabricSelector::~FabricSelector()
{
    for (auto& [format, fabric] : m_Readers)
    {
        delete fabric;
    }

    for (auto& [format, fabric] : m_Writers)
    {
        delete fabric;
    }
}

void FabricSelector::FindDlls() noexcept
{
    for (const auto& entry : std::filesystem::directory_iterator(m_PluginsPath))
    {
        const std::filesystem::path& dllPath = entry.path();
        const std::string& dllName = dllPath.stem().string();

        if (dllPath.extension() != ".dll")
        {
            continue;
        }

        auto makePath = [&]()
        {
            const std::size_t len = 7;

            std::string format = dllName.substr(len);
            std::transform(format.begin(), format.end(), format.begin(),
                [](unsigned char c) { return std::tolower(c); });

            return std::pair<std::string, std::string>{ format, m_PluginsPath.string() + '/' + dllName + ".dll" };
        };

        if (const std::size_t pos = dllName.find("Reader."); !pos)
        {
            const auto outPair = makePath();

            m_Readers[outPair.first] = new ReaderFabric(outPair.second);
        }
        else if (const std::size_t pos = dllName.find("Writer."); !pos)
        {
            const auto outPair = makePath();

            m_Writers[outPair.first] = new WriterFabric(outPair.second);
        }
    }
}

ReaderFabric& FabricSelector::GetReaderFabric(const std::string& format) const noexcept(false)
{
    auto iter = m_Readers.find(format);

    if (iter == m_Readers.end())
    {
        throw std::runtime_error{ "The program does not support reading of such a format. Follow the updates" };
    }

    return *iter->second;
}

WriterFabric& FabricSelector::GetWriterFabric(const std::string& format) const noexcept(false)
{
    auto iter = m_Writers.find(format);

    if (iter == m_Writers.end())
    {
        throw std::runtime_error{ "The program does not support writing of such a format. Follow the updates" };
    }

    return *iter->second;
}