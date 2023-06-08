#pragma once

#include "RenderHandlerFabric.hpp"
#include "Fabrics/FabricSelector/FabricSelector.hpp"
#include "Render/Screen.h"
#include "CmdParser/CmdParser.hpp"

class ImageRenderHandlerFabric : public RenderHandlerFabric
{
public:
	ImageRenderHandlerFabric(const FabricSelector& fabricSelector, CmdParser& parser);
	ImageRenderHandlerFabric(FabricSelector&& fabricSelector, CmdParser&& parser);

	~ImageRenderHandlerFabric() = default;

	RenderHandler* GetRenderHandler() noexcept(false) override;

private:
	FabricSelector m_FabricsSelector;
	CmdParser& m_Parser;
};