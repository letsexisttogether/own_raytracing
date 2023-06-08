#include "../ImageRenderHandlerFabric.hpp"

#include "RenderHandler/ImageRenderHandler.hpp"

ImageRenderHandlerFabric::ImageRenderHandlerFabric(const FabricSelector& fabricSelector, CmdParser& parser)
	: m_FabricsSelector { fabricSelector}, m_Parser{ parser }
{}

ImageRenderHandlerFabric::ImageRenderHandlerFabric(FabricSelector&& fabricSelector, CmdParser&& parser)
	: m_FabricsSelector{ std::move(fabricSelector) }, m_Parser{ std::move(parser) }
{}

RenderHandler* ImageRenderHandlerFabric::GetRenderHandler() noexcept(false)
{
	m_FabricsSelector.FindDlls();

	WriterFabric& writerFabric = m_FabricsSelector.GetWriterFabric(m_Parser.GetGoalFormat());
	writerFabric.LoadDll();

	return new ImageRenderHandler{ writerFabric.GetWriter(m_Parser.GetOutput() + '.' + m_Parser.GetGoalFormat()) };
}
